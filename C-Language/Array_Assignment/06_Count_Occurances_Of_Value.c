#include <stdio.h>
#define MAX 7
int count_occurrences(int* array, int size, int value);
int main()
{
    int array[MAX] = {0};
    int value = 0;
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("array[%d] : \t", i);
        scanf("%d",&array[i]);
    }
    printf("\nEnter target to check in the Array:\t");
    scanf("%d", &value);
    printf("You have entered array:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\nIn the Above array %d occur %d times", value, count_occurrences(array, MAX, value));
    return 0;
}
int count_occurrences(int* array, int size, int value){
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(array[i] == value)
            count++;
    }
    return count;
}