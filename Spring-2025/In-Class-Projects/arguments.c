/* C program by Dave Russillo. Made on 03/25/2025 for CS1311. Arguments to main. */
#include <stdio.h>

enum text {no, yes};
enum text testing = no;


int main(int argc, char *argv[]) {
  for(int i = 0; i < argc; i++) {
    printf("element %d is: '%s'\n", i, argv[i]);
  }
  
  return 0;
}
