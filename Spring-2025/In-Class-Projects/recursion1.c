#include <stdio.h>

int f(int x) {
  if(x == 0) {
    return 7;
  }
  else {
    return f(x-1) + 8*x - 2;
  }
}

int main(void) {
  int num;

  for(num = 0; num < 10; num++) {
    printf("f(%d) = %d \n", num, f(num));
  }

  return 0;
}
