/* C program by Dave Russillo. Made for CS1311 on 02/20/2025 */
#include <stdio.h>
#include <stdbool.h>


void print_array(int *array, int n) {
  printf("[");
  for(int i = 0; i < n-1; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[n-1]);
}


bool check_sorted(int *array, int n) {
  for(int i = 0; i < n-1; i++) {
    if(array[i] > array[i+1])
      return false;
  }
  return true;
}


void bubblesort(int *array, int n) {
  int temp;

  while(!check_sorted(array, n)) {
    for(int i = 0; i < n-1; i++) {
      if(array[i] > array[i+1]) {
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
      }
    }
  }
}


int main(void) {
  int list[5] = {4, 2, 1, 5, 3};
  int n = 5;

  printf("This program uses bubble sort to sort a list of integers.\n"
         "Initial list: ");
  print_array(list, n);
  bubblesort(list, n);
  printf("Sorted list: ");
  print_array(list, n);

  return 0;
}
