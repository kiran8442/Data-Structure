#include <stdio.h>
#define MAX 8
int find_majority_element(int* array, int size);
int main()
{
    int array[MAX] = {0};
    int size = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\n From Above Array [ %d ] Element is Occur majority times\n",find_majority_element(array, MAX));
    return 0;
}
int find_majority_element(int* array, int size){
    int MaxCount = 0;
    int Count = 0;
    int majority_element = 0;
    for(int i = 0; i < size; i++){
        Count = 0;
        for(int j = 0; j < size; j++){
            if(array[i] == array[j])
                Count++;
        }
        if(Count > MaxCount)
            majority_element = array[i];
    }
    return majority_element;
}