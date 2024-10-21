/* C program by Dave Russillo, made on 09/12/2024 for CS1310. Prints name of digit, switch example */
#include <stdio.h>

void main(void) {
    int digit; // user's input
    
    printf("This program prints the English name of your digit. \n");
    printf("Type in a digit:  ");
    scanf("%d", &digit);
    printf("You entered %d. \n\n", digit);
    
    printf("Your digit name for %i is: ", digit);
    switch(digit) {
        case -1:
            printf("Negative One \n");
            break;
        case 0:
            printf("Zero \n");
            break;
        case 1:
            printf("One \n");
            break;
        case 2:
            printf("Two \n");
            break;
        case 3:
            printf("Three \n");
            break;
        case 4:
            printf("Four \n");
            break;
        case 5:
            printf("Five \n");
            break;
        case 6:
            printf("Six \n");
            break;
        case 7:
            printf("Seven \n");
            break;
        case 8:
            printf("Eight \n");
            break;
        case 9:
            printf("Nine \n");
            break;
        default:
            printf("not valid because it is not a single digit. \n");        
    }
}



