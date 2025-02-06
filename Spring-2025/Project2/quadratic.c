/* 
 * C program by Dave Russillo. Made for CS1311. 
 * Uses recursion for quadratic function.
 */
#include <stdio.h>


// f(x) = 4x^2 + 2x + 7
int f_normal(int x) {
  return 4*x*x + 2*x + 7;
}

// f(z) = f2(z-1) + 8z - 2, f(0) = 7
int f_recursive(int z) {
  if(z == 0) {
    return 7;
  }
  else {
    return f_recursive(z-1) + 8*z - 2;
  }
}


int main(void) {
  char restart = 'y';
  int num = 0;

  while(restart == 'y' || restart == 'Y') {
    while(num <= 0) {
      printf("Enter positive integer value: ");
      scanf("%d", &num);
    }
    printf("f(%d) = %d  (non-recursive) \n", num, f_normal(num));
    printf("f(%d) = %d  (recursive) \n"), num, f_recursive(num);
    printf("Would you like to restart? (y/n) ");
    scanf(" %c", &restart);
  }

  return 0;
}

