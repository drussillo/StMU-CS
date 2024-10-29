/* C program by Dave Russillo. Made on 10/29/2024 for CS1310. Print plural forms of words. */
#include <stdio.h>
#include <string.h>

int main(void) {
    char string[256] = "";  // input word from the user
    
    printf("This program prints the plural form of your word. \n");
    while(strcmp(string, "done") != 0 && strcmp(string, "Done") != 0) {
        printf("Type in a word or done when finished:  ");
        gets(string);  // assuming one word
        printf("The plural form of %s is ", string);
        
        if(strcmp(string, "foot") == 0) {
            printf("feet. \n");
        }
        if(string[strlen(string) - 1] == 'y') {
            string[strlen(string) - 1] = '\0';
            printf("%sies. \n", string);
        }
            
        
        printf("%s. \n", string);
    }
    
    return 0;
}
