/* Bubble sort in C: Test */
#include <stdio.h>

int is_sorted(int array[]) {
    int i;
    for(i = 0; i < sizeof(array)-1; i++) {
        if(array[i] > array[i+1]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int nums[] = {1,2,3,4,5,6,7,8};
    printf("%d \n", is_sorted(nums));
    
    return 0;
}
