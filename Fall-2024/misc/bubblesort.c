/* Bubble sort in C: Test */
#include <stdio.h>

int is_sorted(int* array, int length) {
  int i;
  for(i = 0; i < length; i++) {
    if(array[i] > array[i+1]) {
        return 0;
    }
  }
  return 1;
}

void print_array(int* array, int length) {
  for(int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void fill_array(int* array, int length) {
  int value;

  for(int i = 0; i < length; i++) {
    printf("Enter index %d value: ", i);
    scanf("%d", &value);
    array[i] = value;
  }
}

void bubble_sort(int* array, int length) {
  int temp;

  while(!is_sorted(array, length)) {
    for(int i = 0; i < length-1; i++) {
      if(array[i] > array[i+1]) {
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
      }
    }
  }
}

int main(void) {
  int length;
  printf("Input length:  ");
  scanf("%d", &length);
  int nums[length];

  fill_array(nums, length);
  print_array(nums, length);
  bubble_sort(nums, length);
  print_array(nums, length);
  
  return 0;
}
