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



int check_if_vowel(char letter) {  // checks if parameter is a vowel or not
  if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || 
    letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
    return 1;
  } else {
    return 0;
  }
}



int check_if_all_consonants(char *word) {  // 0 false, 1 true
  for(; *word != '\0'; word++) {  // iterate through word's characters
    if(check_if_vowel(*word)) {
      return 0;
    }
  }
  return 1;
}



void translate(char *word) {  // translates to pig latin
  int i;  // used for iteration
  int first_vowel_reached = 0;  // 0 false, 1 true
  char temp[strlen(word) - 1]; /* temporary string used for initial consonants; 
                                 1 shorter than word because worst case vowel will be in index len - 1 */
  temp[0] = '\0';  // initialize to empty string with \0

  if(check_if_vowel(word[0]) || check_if_all_consonants(word)) {
    printf("%sway ", word);
  } else {
    for(i = 0; i < strlen(word); i++) {
      if(check_if_vowel(word[i])) {
        first_vowel_reached = 1;
      }
      if(first_vowel_reached) {
        printf("%c", word[i]);
      } else {
        temp[strlen(temp)] = word[i];
        temp[strlen(temp) + 1] = '\0';
      }
    }
    printf("%say ", temp);
  }
}



int main(void) {
  char sentence[81];  // input sentence
  char sentence_copy[81];  // copy of sentence, because strtok messes with it and causes errors
  char *current;
  int i;

  printf("This program takes in a sentence from the user and outputs its Pig Latin translation. \n"
         "In pig latin, if the word starts with a vowel, or if it doesn't have a vowel at all, \n"
         "it stays the same with only 'way' appended at the end. Otherwise, the word will start \n"
         "with every letter from the first vowel to the end of the word, with then the initial \n"
         "consonants appended, followed by 'ay'. \n"
         "Accepts sentences of max 80 characters per line, no punctuation. Loops until user inputs STOP as sentence. \n\n");
  while(strcmp(sentence, "stop") != 0 && strcmp(sentence, "Stop") != 0 && strcmp(sentence, "STOP") != 0) {
    printf("Input sentence here: \n");
    gets(sentence);
    if(strcmp(sentence, "stop") == 0 || strcmp(sentence, "Stop") == 0 || strcmp(sentence, "STOP") == 0) {
      printf("Shutting down... \n");
    } else {
      printf("\nYou entered: \n%s \n\nTranslation: \n", sentence);
      strcpy(sentence_copy, sentence);  // work with copy and keep original intact
      current = strtok(sentence_copy, " ");
      while(current != NULL) {  // for each word
        translate(current);
        current = strtok(NULL, " ");  // get next word
      }
      printf("\n\n");
    }
  }

  return 0;
}
