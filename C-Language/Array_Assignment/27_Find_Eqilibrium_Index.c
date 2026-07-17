#include <stdio.h>
#include <stdbool.h>
#define MAX 7
int find_equilibrium_index(int* array, int size);
int main()
{
    int array[MAX] = {0};
    int length = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("Arr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    length = find_equilibrium_index(array, MAX);
    if(length == -1)
    {
        printf("\nDid not found Equilibrium Index\n");
    }
    else
    printf("\nEquilibrium Index of the Given Array is: %d\n", length); 
    return 0;
}
int find_equilibrium_index(int* array, int size)
{
    int i = 0;
    int j = 0;
    int Sum1 = 0;
    int Sum2 = 0;
    j = size-1;
    while(i < j)
    {   
        Sum1 = Sum1 + array[i];
        Sum2 = Sum2 + array[j];
        if(Sum1 == Sum2)
            return i+1;
        i++;
        j--;
    }
    return -1;
}