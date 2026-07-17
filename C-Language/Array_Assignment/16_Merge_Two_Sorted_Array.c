#include <stdio.h>
#define MAX 10
void MergeSortedArray(int* first, int first_size, int* second, int second_size, int* output);
int main()
{
    int array1[] = {1, 3, 5, 7, 9};
    int array2[] = {0, 2, 4, 6, 8};
    int merged_array[MAX] = {0};
    
    printf("\nGiven Array1 :\n");
    for(int i = 0; i < 5; i++) {
        printf(" %d ", array1[i]);
    }
    printf("\nGiven Array2 :\n");
    for(int i = 0; i < 5; i++) {
        printf(" %d ", array2[i]);
    }
    MergeSortedArray(array1, 5, array2, 5, merged_array);
    printf("\nAfter Merging Above Two Sorted Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", merged_array[i]);
    }
    return 0;
}
void MergeSortedArray(int* first, int first_size, int* second, int second_size, int* output)
{
    int i = 0, j = 0, index = 0;
    while(i < first_size && j < second_size)
    {
        if(first[i] > second[j])
            output[index++] = second[j++];
        else
            output[index++] = first[i++];
    }

    while( i < first_size)
        output[index++] = first[i++];

    while( j < second_size)
        output[index++] = second[j++];
}
