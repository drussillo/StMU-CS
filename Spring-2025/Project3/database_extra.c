/*
 * C program by Dave Russillo. Made for CS1311.
 * Takes collection of items and puts it in linked list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct videogame {
  char name[31];
  double space;  // in GB
  int playtime;  // in hours
  double price;  // in USD
  struct videogame *next;
};
struct videogame *head, *last, *current;
int entries;  // length of list


void add_node(void) {
  int valid_value = 0;  // boolean

  // new struct
  current = malloc(sizeof(struct videogame));

  // set name
  printf("Enter name (will read up to 30 characters): ");
  fgets(current->name, 31, stdin);
  if(current->name[29] == '\n') {  // if input is exactly 30
    current->name[29] == '\0';
  } else if(strlen(current->name) == 30) {  // if input is greater than 30
    while(getchar() != '\n');  // clear input buffer
  } else {
    current->name[strlen(current->name)-1] = '\0';  // replace newline
  }

  // set space
  while(valid_value == 0) {
    printf("Enter required space in GB (up to 9,999.9): ");
    scanf("%lf", &current->space);
    if(current->space < 0.000001 || current->space > 9999.9) {
      printf("Invalid value for required space was entered. Try again. \n");
    } else {
      valid_value = 1;  // pass
    }
  }
  valid_value = 0;  // reset valid_value

  // set playtime
  while(valid_value == 0) {
    printf("Enter playtime in hours (up to 99,999): ");
    scanf("%d", &current->playtime);
    if(current->playtime < 0 || current->playtime > 99999) {
      printf("Invalid value for playtime was entered. Try again. \n");
    } else {
      valid_value = 1;  // pass
    }
  }
  valid_value = 0;  // reset valid_value

  // set price
  while(valid_value == 0) {
    printf("Enter price in USD (enter up to 999.99): ");
    scanf("%lf", &current->price);
    if(current->price < 0 || current->price > 999.99) {
      printf("Invalid value for price was entered. Try again. \n");
    } else {
      valid_value = 1;  // pass
    }
  }
  valid_value = 0;  // reset valid_value

  while(getchar() != '\n');  // clear input buffer
  
  // set next
  current->next = NULL;

  if(head == NULL) {
    head = current;
  } else {
    last->next = current;
  }
  last = current;
  entries++;  // track entries
}


void print_nodes(void) {
  char price_buffer[8];

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("CURRENT DATA (%d ENTRIES): \n", entries);
  printf(" __________________________________________________________________  \n");
  printf("|                                |            |          |         | \n");
  printf("| name                           | req. space | playtime |  price  | \n");
  printf("|________________________________|____________|__________|_________| \n");
  if(head == NULL) {
    printf("|                                |            |          |         | \n");
    printf("| NULL                           |       NULL |     NULL |    NULL | \n");
    printf("|________________________________|____________|__________|_________| \n");
  } else {
    current = head;
    while(current != NULL) {
      sprintf(price_buffer, "$%.2f", current->price);
      printf("|                                |            |          |         | \n");
      printf("| %-30s | %8.1fGB | %6dh  | %7s | \n", current->name, current->space, current->playtime, price_buffer);
      printf("|________________________________|____________|__________|_________| \n");
      current = current->next;
    }
  }
  printf("\n\n");
}


int main(void) {
  char selection = '0';  // add or delete

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("This program take videogames' names, required space, playtime, and price as input. \n"
         "It then puts them in a liked list database. \n\n"
         "Press enter to continue \n");
  getchar();

  while(selection != 'a' && selection != 'd' && selection != 'q') {
    print_nodes();
    printf("What would you like to do? \n"
           "Add Entry(a), Delete Entry(d), Quit(q)\n\n?..");
    scanf(" %c", &selection);
    getchar();

    if(selection == 'a') {
      print_nodes();
      add_node();
      selection = '0';
    }
  }

  return 0;
}
