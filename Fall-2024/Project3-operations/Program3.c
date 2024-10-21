/* C program by Dave Russillo. Due on 10/03/2024 for CS1310. Adds, Subtracts, Multiplies, or Divides user input. */ 
#include <stdio.h>

double get_input() {
    double out;
    printf("Input value:  ");
    scanf("%lf", &out);
    printf("You entered %lf. \n", out);
    return out;
}

void add(double x, double y) {
    printf("%lf + %lf = %lf \n", x, y, x + y);
}

void sub(double x, double y) {
    printf("%lf - %lf = %lf \n", x, y, x - y);
}

void mult(double x, double y) {
    printf("%lf * %lf = %lf \n", x, y, x * y);
}

void div(double x, double y) {
    printf("%lf / %lf = %lf \n", x, y, x / y);
}

int main(void) {
    double b;
    double a;
    int operation;

    printf("This program adds, subtracts, multiplies, or divides two inputs. \n");
    a = get_input();
    b = get_input();
    
    printf(""
           "  _____________________________   \n"
           " //////////////////////////////|  \n"
           "||                            ||  \n"
           "||    PRESS 1, 2, 3, or 4!    ||  \n"
           "||----------------------------||  \n"
           "||     1 -> addition          ||  \n"
           "||     2 -> subtraction       ||  \n"
           "||     3 -> multiplication    ||  \n"
           "||     4 -> division          ||  \n"
           "||----------------------------||  \n"
           " \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\|  \n"
           "  \\____________________________|  \n"
           "");
    
    scanf("%int", &operation);
    printf("You selected operation %d: \n", operation);

    switch (operation) {
        case 1:
            add(a, b);
            break;
        case 2:
            sub(a, b);
            sub(b, a);
            break;
        case 3:
            mult(a, b);
            break;
        case 4:
            div(a, b);
            div(b, a);
            break;
        default:
            printf("Invalid input! \n");  int operation;
    }
}



