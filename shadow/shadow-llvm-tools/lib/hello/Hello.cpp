//===- Hello.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements two versions of the LLVM "Hello World" pass described
// in docs/WritingAnLLVMPass.html
//
//===----------------------------------------------------------------------===//


// Statistics.
// This goes before any #includes.
#define DEBUG_TYPE ""

#include "llvm/Pass.h"
#include "llvm/Function.h"
#include "llvm/Instruction.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Analysis/DebugInfo.h"
#include "llvm/Support/InstVisitor.h"
#include "llvm/Support/CommandLine.h"
using namespace llvm;

#include <iostream>

STATISTIC(FunctionCounter, "Counts number of functions");
STATISTIC(BBCounter, "Counts number of basic blocks");
STATISTIC(InstCounter, "Counts number of instructions");

static cl::opt<bool>
InstInfo("inst-info", cl::desc("Dump debug info about instructions"));


namespace {

  class StatsCount : public FunctionPass, public InstVisitor<StatsCount> {

    llvm::Module* _curr_module;

    unsigned int _num_functions;
    unsigned int _num_bb;
    unsigned int _num_instructions;

  public:
    static char ID; // Pass identification, replacement for typeid
    StatsCount();

    virtual bool doInitialization(Module& module);
    virtual bool runOnFunction(Function &F);
    virtual bool doFinalization(Module& module);

    void processBasicBlock(const BasicBlock& bb);
    void processInstruction(const Instruction& instruction);

    // We don't modify the program, so we preserve all analyses
    virtual void getAnalysisUsage(AnalysisUsage &AU) const {
        AU.setPreservesAll();
    }

	inline unsigned int get_num_functions() const { return(_num_functions); };
	inline unsigned int get_num_bb() const { return(_num_bb); };
	inline unsigned int get_num_instructions() const { return(_num_instructions); };
  };
}

char StatsCount::ID = 0;
static RegisterPass<StatsCount> X("hello", "Function + BB + Instruction Counting Pass");


StatsCount::StatsCount() :
FunctionPass(ID),
_curr_module(NULL),
_num_functions(0),
_num_bb(0),
_num_instructions(0)
{
}

bool StatsCount::doInitialization(Module& module) {
	_curr_module = &module;
	assert(_curr_module);
	errs() << "\nModule (identifier="<< _curr_module->getModuleIdentifier() << ")\n";
	return(true);
}

bool StatsCount::doFinalization(Module& module) {
	return(true);
}

bool StatsCount::runOnFunction(Function &F) {
    ++FunctionCounter;
    ++_num_functions;

    errs() << "\nFunction: ";
    errs().write_escaped(F.getName());
    errs() << ", " << F.size() << " basic blocks\n";

    // F.viewCFG();

    const Function::BasicBlockListType& bb_list = F.getBasicBlockList();

    //for (Function::iterator it = F.begin(); it != F.end(); ++it) {
    for (Function::BasicBlockListType::const_iterator it = bb_list.begin(); it != bb_list.end(); ++it) {
   	    ++BBCounter;
   	    ++_num_bb;

   	    const BasicBlock &bb = *it;
   	    std::cerr << "Basic block (name=" << bb.getNameStr() << ") has " << bb.size() << " instructions.\n";

   	    const BasicBlock::InstListType& instructions = bb.getInstList();
   	    for (BasicBlock::InstListType::const_iterator iit = instructions.begin(); iit != instructions.end(); ++iit) {
   		    ++InstCounter;
   		    ++_num_instructions;

  		    const Instruction& instruction = *iit;

   		    if (const CallInst* call_instruction = dyn_cast<CallInst>(&instruction)) {
				const Function* called_function = call_instruction->getCalledFunction();
				if (called_function) {
					// This gets hold of printf, puts, etc, but not functions defined in the module ...
					errs() << "calling function " << called_function->getName() << "\n\n";
				}
   		    }

   		    if (InstInfo) {

				if (MDNode* debug_info = instruction.getMetadata("dbg")) {
					DILocation location(debug_info);
					errs() << "-- instruction " << instruction.getOpcodeName() << " (" << location.getFilename()
						   << "@" << location.getLineNumber() << ")\n";
					instruction.dump();
				}
   		    }
   	    }
    }

    // return value = (function is modified) ? true : false;
    return false;
}


