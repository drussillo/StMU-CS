#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char names[20][60];
  FILE *in;
  FILE *out;
  int max_length = 0;
  int i;
  int j;
  in = fopen("names.txt", "r");
  out = fopen("transpose.txt", "w");

  // initialize names with blank spaces
  for(i = 0; i < 20; i++) {
    for(j = 0; j < 60; j++) {
      names[i][j] = ' ';
    }
  }

  // read names from names.txt and remove newline characters
  for(i = 0; i < 20; i++) {
    fgets(names[i], 60, in);
    names[i][strcspn(names[i], "\n")] = '\0';
  }

  // find length of longest name
  for(i = 0; i < 20; i++) {
    if(strlen(names[i]) > max_length) {
      max_length = strlen(names[i]);
    }
  }

  // transpose and add spaces
  for(i = 0; i < max_length; i++) {
    for(j = 0; j < 20; j++) {
      if(names[j][i] != '\0') {
        fprintf(stdout, "%c  ", names[j][i]);
        fprintf(out, "%c  ", names[j][i]);
      } else {
        fprintf(stdout, "   ");
        fprintf(out, "   ");
      }
    }
    fprintf(stdout, "\n");
    fprintf(out, "\n");
  }

  fclose(in);
  fclose(out);
  return 0;
}
