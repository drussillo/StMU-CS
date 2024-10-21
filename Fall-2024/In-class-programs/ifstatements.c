/* C program by Dave Russillo, made on 09/10/2024 for CS1310. Checks if input is > 0. */
#include <stdio.h>

void main(void) {
    double number = 0; // get it from the user
    
    printf("Check for valid positive input. \n");
    printf("Type in a distance:");
    scanf("%lf", &number);
    printf("You entered %lf. \n\n", number);
    if(number > 0) { // distance must be positive
        printf("%lf is a valid value.", number);
        printf("You can divide by %lf such that 1 / %lf = %lf \n", number, number, 1 / number);
    } else {
        printf("Invalid input. Distance must be positive. \n");
    }
}
