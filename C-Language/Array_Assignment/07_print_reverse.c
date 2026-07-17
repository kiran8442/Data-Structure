#include <stdio.h>
#define MAX 5
void print_reverse_array(const int *array, int size);
int main()
{
    int array[MAX] = {0};
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("\narray[%d] : \t", i);
        scanf("%d",&array[i]);
    }
    printf("You have entered array:\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\nPrint Array in rever order:\n");
    print_reverse_array(array, MAX);
    return 0;
}
void print_reverse_array(const int *array, int size) {
    for(int i = size - 1; i >= 0; i--){
        printf(" %d ",array[i]);
    }
}