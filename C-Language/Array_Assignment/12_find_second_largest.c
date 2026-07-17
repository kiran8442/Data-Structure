#include <stdio.h>
#define MAX 5
int find_second_largest(int *array, int size);
int main()
{
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
    printf("Second Largest  element from the above array:\t%d",find_second_largest( array, MAX));
    return 0;
}
int find_second_largest(const int *array, int size){
    int largest = 0;
    int second_largest = 0;
    largest = array[0];
    for(int i = 0; i < size; i++){
        
        if(largest < array[i]){
            second_largest = largest;
            largest = array[i];
        }
    }
    return second_largest;
}