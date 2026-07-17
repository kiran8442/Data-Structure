#include <stdio.h>  
#define MAX 7
int count_even_numbers(const int *array, int size);

int main(){
    int array[MAX] = {0};
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("rray[%d] : \t", i);
        scanf("%d",&array[i]);
    }
    printf("You have entered array:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("Number of even number from the given Array:\t %d", count_even_numbers(array,MAX));

    return 0;
}
int count_even_numbers(const int *array, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            count++;
        }
    }

    return count;
}