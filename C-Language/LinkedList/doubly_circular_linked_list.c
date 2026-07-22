#include <stdio.h> //For declaration of printf,puts
#include <stdlib.h> //For declaration of malloc,free(),rand(),exit(),EXIT_FAILURE
#include <string.h> //For declaration of memset()
#include <assert.h> //For dfinition of assert macro
#include <stdbool.h>    //  For definition of bool data type 
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
    node_t* prev;
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




// Interface functions declarations

// Function Name: create_list()
// @input: Node
// @output: Address of dynamically allocated instance of struct node (which is a dummy node)
// @behaviour: create_list() function create new instance of singly linked list by allocating
//             a dummy node
int main(void)
{
    list_t* p_list = NULL; 
    status_t status; 
    data_t data; 

    p_list = create_list(); 

    show_list(p_list, "List after creation:"); 

    assert(get_start(p_list, &data) == LIST_EMPTY); 
    assert(get_end(p_list, &data) == LIST_EMPTY); 
    assert(pop_start(p_list, &data) == LIST_EMPTY); 
    assert(pop_end(p_list, &data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 

    for(data = 10; data <= 50; data = data + 10)
    {
        status = insert_start(p_list, data); 
        assert(status == SUCCESS); 
    }

    show_list(p_list, "\nList After inserting five elements at start:"); 

    for(data = 60; data <= 100; data += 10)
    {
        status = insert_end(p_list, data); 
        assert(status == SUCCESS); 
    }

    show_list(p_list, "\nShowing list after inserting at end:"); 

    status = insert_after(p_list, -50, 1000); 
    assert(status == LIST_DATA_NOT_FOUND); 

    status = insert_after(p_list, 10, 1000); 
    assert(status == SUCCESS); 

    show_list(p_list, "\nShowing list after insert_after():"); 

    status = insert_before(p_list, -100, 2000); 
    assert(status == LIST_DATA_NOT_FOUND);

    status = insert_before(p_list, 10, 2000); 
    assert(status == SUCCESS); 

    show_list(p_list, "\nShowing list after insert_before():"); 

    status = get_start(p_list, &data); 
    assert(status == SUCCESS); 
    printf("\nget_start():start_data = %d\n", data); 
    show_list(p_list, "Showing list after get_start():"); 

    status = get_end(p_list, &data); 
    assert(status == SUCCESS); 
    printf("\nget_end():End data = %d\n", data); 
    show_list(p_list, "Showing list after get_end():"); 

    status = pop_start(p_list, &data); 
    assert(status == SUCCESS); 
    printf("\npop_start():Poped start_data = %d\n", data); 
    show_list(p_list, "Showing list after pop_start():"); 

    status = pop_end(p_list, &data); 
    assert(status == SUCCESS); 
    printf("\npop_end():Poped End data = %d\n", data); 
    show_list(p_list, "Showing list after pop_end():"); 
    
    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "\nShowing list after remove_start():"); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "\nShowing list after remove_end():"); 

    status = remove_data(p_list, -100); 
    assert(status == LIST_DATA_NOT_FOUND); 
    show_list(p_list, "\nShowing list after remove_data():");

    status = remove_data(p_list, 2000); 
    assert(status == SUCCESS); 
    show_list(p_list, "\nShowing list after remove_data():"); 

    bool find_status = find(p_list, -100); 
    printf("\nfind_status for -100 in p_list:%d\n", find_status); 

    find_status = find(p_list, 60); 
    printf("\nfind_status for 60 in p_list:%d\n", find_status); 

    bool empty_status = is_list_empty(p_list); 
    printf("\nEmpty status for p_list:%d\n", empty_status);

    len_t list_length = get_list_length(p_list); 
    printf("\nLength of p_list: %d\n", list_length); 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 
    puts("\nThe linked list destroyed successfully"); 

    // Testing  of interlist routines
    list_t* p_list1 = create_list();
    list_t* p_list2 = create_list();

    for(data = 10; data <= 50; data = data + 10)
    {
        status = insert_end(p_list1, data);
        assert(status == SUCCESS);
    }

    for(data = 5; data <= 95; data = data+ 10)
    {
        status = insert_end(p_list2, data);
        assert(status == SUCCESS);
    }
    show_list(p_list1, "\nInitial state of p_list1");
    show_list(p_list2, "\nInitial state of p_list2");

    list_t* p_concat_list = NULL;
    status = concat_lists(p_list1, p_list2, &p_concat_list);
    assert(status == SUCCESS);
    show_list(p_concat_list, "\nConcatenated list of p_list1 & p_list2");
    
    list_t* p_merged_list = NULL;
    status = merge_lists(p_list1, p_list2, &p_merged_list);
    assert(status == SUCCESS);
    show_list(p_merged_list, "\nMerged list of p_list1 & p_list2");
    
    list_t* p_reversed_list1 = NULL;
    status = get_reverse_list(p_list1, &p_reversed_list1);
    assert(status == SUCCESS);
    show_list(p_reversed_list1, "\nReversed version of p_list_1:");

    show_list(p_list2, "\np_list2 before in-place reversal:");
    status = reverse(p_list2);
    show_list(p_list2, "\np_list2 after in-place reversal:");

    status =  append(p_list1, &p_list2);
    assert(status == SUCCESS);
    show_list(p_list1, "\np_list1 after appending p_list2 to it:");

    status = destroy_list(&p_list1);
    assert(status == SUCCESS && p_list1 == NULL);

    puts("\np_list1 destroyed successfully");
    puts("\nDoubly Linked List Testing Succeeded!");

    exit(EXIT_SUCCESS); 
}

