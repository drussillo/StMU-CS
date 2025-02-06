/* C prgram by Dave Russillo. Made on 02/06/2025 for CS1311. LinkedList of ints */
#include <stdio.h>
#include <stdlib.h>

struct intlist {
  int num;
  struct intlist *ptr;
};
struct intlist *head, *item, *last;


int get_input(void) {
  int n = -1;
  
  while(n < 0) {
    printf("Enter an integer greater than 0:  ");
    scanf("%d", &n);
    printf("You entered %d. \n", n);
  }

  return n;
}


void print_list(void) {
  item = head;
  while(item != NULL) {
    printf("%d  ", item->num);
    item = item->ptr;
  }
}


void add_record(int number) {
  item = malloc(sizeof(struct intlist));
  item->num = number;
  item->ptr = NULL;
  if(head == NULL) {
    head = item;
  } else {
    last->ptr = item;
  }
  last = item;
}


int main(void) {
  int input;

  printf("This program creates and prints a list of integers. \n");
  head = NULL;
  input = get_input();
  while(input != 0) {
    add_record(input);
    input = get_input();
  }
  print_list();
  
  return 0;
}
