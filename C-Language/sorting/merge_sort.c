#include <stdio.h>
#define _CRT_RAND_S
#include <stdlib.h>

#define TRUE 1

//Interface function
void input_array(int* a, size_t N);
void output_array(int* a, size_t N, const char* msg);
void sort(int* a, size_t N);

//Actual sorting function
void merge_sort(int* array, size_t start, size_t end);
void merge(int* array, size_t start, size_t mid, size_t end);

//Helper function
void* xmalloc(size_t size);

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage Error: %s number_of_elements", argv[0]);
		exit(EXIT_FAILURE);
	}
	time_t t_start, t_end, t_delta;
	size_t N = atoi(argv[1]);
	int* array = (int*)xmalloc(N * sizeof(int));

	input_array(array, N);
	output_array(array, N, " Array before Sorting: ");

	t_start = time(0);

	sort(array, N);

	t_end = time(0);

	output_array(array, N, " Array after Sorting: ");
	
	t_delta = t_end - t_start;
	
	printf("Physical  Time required: %lld", t_delta);
	
	free(array);
	array = NULL;
	return 0;
}

//Interface function
void input_array(int* array, size_t N)
{
	int num;
	for(int i = 0; i < N; i++)
	{
		rand_s(&num);
		array[i] = num;
	}
}
void output_array(int* array, size_t N, const char* msg)
{
	if(msg)
		puts(msg);
	for(int i = 0; i < N; i++)
		printf("a[%d]: %d\n", i, array[i]);
}
void sort(int* a, size_t N)
{
	merge_sort(a, 0, N - 1);
}
//Actual sorting function
void merge_sort(int* array, size_t start, size_t end)
{
    if(start < end)
    {
        size_t mid = (end + start)/2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end); 
    }
}
void merge(int* array, size_t start, size_t mid, size_t end)
{
    size_t length = end - start + 1;
    int* temp_array = xmalloc(sizeof(int) * length);

    size_t i = start;
    size_t j = mid + 1;
    size_t k = 0;
    while( i <= mid && j <= end)
    {
        if(array[i] < array[j])
            temp_array[k++] = array[i++];
        else
            temp_array[k++] = array[j++];
    }
    while(i <= mid)
        temp_array[k++] = array[i++];

    while(j <= end)
        temp_array[k++] = array[j++];

    for(i = 0; i < length; i++)
        array[start + i] = temp_array[i];
    
    free(temp_array);
    temp_array = NULL;
}

//Helper function
void* xmalloc(size_t size)
{
	void* ptr = NULL;
	ptr = malloc(size);
	if(NULL == ptr)
	{
		fprintf(stderr, "\nmalloc(): fatal error: Out of memory");
		return NULL;
	}
	return ptr;
}