list_t* create_list(void)
{
    list_t* new_list = get_node(0);
    new_list->next = new_list;
    new_list->prev = new_list;
    return new_list;
}

//Insert Routines
status_t insert_start(list_t* p_list, data_t new_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    node_t* new_node = get_node(new_data);
    
    new_node->next = p_list->next;
    new_node->prev = p_list;
    if(p_list->next != p_list)
        p_list->next->prev = new_node;
    p_list->next = new_node;
    
    return SUCCESS;
}
status_t insert_end(list_t* p_list, data_t new_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    
    node_t* new_node = get_node(new_data);
    node_t* run = p_list;
    if(p_list->prev != p_list)
        run = p_list->prev;

    new_node->next = run->next;
    run->next = new_node;
    new_node->prev = run;
    p_list->prev = new_node;
    
    return SUCCESS;
}
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data)
{
    if(NULL == p_list)
        return INVALID_LIST;

    node_t* run = p_list->next;
    
    while(run != p_list)
    {    
        if(run->data == existing_data)
            break;
        run = run->next;
    }
    
    if(p_list == run)
        return LIST_DATA_NOT_FOUND;

    node_t* new_node = get_node(new_data);
    new_node->next = run->next;
    new_node->prev = run;
    run->next->prev = new_node;
    run->next = new_node;

    return SUCCESS;
}
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    
    node_t* run = p_list->next;
    while(run != p_list)
    {
        if(run->data == existing_data)
            break;
        run = run->next;
    }
    if(p_list == run)
        return LIST_DATA_NOT_FOUND;
    node_t* new_node = get_node(new_data);
    new_node->next = run;
    new_node->prev = run->prev;
    run->prev->next = new_node;
    run->prev = new_node;

    return SUCCESS;
}

// Get and pop routines
status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(NULL == p_list)
        return INVALID_LIST;

    if(is_list_empty(p_list))
        return LIST_EMPTY;
    
    *p_start_data = p_list->next->data;
    
    return SUCCESS;
}
status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    
    if(is_list_empty(p_list))
        return LIST_EMPTY;
    
    *p_end_data = p_list->prev->data;

    return SUCCESS;
}
status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(is_list_empty(p_list))
        return LIST_EMPTY;
    node_t* removed_node = p_list->next;

    p_list->next = removed_node->next;
    removed_node->next->prev = p_list;
    
    *p_start_data = removed_node->data;
    free(removed_node);
    return SUCCESS;
}
status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(is_list_empty(p_list))
        return LIST_EMPTY;

    node_t* run = p_list->prev;

    run->prev->next = run->next;
    run->next->prev = run->prev;
    
    *p_end_data = run->data;

    free(run);
    return SUCCESS;
}

