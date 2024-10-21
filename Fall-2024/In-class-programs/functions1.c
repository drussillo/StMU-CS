/* C program by Dave Russillo, made on 09/17/2024 for CS1310. Finds circumference given a radius. */
#include <stdio.h>
#define pi 3.1416



double get_radius(void) {
    double r;
    
    printf("Type in a radius in cm:  ");
    scanf("%lf", &r);
    printf("Your radius is %lfcm. \n", r);
    return r;
}



double calc_circumference(double r) {
    return 2 * pi * r;
}



void print_result(double c) {
    printf("The circumference of your circle is %lfcm. \n", c);
}



void main(void) {
    double radius;
    double circumference;
    
    printf("This program finds the circumference of your circle. \n\n");
    radius = get_radius();
    circumference = calc_circumference(radius);
    print_result(circumference);
}

