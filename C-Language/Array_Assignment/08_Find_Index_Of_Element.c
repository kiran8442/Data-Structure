#include <stdio.h>
#define MAX  7
int find_index_of_element(const int *array, int size, int value);
int main(){
    int array[MAX] = {0};
    int value = 0;
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("array[%d] : \t", i);
        scanf("%d",&array[i]);
    }
    printf("enter element to find the index:\t");
    scanf("%d",&value);
    printf("You have entered array:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("Entered element %d find at %d index in the array\n", value, find_index_of_element(array, MAX, value));
    return 0;
}
int find_index_of_element(const int *array, int size, int value){

    for(int i = 0; i < size; i++){
        if(array[i] == value)
            return i + 1;
    }
    return -1;
}