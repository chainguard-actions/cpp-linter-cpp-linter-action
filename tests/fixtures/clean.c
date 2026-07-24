// A simple, clean C file for linting tests
#include <stdio.h>

int add(int a, int b) { return a + b; }

int main(void) {
  int result = add(1, 2);
  printf("Result: %d\n", result);
  return 0;
}
