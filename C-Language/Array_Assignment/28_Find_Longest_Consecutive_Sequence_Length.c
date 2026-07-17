#include <stdio.h>
#include <stdbool.h>
#define MAX 6
int find_longest_consecutive_sequence_length(int* array, int size);
int main()
{
    int array[MAX] = {0};
    int length = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    length = find_longest_consecutive_sequence_length(array, MAX);
    printf("\nLongest consecutive sequence length of the given array: %d\n", length);
    return 0;
}
int find_longest_consecutive_sequence_length(int* array, int size)
{
    int temp = 0;
    //Sort the Array
    for(int i = 0;i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp; 
            }
        }
    }
    int max_length = 0;
    int length = 0;
    for(int i = 0; i < size; i++)
    {
        length = 1;
        for(int j = i; j < size-1; j++)
        {
            if(array[j+1] - array[j] == 1)
            {
                length++;
            }
            else
                length;
        }
        if(length > max_length)
            max_length = length;
    }
    return max_length;
}