// Remove routines
status_t remove_start(list_t* p_list)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(is_list_empty(p_list))
        return LIST_EMPTY;
    node_t* removed_node = p_list->next;
    
    p_list->next = removed_node->next;
    removed_node->next->prev = p_list;
    
    free(removed_node);
    return SUCCESS;
}
status_t remove_end(list_t* p_list)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(is_list_empty(p_list))
        return LIST_EMPTY;
    node_t* run = p_list->prev;
    
    run->prev->next = run->next;
    run->next->prev = run->prev;
    
    free(run);
    return SUCCESS;
}
status_t remove_data(list_t* p_list, data_t r_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(is_list_empty(p_list))
        return LIST_EMPTY;

    node_t* run = p_list->next;
    while(run != p_list)
    {
        if(run->data == r_data)
            break;
        run = run->next;
    }
    if(p_list == run)
        return LIST_DATA_NOT_FOUND;
    
    run->prev->next = run->next;
    run->next->prev = run->prev;
    
    free(run);
    return SUCCESS;
}

// Miscellaneous routines
bool find(list_t* p_list, data_t find_data)
{
    if(NULL == p_list)
        return FALSE;
    node_t* run = p_list->next;
    while(run != p_list)
    {
        if(run->data == find_data)
            return TRUE;
        run = run->next;
    }
    return FALSE;
}
bool is_list_empty(list_t* p_list)
{
    if(NULL == p_list)
        return (INVALID_LIST); 

    return (p_list->prev == p_list && p_list->next == p_list); 
}
len_t get_list_length(list_t* p_list)
{
    if(NULL == p_list)
        return -1;
    len_t length = 0;
    node_t* run = p_list->next;
    while(run != p_list)
    {
        length++;
        run = run->next;
    }
    return length;
}
void show_list(list_t* p_list, const char* msg)
{
    if(NULL == p_list)
        return;

    if(msg)
        puts(msg);
    
    printf("[START] <-> ");

    node_t* run = p_list->next;
    while(run != p_list)
    {
        printf("[%d] <-> ", run->data);
        run = run->next;
    }
    printf(" [END]\n");
}

