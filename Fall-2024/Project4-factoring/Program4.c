/* C program by Dave Russillo. Due on 10/17/2024 for CS1310. 
 *
 *           _                      _
 *          | |                    | |
 *         / /                     \ \
 *        /  \____             ____/  \
 *   ____/   (|____)          (____|)  \____
 *  |   |   (|_____)          (_____|) |    |
 *  |   |    (|____)          (____|)  |    |
 *  |___|_____(|___)          (___|)___|____|
 *
 *
 * Takes two positive integer inputs; outputs all factors, prime factorization, LCM, and GCD.
 * 
 */
#include <stdio.h>



int get_positive_integer(void) {
  int input = 0;

  do {
    printf("Input value:  ");
    scanf("%d", &input);
    printf("Your input is %d. \n\n", input);
    if(input < 1) printf("Invalid input! Try again! \n\n");  // check if input is not positive
  } while(input < 1);
  return input;
}



void get_factors(int value) {
  int i;

  for(i = 1; i < value; i++) {
    if(value % i == 0) {  // check if value is divisible by each number from 1 to value - 1
      printf("%d, ", i);
    }
  }
  printf("%d. \n", value);  // print value, because value is always a factor of itself
}



void get_prime_factors(int value) {  /* inspired by Dr. Redfield's code */
  int count = 1;

  while(count < value) {
    count++;
    if(value % count == 0) {
      printf("%d  ", count);
      value /= count;
      count--;
    }
  }
  printf("\n");
}



void get_lcm(int value_a, int value_b) {
  int base = value_a;
  int lcm;

  if(value_a < value_b) base = value_b;  // set base to highest of given values
  lcm = base;  // set lcm to base
  while(lcm % value_a != 0 || lcm % value_b != 0) {
    lcm += base;  // if current lcm is not lcm, increment it by the base and test again
  }
  printf("The LCM of %d and %d is %d. \n", value_a, value_b, lcm);
}



void get_gcd(int value_a, int value_b) {
  int gcd = value_a;
  if(value_a > value_b) gcd = value_b;  // set gcd to smallest of the given values

  while(value_a % gcd != 0 || value_b % gcd != 0) {
    gcd--;  // keep decrementing gcd until it's divisible by both values
  }
  printf("The GCD of %d and %d is %d. \n", value_a, value_b, gcd);
}



void main(void) {
  int input_a;
  int input_b;
  char restart = 'n';
  
  do {
    input_a = get_positive_integer();
    input_b = get_positive_integer();
    printf("Your inputs are %d and %d! \n\n", input_a, input_b);
    printf("%d's factors are:  ", input_a);
    get_factors(input_a);
    printf("%d's factors are:  ", input_b);
    get_factors(input_b);
    printf("%d's prime factors are:  ", input_a);
    get_prime_factors(input_a);
    printf("%d's prime factors are:  ", input_b);
    get_prime_factors(input_b);
    get_lcm(input_a, input_b);
    get_gcd(input_a, input_b);
    printf("\nWould you like to restart?  (y/n):  ");
    scanf(" %c", &restart);
  } while(restart == 'y' || restart == 'Y');
}



