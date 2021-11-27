#include <stdio.h>

#include "klee_change_macros.h"

void foo();
void bar();

int main() {

  printf("Hello world!\n");

  int i =0;
  i++;
  if (i != 0) {
    printf("%d\n",i);
  }
  
  printf("RESOLVE_KLEE_CHANGE is now %d\n", RESOLVE_KLEE_CHANGE);
  
  i = klee_change(i+7,i+1);
  printf("Value of i after klee_change is %d\n",i);

  foo();
  bar();
  foo();

  return 0;
}

void foo() {
  bar();
}

void bar() {
  printf("In bar ... \n");
}

