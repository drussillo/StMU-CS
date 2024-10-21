/* C prograam by Dave Russillo for CS1310 September 5th, 2024 */
#include <stdio.h>

void main(void) {
    char letter; // holds user characters
    int inumber = 0;
    double dnumber;
    
    printf("This program prints out what you type in. \n\n");
    scanf("%c", &letter);
    scanf("%c"); // capture newline character from entering first letter
    printf("\nYou entered: %c \n\n", letter);
        
    printf("Type in another character and enter:  ");
    scanf("%c", &letter);
    printf("\nYou entered: %c \n", letter);
    
    printf("Enter an integer: ");
    scanf("%d", &inumber);
    printf("You entered %d. \n\n", inumber);
    
    printf("Enter a decimal number: ");
    scanf("%lf", &dnumber);
    printf("You entered %lf. \n\n", dnumber);
}

