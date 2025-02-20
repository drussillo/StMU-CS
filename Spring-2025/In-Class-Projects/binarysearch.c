/* C program by Dave Russillo. Made on 02/18/2025 for CS1311. Does binary search. */

#include <stdio.h>

#define findvalue 55
#define items 10

int main(void) {
  int scores[items] = {3, 5, 7, 10, 20, 40, 55, 70, 90, 101};
  int current = 0, min = 0, max=items-1, i;
  int findme = findvalue;
  int found = -1, count = 0;

  printf("This program does a binary search. \n");
  printf("List: ");
  for(i = 0; i < items; i++) {
    printf("%d  ", scores[i]);
  }
  printf("\n");

  while(found == -1 && min != max && count < items) {
    count++;
    if(current == max-1) {
      current = max;
    } else {
      current = (min + max) / 2;
    }
    printf("count = %d  min = %d  current = %d  max = %d\n",
           count, min, current, max);
    if(scores[current] == findme) {
      found = current;
    } else {
      if(findme < scores[current]) {
        max = current;
      } else {
        min = current;
      }
    }
  }
  if(found == -1) {
    printf("\nelement %d was not found in scores.\n", findme);
  } else {
    printf("\nvalue %d was found at index %d.\n", findme, found);
  }

  return 0;
}
