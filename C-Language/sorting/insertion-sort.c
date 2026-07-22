#include <stdio.h>
#define _CRT_RAND_S
#include <stdlib.h>

#define TRUE 1

//Interface function
void input_array(int* a, size_t N);
void output_array(int* a, size_t N, const char* msg);
void sort(int* a, size_t N);

//Actual sorting function
void insertion_sort(int* array, size_t size);
void insert_at_sorting_position(int* array, size_t size);

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
	insertion_sort(a, N);
}

void insertion_sort(int* array, size_t N)
{
	size_t index = 2;
	while(index <= N)
	{
		insert_at_sorting_position(array, index);
		index++;
	}
}
void insert_at_sorting_position(int* array, size_t size)
{
	int temp = array[size - 1];
	size_t index = size - 2;
	while(index >= 0 && array[index] > temp )
	{
		array[index + 1] = array[index];
		index--;
	}
	array[index + 1] = temp;
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