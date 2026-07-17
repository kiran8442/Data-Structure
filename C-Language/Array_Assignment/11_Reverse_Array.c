#include <stdio.h>
#define MAX 6
void reverse_array(int *array, int size);
int main()
{
    int array[MAX] = {0};
    printf("Enter the Elements in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("array[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\nArray After reverse:\n");
    reverse_array(array,MAX);
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    return 0;
}
void reverse_array(int *array, int size){
    int temp = 0;
    for(int left = 0, right = size - 1; left < right; left++, right--) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
}