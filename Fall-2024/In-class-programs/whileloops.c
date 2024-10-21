/* C program by Dave Russillo. Made on 09/24/2024 for CS1310. Skip count with while */
#include <stdio.h>

void main(void) {
    int number = 0;  // for loop to skip
    
    printf("This program skip counts. \n");
    while(number < 1000) {  //  next values
        printf("%d  ", number);
        number += 3;
    }
}
