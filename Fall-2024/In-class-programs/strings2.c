/* C program by Dave Russillo. Made on 11/05/2024 for CS1310. Gets words from a sentence. */
#include <stdio.h>
#include <string.h>

int main(void) {
    char words[] = "Teamwork makes the dream work.";
    char *point;  // for the start of each word
    int i;
    
    printf("The string is \n%s \nThe words are \n", words);
    for(i = 0; i < strlen(words); i++) {
        if(words[i] == ' ') {
            printf(" \n");
        } else {
            printf("%c", words[i]);
        }
    }
    
    printf("\n\n");
    
    printf("The string is \n%s \nThe words are \n", words);
    point = strtok(words, " ");  // get first word
    while(point != NULL) {
        printf(" %-12s (word starts at %p) \n", point, point);
        point = strtok(NULL, " ");  // next word; replace ' ' with \0
    }
    
    return 0;
}
