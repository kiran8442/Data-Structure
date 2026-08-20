#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Symbolic constants
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define LIST_DATA_NOT_FOUND -1
#define LIST_EMPTY -2
#define INVALID_LIST            (-3)
#define INVALID_ARRAY   (-4)

//  Typedefs 
typedef int data_t; 
typedef int status_t; 
typedef int len_t; 
typedef struct node node_t; 
typedef node_t list_t; 

//  Data layout definitions 
struct node 
{
    data_t data; 
    node_t* next; 
}; 

// Interface functions declarations

// Function Name: create_list()
// @input: Node
// @output: Address of dynamically allocated instance of struct node (which is a dummy node)
// @behaviour: create_list() function create new instance of singly linked list by allocating
//             a dummy node
list_t* create_list(void);

//Insert Routines
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data);

// Get and pop routines
status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

// Remove routines
status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

// Miscellaneous routines
bool find(list_t* p_list, data_t find_data);
bool is_list_empty(list_t* p_list);
len_t get_list_length(list_t* p_list);
void show_list(list_t* p_list, const char* msg);

//Interlist and Adcanced Functions
status_t concat_lists(list_t* p_list1, list_t* p_list2, list_t** pp_concatenated_lists);
status_t append(list_t* p_list1, list_t** pp_list2);
status_t  merge_lists(list_t* p_list1, list_t* p_list2, list_t** pp_merged_list);
status_t get_reverse_list(list_t* p_list, list_t** pp_reversed_list);
status_t reverse(list_t* p_list);
status_t to_array(list_t* p_list, data_t** pp_array, size_t* p_size);
status_t to_list(data_t* p_array, size_t size, list_t** pp_list);

// Destroy routine
status_t destroy_list(list_t** pp_list);

// Auxilary/ Helper function declarations
node_t* search_node(list_t* p_list, data_t search_data);
node_t* get_node(data_t new_data);
void* xmalloc(size_t size_in_bytes);