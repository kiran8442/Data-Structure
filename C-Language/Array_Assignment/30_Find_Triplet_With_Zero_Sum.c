#include <stdio.h>
#include <stdbool.h>
#define MAX 6
int find_triplets_with_sum(int* array, int size, int target);
int main()
{
    int array[MAX] = {0};
    int target = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("Enter the Target number to find out is triplet :\t");
    scanf("%d", &target);
    find_triplets_with_sum(array, MAX, target);
    return 0;
}
int find_triplets_with_sum(int* array, int size, int target) {
    bool repeated = false;
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            for(int k = j+1; k < size; k++){
                if (array[i] + array[j] + array[k] == target) 
                {
                        printf("[ %d, %d, %d]", array[i], array[j], array[k]);
                        count++;
                }
            }
        }
    }
    return count;
}