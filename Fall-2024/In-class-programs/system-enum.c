/* C Program by Dave Russillo. Made on 10/31/2024 for CS1310. System and enumerate examples */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    enum toggle {
        off,
        on
    };
    enum toggle abit = off;
    char move = 'y';
    
    printf("This part of the program calls up other commands. \n\n");
    system("dir *.exe");
    
    printf("\n\nThis program section toggles a bit as long as you want. \n");
    while(move == 'y') {
        printf("abit is %i. \n", abit);
        printf("Would you like to toggle abit? (y for yes):  ");
        scanf("%c", &move);
        getchar();  // capture newline
        if(abit == on) {
            abit = off;
        } else {
            abit = on;
        }
    }
    
    return 0;
}
