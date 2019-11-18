#!/bin/sh

# A script that instruments a c program with instructions that print outcomes from 
# conditional branch instructions
# Input: .c file with main function
# Output: instrumented native executable

LLVM_GCC=`which llvm-gcc`
if [ "x$LLVM_GCC" = "x" ]; then
  echo "llvm-gcc not found in your PATH"
  exit 1
fi

LLVM_LINK=`which llvm-link`
if [ "x$LLVM_LINK" = "x" ]; then
  echo "llvm-link not found in your PATH"
  exit 1
fi

LLC=`which llc`
if [ "x$LLC" = "x" ]; then
  echo "llc not found in your PATH"
  exit 1
fi


if [ $# -ne 1 ]; 
    then echo "Usage: " $0 " <file.c>"; exit 1
fi

C_FILE=$1

if [ ! -f "$C_FILE" ]; then
  echo "Input C file not found"
  exit 1
fi

DIR_NAME=`dirname $C_FILE`
C_FILE_NAME=`basename $C_FILE`
FILE_NAME=${C_FILE_NAME%.*}
FILE_NAME_PREFIX=${C_FILE%.*}


llvm-gcc -DRESOLVE_KLEE_CHANGE=-1 --emit-llvm -g -c -I./include -o $FILE_NAME_PREFIX.bc $FILE_NAME_PREFIX.c
llvm-link $FILE_NAME_PREFIX.bc ./lib/branch-recorder/Instrumentation/Instrumentation.bc -o $FILE_NAME_PREFIX.i1.bc
opt -load ./Release+Asserts/lib/branch-recorder.so -break-crit-edges -branch-record $FILE_NAME_PREFIX.i1.bc > $FILE_NAME_PREFIX.i2.bc
llc $FILE_NAME_PREFIX.i2.bc
g++ $FILE_NAME_PREFIX.i2.s -o $FILE_NAME_PREFIX

# To be removed. Temporarily used for debugging purposes.
llvm-dis $FILE_NAME_PREFIX.i2.bc
