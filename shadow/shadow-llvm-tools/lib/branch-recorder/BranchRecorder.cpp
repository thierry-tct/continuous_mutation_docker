// Statistics.
// This goes before any #includes.
#define DEBUG_TYPE ""

#include "llvm/Pass.h"
#include "llvm/Function.h"
#include "llvm/Instruction.h"
#include "llvm/Constants.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/Analysis/DebugInfo.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/InstVisitor.h"
#include "llvm/Support/CommandLine.h"
using namespace llvm;

#include "Bijection.h"
#include "PatchSummary.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>



STATISTIC(BranchCounter, "Counts number of branches encountered");

static cl::opt<bool>
InstInfo("inst-info", cl::desc("Dump debug info about instructions"));

static cl::opt<std::string>
OutputFile("output-file",
           cl::init("branch-dump.log"),
           cl::desc("Output filename"));

static cl::opt<std::string>
PatchFile("patch-file",          
          cl::desc("Patch filename"));



namespace {

  std::string getDSPIPath(DILocation Loc) {
    std::string dir = Loc.getDirectory();
    std::string file = Loc.getFilename();

    if (dir.empty() || file[0] == '/') {
      return file;
    } else if (*dir.rbegin() == '/') {
      return dir + file;
    } else {
      return dir + "/" + file;
    }
  }

  bool getInstructionDebugInfo(const llvm::Instruction& I,
                               std::string& File,
                               unsigned& Line) {
    if (MDNode* N = I.getMetadata("dbg")) {
      DILocation Loc(N);
      File = getDSPIPath(Loc);
      Line = Loc.getLineNumber();
      return true;
    }
    return false;
  }
  
  void dumpInstructionDebugInfo(const llvm::Instruction& I) {
    std::string file;
    unsigned line;

    if (getInstructionDebugInfo(I, file, line)) {
      errs() << "-- instruction " << I.getOpcodeName() << " (" << file
             << "@" << line << ")\n";
      I.dump();
    }
  }

  class BranchRecorder : public ModulePass, public InstVisitor<BranchRecorder> {
  public:
    static char ID; // Pass identification, replacement for typeid
    BranchRecorder() : ModulePass(ID) {};
    virtual ~BranchRecorder() {};

    virtual bool runOnModule(Module &M);
    virtual void getAnalysisUsage(AnalysisUsage &AU) const;

    void visitTerminatorInst(TerminatorInst &TI);
    
  private:
    std::string _output_filename;
    std::string _patch_filename;
    PatchSummary _patch_summary;
    
    std::map<unsigned, unsigned>      _line_branch_cnts;
    Bijection<BranchInst*, unsigned>  _branch_bimap;
    std::map<std::string, Constant*>  _string_cache;
    
    Constant* getGlobalLLVMCStr(Module& M, const std::string& str);
    void insertRecordingInitCall(Function *Main,
                                 Function* InitFunction,
                                 const std::string& OutFilename);
    
    bool parsePatch();
  };
}


char BranchRecorder::ID = 0;
static RegisterPass<BranchRecorder> X("branch-record", "Instrumentation pass for recording the branch taken at each conditional branch instruction");

void BranchRecorder::getAnalysisUsage(AnalysisUsage &AU) const {
  // http://llvm.org/pubs/2010-12-Preuss-PathProfiling.pdf
  AU.addRequiredID(BreakCriticalEdgesID);
}

