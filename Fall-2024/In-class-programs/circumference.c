/* C program by Dave Russillo for CS1310, made on September 5th, 2024. Calculates circumference and area based on the radius. */
#include <stdio.h>
#define pi 3.14159  // the constant pi for circles

void main(void) {
    double radius;  // radius in inches
    double circumference;   // circumference in inches to be output
    double area;   // area in square inches to be output
    
    // get radius from user
    printf("Enter circle's radius in inches: ");
    scanf("%lf", &radius);
    printf("\nYou entered %lf inches as the radius. \n\n", radius);
    
    // calculate circumference and area
    circumference = 2 * radius * pi;
    area = pi * radius * radius;
    
    // print out results
    printf("The circumference of your circle is approximately %lf inches. \n", circumference);
    printf("The area of your circle is approximately %lf square inches. \n", area);
}


