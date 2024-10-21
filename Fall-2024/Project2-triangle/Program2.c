/* C Program 2: Triangle. By Dave Russillo for CS1310. Returns area of triangle based on length of sides. 
 * It'll use the formula A = sqrt(s * (s-a) * (s-b) * (s-c)) for the area.
 * It'll use the formula s = 1/2 * (a + b + c) for s.
 */

#include <stdio.h>
#include <math.h>


void main(void) {
  double side_a;
  double side_b;
  double side_c;
  double s;
  double area;

  printf("This program prints out the area of a triangle based on the lengths of the sides. \n"
         "It does this using Heron's formula! \n\n");
  printf(""
         "        # \n"
         "   a  #   #  b \n"
         "    #       # \n"
         "  # # # # # # # \n"
         "        c \n");
  printf("Input length of side a in cm: ");
  scanf("%lf", &side_a);
  printf("\nInput length of side b in cm: ");
  scanf("%lf", &side_b);
  printf("\nInput length of side c in cm: ");
  scanf("%lf", &side_c);
  printf("\nYour inputs are: a = %lfcm, b = %lfcm, c = %lfcm. \n\n", side_a, side_b, side_c); // prints out given inputs

  if(side_a <= 0 || side_b <= 0 || side_c <= 0) { // checks if any of the values are negative
    printf("Invalid inputs. All side lengths have to be positive. \n");
  } else if(side_a + side_b <= side_c || side_a + side_c <= side_b || side_b + side_c <= side_a) { // checks if the lenghts are unviable
    printf("Not a triangle. The lengths don't make up a triangle. \n");
  } else {
    s = 0.5 * (side_a + side_b + side_c); // calculate s
    area = sqrt(s * (s - side_a) * (s - side_b) * (s - side_c)); // calculate the area
    printf("The area of your triangle is of %lf. \n", area); // prints out result
  }
}



