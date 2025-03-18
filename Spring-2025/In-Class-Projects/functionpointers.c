/* C program by Dave Russillo. Made on 03/18/2025 for CS1311. Testing first-class functions*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_random(void) {
  printf("Random number: %d\n", rand());
}


int main(void) {
  void (*pfunc)(void);
  void (*ppfunc)(void);
  int randres;

  srand(time(NULL));

  pfunc = print_random;
  print_random();
  (*pfunc)();

  return 0;
}
