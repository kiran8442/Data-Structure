#include <stdio.h>
#include <stdbool.h>
#define MAX 10
void dutch_national_flag(int* array, int size);
int main()
{
    int array[MAX] = {0};
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    dutch_national_flag(array, MAX);
    printf("\nArray after solved dutch National flag logic:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    return 0;
}
void dutch_national_flag(int* array, int size)
{
    int j = 0;
    int k = size-1;
    int temp = 0;
    for(int i = 0; i < k;)
    {
        if(array[i] == 0)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j++;
        }
        else if(array[j] == 1)
        {
            i++;
        }
        else
        {  
            temp = array[k];
            array[k] = array[j];
            array[j] = temp;
            k--;
        }
    }
}