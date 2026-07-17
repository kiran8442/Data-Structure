#include <stdio.h>
#define MAX 10
void rotate_left_by_k(int *array, int size, int k);
int main()
{
    int array[MAX] = {0};
    int shifting = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("Enter Number of position Array should be shift:\t");
    scanf("%d",&shifting);
    printf("\nArray After rotating left by %d position:\n",shifting);
    rotate_left_by_k(array, MAX, shifting);
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    return 0;
}
void rotate_left_by_k(int *array, int size, int k) {
    int first = 0;
    int j;
    k = k % size;
    for(int step = 0; step < k; step++) {
        first = array[0];
        for(j = 0; j < size-1; j++) {
            array[j] = array[j+1];
        }
        array[size - 1] = first;
    }
}