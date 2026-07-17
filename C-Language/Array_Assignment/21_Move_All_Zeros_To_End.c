#include <stdio.h>
#define MAX 5
void move_all_zeros_to_end(int* array, int size);
int main()
{
    int array[MAX] = {0};
    int size = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\n After Moving All zeros to the End\n");
    move_all_zeros_to_end(array, MAX);
    for(int i = 0; i < MAX; i++) {
        printf(" %d ",array[i]);
    }
    return 0;
}
void move_all_zeros_to_end(int *array, int size) {
    int insert_index = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] != 0) {
            array[insert_index++] = array[i];
        }
    }

    while (insert_index < size) {
        array[insert_index++] = 0;
    }
}
/*
void move_all_zeros_to_end(int* array, int size){
    int start_index = 0;
    int end_index = 0;
    for(start_index = 0, end_index = size -1; start_index < end_index;)
    {
        if(array[start_index] == 0 && array[end_index] != 0)
        {
            array[start_index] = array[end_index];
            array[end_index] = 0;
        }
        if(array[start_index] != 0)
            start_index++;
        if(array[end_index] == 0)
            end_index--;
    }
}
*/