#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item {
  char name[50];
  double value;
  struct item *next;
};
struct item *start, *ptemp, *current;

int main(void) {
  printf("This program holds thing I want in a list. \n\n");
  current = malloc(sizeof(struct item));  // create first record
  strcpy(current->name, "Volkswagen Jetta");
  current->value = 5000;
  current->next = NULL;
  ptemp = current;
  start = current;
  
  // create second record
  current = malloc(sizeof(struct item));
  strcpy(current->name, "California Trip");
  current->value = 3000;
  current->next = NULL;
  ptemp->next = current;
  ptemp = current;

  // create second record
  current = malloc(sizeof(struct item));
  strcpy(current->name, "House");
  current->value = 300000;
  current->next = NULL;
  ptemp->next = current;
  ptemp = current;
  
  current = start;
  printf("\n           ITEM NAME          VALUE \n");
  while(current != NULL) {
    printf("%20s          $%.0lf \n", current->name, current->value);
    current = current->next;
  }
  
  return 0;
}
