/* C program by Dave Russillo. Made on 10/17/2024 for CS1310. Mess with strings */
#include <stdio.h>
#include <string.h>

void main(void) {
    char string[256];
    char substring[81];
    int number;
    
    printf("This program says how long a phrase is. \n");
    printf("Type in a line: \n");
    gets(string);
    printf("\nYour phrase is \n%s\n", string);
    printf("and has %d characters. \n", strlen(string));
    
    strcpy(substring, string);
    printf("This line is a copy: \n%s\n", substring);
    printf("The two strings compared return %d. \n\n", strcmp(string, substring));
    
    printf("How many characters do ou want?   ");
    scnaf("%d", &number);
    printf("You are asking for %d characters. \n", number);
    strncpy(substring, *string[0], number);
    printf("The substring before null character is ")
}
