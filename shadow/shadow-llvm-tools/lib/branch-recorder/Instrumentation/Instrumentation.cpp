#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "Instrumentation.h"


namespace {
  FILE *fd_output;

  void finishBranchRecording() {
    if (fd_output) {
      fclose(fd_output);
    }
  }
}

extern "C"
void recordBranch(const char* const file, unsigned line, unsigned branchID, unsigned branchDest) {
  printf("%s\t%u\t%u\t%u\n", file, line, branchID, branchDest);
}

extern "C"
void recordBranchInOutputFile(const char* const file, unsigned line, unsigned branchID, unsigned branchDest) {
  if (fd_output) {
    fprintf(fd_output, "%s\t%u\t%u\t%u\n", file, line, branchID, branchDest);
  }
}

extern "C"
void startBranchRecording(const char* const out_file) {
  fd_output = fopen(out_file, "a");
  atexit(finishBranchRecording);
}



