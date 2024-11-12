/* C Program by Dave Russillo. Made on 11/07/2024 for CS1310. Example of a structure */
#include <stdio.h>
#include <string.h>

typedef struct games {
    char person1[5];
    char person2[50];
    int score;
} games;

int main(void) {
    games first;
    games second;
    
    printf("Here are the scores for today's games  \n\n");
    
    strcpy(first.person1, "Dave");
    strcpy(first.person2, "Llama");
    first.score = 500;
    printf("%s won againt %s with a score of %d. \n", first.person1, first.person2, first.score);
    
    return 0;
}
