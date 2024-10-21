/* Practice C program by Dave Russillo, made on 08/22 for the 'Variables and Expressions' chapter on the textbook */

#include <stdio.h>

void main(void) {
    /* TASK 1 */
    char initial = 'D';
    int age = 18;
    double price = 15.98;    
    printf("My first initial is %c, I am %d years old, and my favorite meal costs $%lf. \n", initial, age, price);

    /* TASK 2 */
    int x1 = 7;
    int x2 = 3;
    printf("7 and 3    Sum: %d  Difference: %d  Product: %d  Quotient: %d \n", x1 + x2, x1 - x2, x1 * x2, x1 / x2);
    
    /* TASK 3 */
    int x = 0;
    printf("f(0) = %d \n", -x*x*x + 2*x*x - 3*x + 4*x);
    x += 1;
    printf("f(1) = %d \n", -x*x*x + 2*x*x - 3*x + 4*x);
    x += 1;    
    printf("f(2) = %d \n", -x*x*x + 2*x*x - 3*x + 4*x);
    x += 8;
    printf("f(10) = %d \n", -x*x*x + 2*x*x - 3*x + 4*x);
}
