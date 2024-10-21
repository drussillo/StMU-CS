/* C program by Dave Russillo. Made on 09/19/2024 for CS1310. */
#include <stdio.h>
#include <math.h>



double get_leg(void) {
  double leg;

  printf("Input length of leg:  ");
  scanf("%lf", &leg);
  printf("You entered %lf for a leg. \n", leg);
  return leg;
}



void main(void) {
  double a;
  double b;
  double c;
  double A;
  double B;
  double C = 90;

  printf("Given two leg lengths, this program gets the rest. \n\n");
  a = get_leg();
  b = get_leg();
  printf("\nCalculating other mesures with %lf and %lf lefs. \n", a, b);

  if(a <= 0 || b <= 0) {
    printf("... or not, since at least one side is <= zero. \n");
  } else {
    c = sqrt(a * a + b * b);
    A = (180/3.14) * asin(a/c);
    A = (180/3.14) * asin(b/c);
    printf("The triangle has side lengths. \n");
    printf("%lf, %lf, %lf and angles %lf, %lf, 90 degrees. \n", a, b, c, A, B);
  }
}




