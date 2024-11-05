/* C Program by Dave Russillo. Made on 11/05/2024 for CS1310. Pass values with an array */
#include <stdio.h>

void print_array(int length, int array[]) {
    int i;
    
    printf("The values in the array length %d are: \n", length);
    for(i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void square_array(int length, int array[]) {
    int i;
    
    for(i = 0; i < length; i++) {
        array[i] = array[i] * array[i];
    }
}

int main(void) {
    int nums[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    
    printf("This program squares an array. \n\n");
    print_array(11, nums);
    square_array(11, nums);
    print_array(11, nums);
    square_array(11, nums);
    print_array(11, nums);
    
    return 0;
}
