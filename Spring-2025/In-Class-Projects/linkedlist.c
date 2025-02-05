/* C program by Dave Russillo. Made on 01/30/2025 for CS1311. Linked List */
#include <stdio.h>
#include <string.h>

struct node {
  char money[40];  // name of coin
  int value;  // number of cents
  struct node *next;  // pointer to next node
};
struct node m1, m5, m10, m25, m50, m100;
struct node *item;

int main(void) {
  strcpy(m1.money, "penny");
  m1.value = 1;
  m1.next = &m5;
  strcpy(m5.money, "nickel");
  m5.value = 5;
  m5.next = &m10;
  strcpy(m10.money, "dime");
  m10.value = 10;
  m10.next = &m25;
  strcpy(m25.money, "quarter");
  m25.value = 25;
  m25.next = &m50;
  strcpy(m50.money, "half dollar");
  m50.value = 50;
  m50.next = &m100;
  strcpy(m1.money, "dollar");
  m100.value = 100;
  m100.next = NULL;
  
  printf("&m1 = %p, m1.next = %p;      A %s is worth %d cents. \n", 
          &m1, m1.next, m1.money, m1.value);
  
  item = &m1;
  while(item != NULL) {
    printf("item = %p; money = %s; value = %d; next = %p \n", 
            item, item->money, item->value, item->next);
    item = item->next;
  }
  
  return 0;
}
