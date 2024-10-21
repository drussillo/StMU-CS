/* C program by Dave Russillo, made on 09/10/2024 for CS1310. Says how many digits input has. */
#include <stdio.h>
#include <stdbool.h>

void main(void) {
    int number;
    int bound = 10;
    int i;
    
    printf("Type in an integer: ");
    scanf("%d", &number);
    printf("You entered %d. \n\n", number);
    
    for(i = 1; !(number > -bound && number < bound); i++) {
        bound *= 10;
    }
    printf("Your number has %d digits. \n", i);
}
