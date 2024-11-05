/* C Program by Dave Russillo. Made on 11/05/2024 for CS1310. Playing with string token */
#include <stdio.h>
#include <string.h>

int main(void) {
    char sentence[81];
    char *psentence;
    
    printf("This program translates the words ...  \n");
    printf("Type end to finish. ");
    do {  // for each sentence
        printf("\nType a phrase until 'end': \n");
        gets(sentence);
        printf("You entered the phrase \n%s \n", sentence);
        psentence = strtok(sentence, " ");
        while(psentence != NULL) {  // for each word
            printf("Word = %s  \n", psentence);
            psentence = strtok(NULL, " ");  // get next word
        }
    } while(strcmp(sentence, "end") != 0);
    
    return 0;
}
