
extern "C"
void recordBranch(const char* const file, unsigned line, unsigned branchID, unsigned branchDest);


extern "C"
void recordBranchInOutputFile(const char* const file, unsigned line, unsigned branchID, unsigned branchDest);


extern "C"
void startBranchRecording(const char* const out_file);
