/* C Program by Dave Russillo. Made on 11/12/2024 for CS1310. Example Array of Structures. */
#include <stdio.h>
#include <string.h>

struct games {
    char person1[50];
    char person2[50];
    int score1;
    int score2;
};
    struct games plays[6];

void put_plays(int index, char name1[], char name2[], int num1, int num2) {
    strcpy(plays[index].person1, name1);
    strcpy(plays[index].person2, name2);
    plays[index].score1 = num1;
    plays[index].score2 = num2;
    printf("entered record %d \n", index);
}

int main(void) {
    int i;
    int total_score = 0;

    printf("This program records and prints scores for the day. \n");
    put_plays(0, "Dave", "John", 3000, 1000);
    put_plays(1, "Jessica", "Alex", 231, 158);
    put_plays(2, "Nick", "Joe", 2231, 194);
    put_plays(3, "Mark", "Frank", 7180, 1540);
    put_plays(4, "George", "Peter", 15040, 3880);
    put_plays(5, "Stacy", "Greg", 550, 300);
    printf("// The scores for today are... \\\\ \n");
    for(i = 0; i < 6; i++) {
        printf("%-10s won with %6d against %-10s with %6d \n", 
                plays[i].person1, plays[i].score1, plays[i].person2, plays[i].score2);
        total_score += plays[i].score1 + plays[i].score2;
    }
    printf("The total score is %d \n", total_score);
    
    return 0;
}
