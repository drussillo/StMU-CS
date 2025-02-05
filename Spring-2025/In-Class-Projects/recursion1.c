#include <stdio.h>

// f1(x) = 4x^2 + 2x + 7
int f1(int x) {
  return 4*(x*x) + 2*x + 7;
}

// f2(z) = f2(z-1) + 8z - 2
int f2(int z) {
  if(z == 0) {
    return 7;
  }
  else {
    return f2(z-1) + 8*z - 2;
  }
}


int main(void) {
  int num;

  for(num = 0; num < 10; num++) {
    printf("f1(%d) = %d,  ", num, f1(num));
    printf("f2(%d) = %d \n", num, f2(num));
  }

  return 0;
}

