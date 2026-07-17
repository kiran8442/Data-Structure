#include <stdio.h>
#define MAX 8
void separate_even_and_odd1(int* array, int size);
void separate_even_and_odd2(int* array, int size);
int main()
{
    int array[MAX] = {0};

    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    separate_even_and_odd1(array, MAX);
    printf("\nAfter Separating Even and Odd Number: \n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ",array[i]);
    }
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    separate_even_and_odd2(array, MAX);
    printf("\nAfter Separating Even and Odd Number: \n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ",array[i]);
    }
    
    return 0;
}
void separate_even_and_odd1(int* array, int size) {
    int i = 0, j = 0;
    int temp = 0;
    for(int i = 0; i < size; i++) {
        if((array[i] % 2) == 0 && (array[j] % 2) != 0) 
        {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
        else if((array[j] % 2) == 0) {
            j++;
        }
    }
}
void separate_even_and_odd2(int* array, int size)
{
    int temp = 0;
    for(int i = 0, j = size - 1; (i < size && j >= 0) && i <= j;){
        if((array[i] % 2) != 0 && (array[j]%2) == 0)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        if((array[i] % 2) == 0)
            i++;
        if((array[j] % 2) != 0)
            j--;
    }
}
