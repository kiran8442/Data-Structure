#include <stdio.h>
int sum_of_all_elements(const int *array, int size);
#define MAX 5
int main(){
    int array[MAX];
    printf("Enter All Emelents of an Array:\n");
    for(int i = 0; i < MAX; i++){
        printf("Enter Arr[%d] : \t",i);
        scanf("%d",&array[i]);
    }
    printf("You have entered array:");
    for(int i = 0; i < MAX; i++){
        printf(" %d ",array[i]);
    }
    printf("\nSum of all array elements: %d\t", sum_of_all_elements( array, MAX));
    return 0;
}
int sum_of_all_elements(const int *array, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}