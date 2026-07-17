#include <stdio.h>
#define MAX 10
int find_all_pairs_with_sum(int* array, int size, int target);
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
    printf("Enter Number of Sum to get its pairs:\t");
    scanf("%d",&target);
    find_all_pairs_with_sum(array, MAX, target);
    return 0;
}
int find_all_pairs_with_sum(int* array, int size, int target){
    int count = 0;
    for(int i = 0; i < size; i++ )
    {
        for(int j = i+1; j < size; j++){
            if(array[i] + array[j] == target)
            {
                printf("( %d, %d),", array[i], array[j]);
                count++;
            }
        }
    }
    return count;
}