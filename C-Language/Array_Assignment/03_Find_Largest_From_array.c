#include <stdio.h>
#define MAX 5

int find_largest_element(const int *array, int size);
int main(){
    int array[MAX] = {0};
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("Arr[%d] : \t", i);
        scanf("%d",&array[i]);
    }
    printf("You have entered array:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("Largest element from the above array:\t%d",find_largest_element(array,MAX));
    return 0;
}
int find_largest_element(const int *array, int size) {
    int largest = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }

    return largest;
}
