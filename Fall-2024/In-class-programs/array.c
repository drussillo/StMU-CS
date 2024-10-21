/* C program by Dave Russell. Made on 10/08/2024 for CS1310. Average 5 numbers */
#include <stdio.h>
int myin;
double nums[5];



void read_print_nums(void) {
    for(myin = 0; myin < 5; myin++) {
        printf("Enter a number:  ");
        scanf("%lf", &nums[myin]);
        printf("You entered %lf. \n", nums[myin]);
    }
}



double add_nums(void) {
    double sum = 0;
    
    for(myin = 0; myin < 5; myin++) {
        sum += nums[myin];
    }
    return sum;
}



void min_max(void) {
    double min = nums[0];
    double max = nums[0];
    int min_i = 0;
    int max_i = 0;
    
    for(myin = 1; myin < 5; myin++) {
        if(max < nums[myin]) {
            max = nums[myin];
            max_i = myin;
        }
        if(min > nums[myin]) {
            min = nums[myin];
            min_i = myin;
        }
    }
    printf("Min = %lf at i = %d; Max = %lf at i = %d. \n", min, min_i, max, max_i);
}



void main(void) {
    double summation = 0;
    
    printf("Input 5 numbers to get their average. \n");
    read_print_nums();
    summation = add_nums();
    printf("The sum of your numbers is %lf, and your average is %lf. \n", summation, summation / 5);
    min_max();
}
