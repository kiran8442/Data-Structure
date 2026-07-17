#include <stdio.h>

#define MAX 5
int find_smallest_element(const int *array, int size);
int main()
{
    int array[MAX] = {0};
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] : \t", i);
        scanf("%d",&array[i]);
    }
    printf("You have entered array:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\nSmallest element from the above array:\t%d",find_smallest_element(array,MAX));
    return 0;
}
int find_smallest_element(const int *array, int size) {
    int smallest = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }

    return smallest;
}