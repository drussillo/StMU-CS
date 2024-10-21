/* C program by Dave Russillo, made on 09/17/2024 for CS1310. Finds f(x) = 3x^2 + 2x + 1 */
#include <stdio.h>

void findfofx(int x) {
    printf("f(%d) = %d", x, 3*x*x + 2*x + 1);
}



void main(void) {
    int num;  // user input
    
    printf("This program finds the values of f(x) = 3x^2 + 2x + 1. \n");
    scanf("%d", &num);
    printf("You entered %d. \n\n", num);\
    findfofx(num);
}



