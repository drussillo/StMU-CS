/* C program by Dave Russillo. Made on 03/18/2025 for CS1311. Further testing of first-order functions */
#include <stdio.h>


int square(int x) {
  return x*x;
}

double sum(double a, double b) {
  return a + b;
}


int main(void) {
  int input;
  int number;
  int (*pfunc)(int);

  pfunc = square;
  printf("Input integer to square: ");
  scanf("%d", &input);
  number = (*pfunc)(input);
  printf("%d sqared is %d.\n", input, number);

  double y;
  double (*pfunc1)(double a, double b);
  pfunc1 = sum;
  y = pfunc1(0.1, 0.2);
  printf("%lf\n", y);

  return 0;
}
