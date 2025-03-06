/* C program by Dave Russillo. Made on 03/06/2025 for CS1311. Family tree. */
#include <stdio.h>
#include <string.h>


struct Person {
  char name[50];
  char spouse[50];
  int child_amount;
  struct Person *children[2];
};
struct Person grandmother, mother, sister, me;


void print_tree(void) {
  void print_tree_helper(struct Person *current) {
    printf("Person is %s, ", current->name);
    if(strcmp(current->spouse, "") != 0) {
      printf("married to %s, ", current->spouse);
    }
    else {
      printf("not married, ");
    }
    if(current->child_amount) {
      printf("with %d kids: ", current->child_amount);
      for(int i = 0; i < current->child_amount; i++) {
        if(i != current->child_amount - 1) {
          printf("%s and ", current->children[i]->name);
        } else {
          printf("%s.\n", current->children[i]->name);
        }
      }
      for(int i = 0; i < current->child_amount; i++) {
        print_tree_helper(current->children[i]);
      }
    } else {
      printf("with no kids.\n");
    }
  }
  print_tree_helper(&grandmother);
}


int main(void) {
  strcpy(grandmother.name, "Lidia");
  strcpy(grandmother.spouse, "Donato");
  grandmother.child_amount = 1;
  grandmother.children[0] = &mother;
  strcpy(mother.name, "Serena");
  strcpy(mother.spouse, "Roberto");
  mother.child_amount = 2;
  mother.children[0] = &sister;
  mother.children[1] = &me;
  strcpy(sister.name, "Dafne");
  strcpy(me.name, "Davide");
  print_tree();

  return 0;
}
