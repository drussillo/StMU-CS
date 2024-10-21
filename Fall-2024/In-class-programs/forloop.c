/* C program by Dave Russillo. Made on 09/26/2024 for CS1310. Uses for loop to count down */
#include <stdio.h>

void main(void) {
    int count;
    int number = 0;
    
    printf("This program counts down from your number to zero. \n");
    
    do {
        printf("Type in a positive integer:  ");
        scanf("%d", &number);
        printf("You entered %d. \n\n", number);
    } while (number <= 0);
    
    printf("Count down! \n");
    for(count = number; count >= 0; count--) {
        printf("%d  ", count);
    }
}



