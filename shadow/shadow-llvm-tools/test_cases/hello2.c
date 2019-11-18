#include <stdio.h>


void foo();
void bar();

int main() {

  printf("Hello world!\n");

  int i = 0;
  i++;
  if (i > 0) {
    printf("%d\n",i);
  }
  else {
    if (i == 0) {
      printf("%d\n",i);
    }
  }

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

