/* C program by Dave Russillo. Compares two numbers. */
#include <stdio.h>



double get_number(void) {
  double number; // user input

  printf("Type in any number:  ");
  scanf("%lf", &number);
  printf("You entered %lf. \n\n", number);
  return number;
}



/* prints the relationship between one and two. */
void print_more_or_less(double one, double two) {
  if(one < two) {
    printf("%lf is smaller and %lf is larger. \n\n", one, two);
  } else if (two < one) {
    printf("%lf is larger and %lf is smaller. \n\n", one, two);
  } else {
    printf("%lf and %lf are equal. \n\n", one, two);
  }
}



void main(void) {
  double first;
  double second;
  printf("This program tells you what number is more or less. \n");
  
  first = get_number();
  second = get_number();
  printf("%lf and %lf will now be compared. \n\n", first, second); 
  print_more_or_less(first, second);
}


