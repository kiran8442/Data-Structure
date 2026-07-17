#include <stdio.h>
#include <stdbool.h>
#define MAX 8
int find_first_non_repeating_element(int* array, int size);
int main()
{
    int array[MAX] = {0};
    int shifting = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\n%d is the non repeating first element in the array\n",find_first_non_repeating_element(array,MAX));

    return 0;
}
int find_first_non_repeating_element(int* array, int size) {
    bool repeated = false;
    int temp = -1;
    for(int i = 0; i < size; i++)
    {
        temp = array[i];
        repeated = false;
        for(int j = 0; j < size; j++)
        {
            if(temp == array[j] && i != j)
                repeated = true;
        }
        if(!repeated)
            return temp;
    }
    return -1;
}