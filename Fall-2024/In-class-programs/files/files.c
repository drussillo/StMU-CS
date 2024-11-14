/* C Program by Dave Russillo. Made on 11/14/2024 for CS1310. Test file input and output */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *in;
  FILE *out;
  char astring[256];
  int num = 0;

  printf("This program reads from in.txt and writes to out.txt \n\n");
  in = fopen("in.txt", "r");
  out = fopen("out.txt", "w");
  
  fgets(astring, 100, in);
  astring[strlen(astring) - 1] = '\0';
  printf("The text from in.txt is \"%s\". \n", astring);

  fprintf(out, "The content from in.txt is \"%s\". \n", astring);

  num = atoi(astring);
  printf("The string \"%s\" as an integer is %d. \n", astring, num);
  
  return 0;
}
