#include<stdio.h>
#define MAX 7
#define NOT_FOUND 0
int element_exists(int* array, int size, int value);
int main()
{
    int array[MAX] = {0};
    int value = 0;
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("Arr[%d] : \t", i);
        scanf("%d",&array[i]);
    }
    printf("\nEnter target to check in the Array:\t");
    scanf("%d", &value);
    printf("You have entered array:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\nIn the Above array target %d ", value);
    if(element_exists(array, MAX, value)){
        printf("is found\n");
    }
    else
        printf("is not found\n");
    return 0;
}
int element_exists(int* array, int size, int value) {
    for(int i = 0; i < size; i++){
        if(array[i] == value)
            return i;
    }
    return NOT_FOUND; 
}