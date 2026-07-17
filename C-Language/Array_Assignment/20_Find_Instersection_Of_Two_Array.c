#include <stdio.h>
#include <stdbool.h>
#define MAX 5
int find_intersection_of_two_arrays(const int *first, int first_size, const int *second, int second_size, int *output);
int main()
{
    int array1[MAX] = {0};
    int array2[MAX] = {0};
    int destination[MAX] = {0};
    int size = 0;
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr1[%d] :\t",i);
        scanf("%d",&array1[i]);
    }
    printf("Enter the Elements in the Array:\t");
    for(int i = 0; i < MAX; i++) {
        printf("\nArr2[%d] :\t",i);
        scanf("%d",&array2[i]);
    }
    size = find_intersection_of_two_arrays(array1,MAX,array2,MAX,destination);
    printf("\nIntersection of above two arrays:\n");
    for(int i = 0; i < size; i++) {
        printf(" %d ",destination[i]);
    }
    return 0;
}
int find_intersection_of_two_arrays(const int *first, int first_size, const int *second, int second_size, int *output) {
    int count = 0;

    for (int i = 0; i < first_size; i++) {
        bool exists_in_second = false;
        bool already_added = false;

        for (int j = 0; j < second_size; j++) {
            if (first[i] == second[j]) {
                exists_in_second = true;
                break;
            }
        }

        for (int j = 0; j < count; j++) {
            if (output[j] == first[i]) {
                already_added = true;
                break;
            }
        }

        if (exists_in_second && !already_added) {
            output[count++] = first[i];
        }
    }

    return count;
}

/*
int find_intersection_of_two_arrays(const int *first, int first_size, const int *second, int second_size, int *output)
{
    int index = 0;
    int i = 0;
    int j = 0;
    for(i = 0; i < first_size; i++){
        for(j = 0; j < second_size; j++){
            if(first[i] == second[j]){
                output[index++] = first[i];
            }
        }
    }
    // Remove Duplicated element from the OutputArray Array
    for(i = 0; i < index; i++)
    {
        for(j = 0; j < index; j++)
        {
            if(output[i] == output[j] && i != j)
                output[j] = 0;
        }
    }

    //Move All Zeros to End
    i = 0;
    j = index -1;
    while(i < j)
    {
        if(output[i] == 0 && output[j] != 0)
        {
            output[i] = output[j];
            output[j] = 0;
        }
        if(output[i] != 0)
            i++;
        if(output[j] == 0)
            j--;
    }
    return i;
}*/