bool BranchRecorder::runOnModule(Module &M) {
  
  _output_filename = OutputFile;
  _patch_filename = PatchFile;
  
  parsePatch();
  
  Function *Main = M.getFunction("main");
  if (Main == 0) {
    errs() << "WARNING: cannot insert branch recording into a module"
           << " with no main function!\n";
    return false;
  }

  Function* fRecord = M.getFunction("recordBranch");
  if (fRecord == 0) {
    errs() << "WARNING: no recordBranch() function!\n";
    return false;
  }
  
  Function* fStartRecording = M.getFunction("startBranchRecording");
  if (fStartRecording == 0) {
    errs() << "WARNING: no startBranchRecording() function!\n";
    return false;
  }
  
  Function* fRecordInOutputFile = M.getFunction("recordBranchInOutputFile");
  if (fRecordInOutputFile == 0) {
    errs() << "WARNING: no recordBranchInOutputFile() function!\n";
    return false;
  }
  
  static unsigned branchCnt = 0;
  
  for (Module::iterator f = M.begin(), fe = M.end(); f != fe; ++f) {
    if (f->isDeclaration())
      continue;

    for (Function::iterator bb = f->begin(), bbe = f->end(); bb != bbe; ++bb) {
      BranchInst *branchI = dyn_cast<BranchInst>(bb->getTerminator());
      if (branchI && branchI->isConditional()) {

        std::string file;
        unsigned line;
        if (getInstructionDebugInfo(*branchI, file, line)) {
  
          _branch_bimap.add(branchI, branchCnt++);
  
          std::map<unsigned, unsigned>::iterator it = _line_branch_cnts.find(line);
          unsigned lineBranchCnt = (it != _line_branch_cnts.end()) ? it->second : 0;
          _line_branch_cnts[line] = lineBranchCnt + 1;
  
          Value* argFile = getGlobalLLVMCStr(M, file);
          Value* argLine = ConstantInt::get(Type::getInt32Ty(M.getContext()), line, false);
          Value* argBranchID = ConstantInt::get(Type::getInt32Ty(M.getContext()),
                                                lineBranchCnt, // _branch_bimap.get_second(branchI),
                                                false);
  

          for (unsigned i = 0; i != branchI->getNumSuccessors(); ++i) {
            BasicBlock *succ = branchI->getSuccessor(i);
            assert(succ);

            Value* argBranchDest = ConstantInt::get(Type::getInt32Ty(M.getContext()), i, false);
            Value *CallArgs[] = {argFile, argLine, argBranchID, argBranchDest};

            CallInst *BranchRecordCall = CallInst::Create(fRecordInOutputFile,
                                                          CallArgs,
                                                          CallArgs + 4,
                                                          "",
                                                          succ->getFirstNonPHI());
          }
        }
      }
    }
  }
  
  insertRecordingInitCall(Main, fStartRecording, _output_filename);
  
  return false;
}

void BranchRecorder::visitTerminatorInst(TerminatorInst &TI) {
  dumpInstructionDebugInfo(TI);
}

Constant* BranchRecorder::getGlobalLLVMCStr(Module& M, const std::string& str) {
  
  Constant* res = NULL;
  
  if (_string_cache.count(str)) {
    res = _string_cache[str];
  }
  else {
    GlobalVariable* llvm_str = new GlobalVariable(M,
          ArrayType::get(Type::getInt8Ty(M.getContext()), str.size() + 1),
          true,
          GlobalValue::InternalLinkage,
          ConstantArray::get(M.getContext(), StringRef(str), true),
          str);

    Constant *zero_32 = Constant::getNullValue(IntegerType::getInt32Ty(M.getContext()));
    Constant *gep_params[] = {
        zero_32,
        zero_32
    };
    Constant *llvm_str_ptr = ConstantExpr::getGetElementPtr(llvm_str, gep_params, array_lengthof(gep_params));

    _string_cache[str] = llvm_str_ptr;
    res = llvm_str_ptr;
  }

  assert(res);
  return res;
}

void BranchRecorder::insertRecordingInitCall(Function *Main,
                                             Function* InitFunction,
                                             const std::string& OutFilename) {

  assert(Main && InitFunction);

  // To loocate the position to insert init recording call,
  // skip over any allocas in the entry block
  BasicBlock *Entry = Main->begin();
  BasicBlock::iterator InsertPos = Entry->begin();
  while (isa<AllocaInst>(InsertPos)) ++InsertPos;
  
  Value* argOutFilename = getGlobalLLVMCStr(*Main->getParent(), OutFilename);
  Value *CallArgs[] = {argOutFilename};
  
  CallInst *BranchRecordCall = CallInst::Create(InitFunction,
                                                CallArgs,
                                                CallArgs + 1,
                                                "",
                                                InsertPos);
  
}

bool BranchRecorder::parsePatch() {

  std::ifstream ifs;
  ifs.open(_patch_filename.c_str()); // open a file
  if (!ifs.good()) {
    return false;
  }
    
  while (!ifs.eof()) {
    std::string file_name, line_numbers;
    std::getline(ifs, file_name);
    if (file_name.empty()) {
      continue;
    }
    getline(ifs, line_numbers);
    assert(!line_numbers.empty());    
    
    // errs() << "Parsing patch file " << file_name << ", " << line_numbers << "\n";
    
    std::stringstream iss(line_numbers);
    std::set<unsigned> changed_lines;
    std::string line;
    
    while (std::getline(iss, line, ' ')) {
      // errs() << line << "\n";
      changed_lines.insert(atoi(line.c_str()));
    }    
    
    _patch_summary.addFile(file_name, changed_lines);
  }
  
  return true;
  
}
