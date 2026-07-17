#include <stdio.h>
#include <stdbool.h>
#define MAX 5
bool is_array_sorted(const int *array, int size);
int main()
{
    int array[MAX] = {0};
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    if(is_array_sorted(array, MAX))
    {
        printf("\nGiven Array is Sorted!\n");
    }
    else{
        printf("\nGiven Array is not Sorted!\n");
    }
    return 0;
}
bool is_array_sorted(const int *array, int size){
    for(int i = 0; i < size - 1; i++) {
        if(array[i] > array[i+1])
            return false;
    }
    return true;
}