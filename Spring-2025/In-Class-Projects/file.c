/* C program by Dave Russillo. Made on 01/16/2025 for CS1311. Reads to a file and writes to a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *in; // input
  FILE *out;  // output
  char astring[81];
  char acopy[81];
  
  printf("This program reads from a file and writes to another file. \n");
  in = fopen("in.txt", "r");
  out = fopen("out.txt", "w");
  fgets(astring, 80, in);
  printf("The text from in.txt is: \n%s \n", astring);
  fprintf(out, "The text from in.txt to out.txt is: \n%s \n", astring);
  printf("The length of 'astring' is %d. \n", strlen(astring));
  strcpy(acopy, astring);
  printf("'acopy' is: %s \nstrcmp of both is %d. \n", acopy, strcmp(acopy, astring));
  
  fclose(in);
  fclose(out);
  
  return 0;
}