//Interlist and Adcanced Functions
status_t concat_lists(list_t* p_list1, list_t* p_list2, list_t** pp_concatenated_lists)
{
    if(NULL == p_list1 || NULL == p_list2 || NULL == pp_concatenated_lists)
        return INVALID_LIST;
    list_t* p_concatenated_list = create_list();
    node_t* run = p_list1->next;
    status_t status;
    while(run != p_list1)
    {
        status = insert_end(p_concatenated_list, run->data);
        assert(status == SUCCESS);
        run = run->next;
    }
    run = p_list2->next;
    while(run != p_list2)
    {
        status = insert_end(p_concatenated_list, run->data);
        assert(status == SUCCESS);
        run = run->next;
    }
    *pp_concatenated_lists = p_concatenated_list;
    return SUCCESS;
}
status_t append(list_t* p_list1, list_t** pp_list2)
{
    if(NULL == p_list1 || NULL == pp_list2)
        return INVALID_LIST;
    list_t* p_list2 = *pp_list2;
    if(!is_list_empty(p_list2))
    {
        p_list1->prev->next = p_list2->next;
        p_list2->next->prev = p_list1->prev;
        p_list2->prev->next = p_list1;
        p_list1->prev = p_list2->prev;
    }
    free(p_list2);
    *pp_list2 = NULL; 
    
    return SUCCESS;
}
status_t  merge_lists(list_t* p_list1, list_t* p_list2, list_t** pp_merged_list)
{
    if(NULL == p_list1 || NULL == p_list2 || NULL == pp_merged_list)
        return INVALID_LIST;

    list_t* p_merged_list = create_list();

    node_t* run1 = p_list1->next;
    node_t* run2 = p_list2->next;

    status_t status;

    while(TRUE)
    {
        if(p_list1 == run1)
        {
            while(run2 != p_list2)
            {
                status = insert_end(p_merged_list, run2->data);
                assert(status == SUCCESS);
                run2 = run2->next;
            }
            break;
        }
        if(p_list2 == run2)
        {
            while(run1 != p_list1)
            {
                status = insert_end(p_merged_list, run1->data);
                assert(status == SUCCESS);
                run1 = run1->next;
            }
            break;
        }
        if(run1->data <= run2->data)
        {
            status = insert_end(p_merged_list, run1->data);
            assert(status == SUCCESS);
            run1 = run1->next;
        }
        else
        {
            status = insert_end(p_merged_list, run2->data);
            assert(status == SUCCESS);
            run2 = run2->next;
        }
    }
    *pp_merged_list = p_merged_list;
    return SUCCESS;
}
status_t get_reverse_list(list_t* p_list, list_t** pp_reversed_list)
{
    if(NULL == p_list || pp_reversed_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list->next;
    list_t* p_reversed_list = create_list();
    status_t status;

    while(run != p_list)
    {
        status = insert_start(p_reversed_list, run->data);
        assert(status == SUCCESS);
        run = run->next;
    }

    *pp_reversed_list = p_reversed_list;

    return SUCCESS;
}
status_t reverse(list_t* p_list) // check in detail
{
    if(NULL == p_list)
        return INVALID_LIST;

    if(is_list_empty(p_list) || p_list->next->next == p_list)
        return SUCCESS;

    node_t* first_node = p_list->next;
    node_t* run = first_node->next;
    node_t* run_next;

    while(run != p_list)
    {
        run_next = run->next;

        run->next = p_list->next;
        p_list->next->prev = run;
        p_list->next = run;
        run->prev = p_list;

        run = run_next;
    } 
    first_node->next = p_list;
    p_list->prev = first_node;

    return SUCCESS;
}
status_t to_array(list_t* p_list, data_t** pp_array, size_t* p_size)
{
    if(NULL == p_list)
        return INVALID_LIST;

    if(NULL == pp_array)
        return INVALID_ARRAY;

    len_t length = get_list_length(p_list);
    if(!length)
    {
        *pp_array = NULL;
        *p_size = 0;
    }

    data_t* p_array = (data_t*) xmalloc(sizeof(data_t) *  length);
    node_t* run = p_list->next;
    int index = 0;

    while(run != p_list)
    {
        p_array[index++] = run->data;
        run = run->next;
    }
    
    *p_size = length;
    *pp_array = p_array;
    
    return SUCCESS;
}
status_t to_list(data_t* p_array, size_t size, list_t** pp_list)
{
    if(p_array == NULL || size == 0)
    {
        *pp_list = NULL;
        return INVALID_ARRAY;
    }

    list_t* p_list = create_list();
    status_t status;

    for(int i = 0; i < size; i++)
    {
        status = insert_end(p_list, p_array[i]);
        assert(status == SUCCESS);
    }
    *pp_list = p_list;

    return SUCCESS;
}

// Destroy routine
status_t destroy_list(list_t** pp_list)
{
    if(NULL == pp_list)
        return INVALID_LIST;
    list_t* p_list = *pp_list;
    if(!is_list_empty(p_list))
    {
        node_t* run = p_list->next;
        node_t* run_next = p_list;
        while(run != p_list)
        {
            run_next = run->next;
            free(run);
            run = run_next;
        }
    }
    free(p_list);
    *pp_list = NULL;
    return SUCCESS;
}

// Auxilary/ Helper function declarations
node_t* search_node(list_t* p_list, data_t search_data)
{
    if(NULL == p_list)
        return NULL;
    node_t* run = p_list->next;
    while(run != p_list)
    {
        if(run->data == search_data)
            return run;
        run = run->next;
    }
    return run;
}
node_t* get_node(data_t new_data)
{
    node_t* p_new_node = NULL;
    p_new_node = (node_t*)xmalloc(sizeof(node_t));
    p_new_node->next = NULL;
    p_new_node->prev = NULL;
    p_new_node->data = new_data;
    return p_new_node;
}
void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL;
    ptr = malloc(size_in_bytes);
    if(NULL == ptr)
    {
        fprintf(stderr, "fatal error: Memory Alloaction Failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}