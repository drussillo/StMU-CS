#include <stdio.h>

int* test_function(void) {
  int array[3] = {10, 29, 35};
  int* pointer = array;

  return pointer;
}

int main(void) {
  printf("%d \n", test_function()[2]);

  return 0;
}
