/* C program by Dave Russillo. Made on 10/10/2024 for CS1310. Times table - read and print the product of 2 integers */
#include <stdio.h>



int get_number(void) {
  int number;
  
  printf("Input number:  ");
  scanf("%d", &number);
  printf("Your input is %d. \n", number);
  return number;
}



void print_table(void) {
    int i;
    int j;
    for(i = 1; i < 11; i++) {
        if(i < 10) printf("\n%d  ", i);
        else printf("\n%d ", i);
        for(j = 2; j < 11; j++) {
            if(j*i > 9) printf("%d  ", j * i);
            else printf(" %d  ", j * i);
        }
    }
}



void main(void) {
  int times[11][11];
  int i;
  int j;
  int num1;
  int num2;

  printf("This program looks up the product of two numbers 0 to 10. \n");
  for(i = 0; i < 11; i++) {
    for(j = 0; j < 11; j++) {
      times[i][j] = i * j;
    }
  }
  num1 = get_number();
  num2 = get_number();

  printf("\n\n%d times %d is %d. (%d * %d = %d) \n\n",
         num1, num2, times[num1][num2], num1, num2, num1 * num2);
         
    print_table();
}
