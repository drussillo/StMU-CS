/* C program by Dave Russillo. Made on 04/01/2025 for CS1311. Macro and define test. */
#include <stdio.h>
#define Test 42
#define Cube(z) z*z*z


int main(void) {
  #ifndef Test
  printf("Test does not exist.\n");
  #endif

  #if Test == 42
  printf("Test has the value of 42.\n");
  #endif
  printf("Using a macro, the cube of 5 is %d\n", Cube(5));

  return 0;
}
