#include <stdio.h>
#define MAX 10
int remove_duplicate_elements(int *array, int size);
int main()
{
    int array[MAX] = {0};
    int return_size = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("Arr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\nArray After removing duplicate elements:\n");
    return_size = remove_duplicate_elements(Arr,MAX);
    for(int i = 0; i < return_size; i++) {
        printf(" %d ", array[i]);
    }
    return 0;
}
int removeduplicate(int* array, int size){
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++){
            if(array[i] == Arr[j])
                array[j] = 0;
        }
    }
    int index = 0;
    for(int i = 0; i < size; i++) {
        if(array[i] != 0 && array[index] == 0) 
        {
            array[index] = array[i];
            array[i] = 0;
        }
        else if(array[index] != 0) {
            index++;
        }
    }
    return MAX;
}