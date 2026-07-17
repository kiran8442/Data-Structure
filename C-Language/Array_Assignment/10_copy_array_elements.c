#include <stdio.h>
#define MAX 5
void copy_array_elements(const int *source, int size, int *destination);
int main(){
    int source[MAX] = {0};
    int destination[MAX] = {0};
    printf("Enter Element in the Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("source[%d] : \t", i);
        scanf("%d",&source[i]);
    }
    printf("Copying Given Array in the Destination Array:\n");
    copy_array_elements(source, MAX, destination);
    for(int i = 0; i < MAX; i++) {
        printf("\n destination[%d] : %d ",i, destination[i]);
    }
    
    return 0;
}
void copy_array_elements(const int *source, int size, int *destination) {
    for(int i = 0;i < size; i++){
        destination[i] = source[i];
    }
}