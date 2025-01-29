/*
 * C program by Dave Russillo. Made for CS1311. 
 * Transposes videogame names from horizontal to vertical.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char names[20][60];  // 20x60 array of chars for names
  FILE *in;  // input file
  FILE *out;  // output file
  int max_length = 0;  // used to print the necessary lines only
  int i;  // iteration
  int j;  // iteration
  in = fopen("names.txt", "r");  // open input file
  out = fopen("transpose.txt", "w");  // open output file

  printf("This program takes twenty videogame names from names.txt "
         "and transposes them from horizontal to vertical. \n\n");

  // initialize names with blank spaces
  for(i = 0; i < 20; i++) {
    for(j = 0; j < 60; j++) {
      names[i][j] = ' ';  // replace each char in each string with ' '
    }
  }

  // read names from names.txt and set newline characters to null characters
  for(i = 0; i < 20; i++) {
    fgets(names[i], 60, in);
    names[i][strcspn(names[i], "\n")] = '\0';
    // uses strcspn which gives the index of the first appearance of a character
  }

  // find length of longest name
  for(i = 0; i < 20; i++) {
    if(strlen(names[i]) > max_length) {
      max_length = strlen(names[i]);
    }
    // remove null characters for later
    names[i][strcspn(names[i], "\0")] = ' ';  // remove first one (prev. newline)
    names[i][strcspn(names[i], "\0")] = ' ';  // remove second one
  }

  // transpose and add spaces
  // for each character position from 0 to the length of the longest name
  for(i = 0; i < max_length; i++) {
    for(j = 0; j < 20; j++) {  // for each name
      // print out the character and two spaces
      fprintf(stdout, "%c  ", names[j][i]);  // to stdout
      fprintf(out, "%c  ", names[j][i]);  // to transpose.txt
    }
    // add newline between each line to stdout and transpose.txt
    fprintf(stdout, "\n");
    fprintf(out, "\n");
  }

  // close files
  fclose(in);
  fclose(out);
  return 0;
}
