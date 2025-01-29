/* C program by Dave Russillo. Made on 01/23/2025 for CS1311. Factorial nonlinear recursion test */
#include <stdio.h>

int factorial(int x) {
  if(x <= 1) {
    return 1;
  }
  else {
    return x * factorial(x - 1);
  }
}

int main(void) {
  int num = 0;
  int fact = 0;

  printf("Input number: ");
  scanf("%d", &num);
  fact = factorial(num);
  printf("%d! = %d \n", num, fact);

  return 0;
}

