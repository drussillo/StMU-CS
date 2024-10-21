/* C program by Dave Russillo. Made on 09/24/2024 for CS1310. Prints every number from user input a to user input b */
#include <stdio.h>



int get_input() {
    int out;
    scanf("%d", &out);
    return out;
}



void main(void) {
    int a = 0;
    int b = 0;
    char again = 'n';
    
    printf("Enter first number:   ");
    a = get_input();
    printf("Enter second number:  ");
    b = get_input();
    printf("Your inputs are a = %d, b = %d. \n\n", a, b);
    while(a < b) {
        printf("%d  ", a);
        a++;
    }
    while(a > b) {
        printf("%d  ", a);
        a--;
    }
} 



