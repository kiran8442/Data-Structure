#include <stdio.h>
#include <stdbool.h>
#define MAX 6
void rearrange_array_in_wave_form(int* array, int size);
  
int main()
{
    int array[MAX] = {0};

    int max_sum;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    rearrange_array_in_wave_form(array, MAX);
    printf("\nAfter ReArranging Array in waveForm:\t");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    return 0;
}
void rearrange_array_in_wave_form(int* array, int size) {
    int temp = 0;
    bool rearranged = true;
    for(int i = 0; i < size; i++) {
        rearranged = true;
        for(int j = 0; j < size-1; j++){
            if(j%2 == 0 && array[j] < array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                rearranged = false;
            }
            if(j%2 != 0 && array[j] > array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                rearranged = false;
            }
        }
        if(rearranged)
            break;
    }
}
