#include <stdio.h>
#define MAX 5
double calculate_average(int* array,int size);
int main(){
    int array[MAX] = {0};
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("Arr[%d] : \t", i);
        scanf("%d",&array[i]);
    }
    printf("You have entered array:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("Average of elements fromt he given Array:\t%lf", calculate_average( array, MAX));
    return 0;
}
double calculate_average(int* array,int size){
    int sum = 0; 
    for(int i = 0; i < size; i++)
        sum = sum + array[i];
    return (double)( sum / size);
}
