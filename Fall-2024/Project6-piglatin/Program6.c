/* C Program by Dave Russillo. Made for CS1310. Translates English sentences into Pig Latin. 
 *           _                      _
 *          | |                    | |
 *         / /                     \ \
 *        /  \____             ____/  \
 *   ____/   (|____)          (____|)  \____
 *  |   |   (|_____)          (_____|) |    |
 *  |   |    (|____)          (____|)  |    |
 *  |___|_____(|___)          (___|)___|____|
 *
 */
#include <stdio.h>
#include <string.h>






int main(void) {
  char sentence[81];
  char current;
  int i;

  printf("This program takes in a sentence from the user and outputs its Pig Latin version. \n"
         "Accepts sentences of max 80 characters per line. Loops until user inputs STOP as sentence. \n\n");
  while(strcmp(sentence, "stop") != 0 && strcmp(sentence, "Stop") != 0 && strcmp(sentence, "STOP") != 0) {
    printf("Input sentence here: \n\n");
    gets(sentence);
    printf("You entered: \n%s \n", sentence);
  }

  return 0;
}
