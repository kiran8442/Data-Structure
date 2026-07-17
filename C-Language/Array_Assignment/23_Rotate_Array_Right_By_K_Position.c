#include <stdio.h>
#define MAX 5
void rotate_right_by_k(int* array, int size, int k);
int main()
{
    int array[MAX] = {0};
    int k = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr[%d] :\t",i);
        scanf("%d",&array[i]);
    }
    printf("\nGiven Array :\n");
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\nEnter Number of position Array should be shift:\t");
    scanf("%d",&k);
    printf("\nArray After rotating right by %d position:\n",k);
    rotate_right_by_k(array,MAX,k);
    for(int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    return 0;
}
void rotate_right_by_k(int* array, int size, int k) {
    int temp = 0;
    int j;
    k %= size;
    for(int i = 0; i < k; i++) {
        temp = array[size - 1];
        for(j = size - 1; j >= 1; j--) {
            array[j] = array[j-1];
        }
        array[j] = temp;
    }

}