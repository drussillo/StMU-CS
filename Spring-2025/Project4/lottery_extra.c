/* C program by Dave Russillo. Made for CS1311. Lottery. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void set_guesses_and_results(int *guesses, int *results, int len, int range_lo, int range_hi) {
  for(int i = 0; i < len; i++) {
    // get user input
    bool valid_number = false; while(!valid_number) {
      printf("Enter unique number between %d and %d (position %d): ", range_lo, range_hi, i+1);
      scanf("%d", &guesses[i]);
      // check if not in range
      if(guesses[i] < range_lo || guesses[i] > range_hi) {
        printf("Out of range number! Try again...\n");
      } else {
        valid_number = true;
        // check if already picked
        for(int j = 0; j < i; j++) {
          if(guesses[j] == guesses[i]) {
            printf("Number already picked! Try again...\n");
            valid_number = false;
            break;
          }
        }
      }
    }
    // generate random numbers
    valid_number = false;
    while(!valid_number) {
      results[i] = range_lo + rand() % (range_hi - range_lo);
      valid_number = true;
      // check if already generated
      for(int j = 0; j < i; j++) {
        if(results[j] == results[i]) {
          valid_number = false;
          break;
        }
      }
    }
  }
}


void bubble_sort(int *array, int len) {
  bool swapped = true;
  int temp;
  while(swapped) {
    swapped = false;
    for(int i = 0; i < len-1; i++) {
      if(array[i] > array[i+1]) {
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
        swapped = true;
      }
    }
  }
}


void check_guesses(int *guesses, int *results, int len) {
  int correct_guesses = 0;
  // assumes guesses and results are sorted
  for(int i = 0; i < len; i++) {
    for(int j = 0; j < len && results[j] <= guesses[i]; j++) {
      if(results[j] == guesses[i]) {
        printf("You guessed %d correctly!\n", guesses[i]);
        correct_guesses++;
      }
    }
  }
  printf("You made %d correct guesses.\n", correct_guesses);
}


void print_array(int *array, int len) {
  printf("[");
  for(int i = 0; i < len-1; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[len-1]);
}


int main(void) {
  int range_lo;
  int range_hi;
  int len;

  printf("In this lottery you try to guess a chosen amount of random numbers in a user defined range\n\n");
  printf("Choose the amount of numbers in the lottery: ");
  scanf("%d", &len);
  printf("Enter low bound of range: ");
  scanf("%d", &range_lo);
  printf("Enter high bound of range: ");
  scanf("%d", &range_hi);

  int guesses[len];
  int results[len];
  srand(time(NULL));
  set_guesses_and_results(guesses, results, len, range_lo, range_hi);
  printf("\nYour guesses (in order you picked): ");
  print_array(guesses, len);
  printf("Random results (in order they were generated): ");
  print_array(results, len);

  bubble_sort(guesses, len);
  bubble_sort(results, len);
  printf("Your guesses (sorted): ");
  print_array(guesses, len);
  printf("Random results (sorted): ");
  print_array(results, len);

  check_guesses(guesses, results, len);

  return 0;
}
