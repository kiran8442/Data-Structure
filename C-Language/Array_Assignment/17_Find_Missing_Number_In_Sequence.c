#include <stdio.h>
#define MAX 10
int find_missing_number_in_sequence(int* array, int size);
int main()
{
    int array[MAX] = {0};
    int missing_number = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    missing_number = find_missing_number_in_sequence(array, MAX);
    printf("\nMissing number from the above sequence : %d", missing_number);
    return 0;
}
int find_missing_number_in_sequence(int* array, int size){
    for(int i = 1; i < size; i++){
        if(array[i] - array[i-1] != 1) {
            return array[i-1] + 1;
        }
    }
    return -1;
}