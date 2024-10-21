/* C program by Dave Russillo. Made on 10/01/2024 for CS1310. Finds prime numbers. */
#include <stdio.h>

void main(void) {
    int number;  // user value
    int i;
    int j;
    int is_prime;  // 0 = false, 1 = true

    printf("This program prints out primes up to your number. \n");
    printf("Enter a positive integer:  ");
    scanf("%d", &number);  // user enters number
    printf("You typed in %d. \n\n", number);
    
    printf("The primes less than or equal to %d are \n", number);
    for(i = 1; i < number; i++) {  // check from 1 to number - 1
        is_prime = 1; // assume i to be prime
        
        for(j = 2; j < i; j++) {  // check every number from 2 to i - 1
            if(i % j == 0) {
                is_prime = 0;
            }
        }
        
        if(is_prime == 1) {  // print i if it's prime
            printf("%d ", i);
        }
    }
}
