#include <stdio.h>
#define MAX 9
int find_maximum_subarray_sum(int* array, int size,int *start_index, int* end_index);
  
int main()
{
    int array[MAX] = {0};
    int start_index = 0, end_index = 0;
    int max_sum;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\nFinding maximum sum of consecutive array:\t");
    max_sum = find_maximum_subarray_sum(array, MAX, &start_index, &end_index);
    printf("\nMaximum Sum is : %d\n",max_sum);
    for(int i = start_index; i <= end_index; i++) {
        printf(" %d ", array[i]);
    }
    return 0;
}
int find_maximum_subarray_sum(int* array, int size,int *start_index, int* end_index){

    //int start_index = 0, end_index = 0;
    int max_sum = 0;
    int final_sum = 0;
    for(int i = 0; i < size; i++) {
        max_sum = 0;
        for(int j = i+1; j < size; j++) {
            max_sum+=array[j];
            if(max_sum > final_sum) {
                *start_index = i+1;
                *end_index = j;
                final_sum = max_sum;
            }
        }
    }
    return final_sum;
}
