//Standard C header files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
/*int main(void)
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

    status = remove_data(p_list, 10); 
    assert(status == LIST_DATA_NOT_FOUND); 
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
    puts("\nSingly Linked List Testing Succeeded!\n");

    exit(EXIT_SUCCESS); 
}*/
list_t* create_list(void)
{
    return get_node(0);
}

status_t insert_start(list_t* p_list, data_t new_data)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* new_node = get_node(new_data);
    
    new_node->next = p_list->next;
    p_list->next = new_node;
    
    return SUCCESS;
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list;
    while(run->next != NULL)
    {
        run  = run->next;
    }
    run->next = get_node(new_data);

    return SUCCESS;
}

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data)
{
    if(p_list == NULL)
        return INVALID_LIST;
    
    node_t* existing_node = search_node(p_list, existing_data);
    if(NULL == existing_node)
        return LIST_DATA_NOT_FOUND;

    node_t* new_node = get_node(new_data);
    new_node->next = existing_node->next;
    existing_node->next = new_node;

    return SUCCESS;
}

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data)
{
    if(p_list == NULL)
        return INVALID_LIST;
    if(p_list->next == NULL)
        return LIST_EMPTY;

    node_t* run = p_list->next;
    node_t* run_prev = p_list;
    while(run != NULL)
    {
        if(run->data == existing_data)
            break;
        run_prev = run;
        run = run->next;
    }
    if(NULL == run)
        return LIST_DATA_NOT_FOUND;
    
    node_t* new_node = get_node(new_data);
    new_node->next = run->next;
    run_prev->next = new_node;
    
    return SUCCESS;
}

status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(NULL == p_list->next)
        return LIST_EMPTY;

    *p_start_data = p_list->next->data;
    return SUCCESS;
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(NULL == p_list->next)
        return LIST_EMPTY;

    node_t* run = p_list->next;
    while(run->next != NULL)
    {
        run = run->next;
    }
    *p_end_data = run->data;
    return SUCCESS;
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(NULL == p_list->next)
        return LIST_EMPTY;

    node_t* removed_node = p_list->next;
    
    p_list->next = removed_node->next;
    *p_start_data = removed_node->data;
    free(removed_node);
    
    return SUCCESS;
}
status_t pop_end(list_t* p_list, data_t* p_poped_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(NULL == p_list->next)
        return LIST_EMPTY;

    node_t* run = p_list->next;
    node_t* run_prev = p_list;
    while(run->next != NULL)
    {
        run_prev = run;
        run = run->next;
    }

    run_prev->next = NULL;
    *p_poped_data = run->data;
    free(run);

    return SUCCESS;
}

status_t remove_start(list_t* p_list)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(NULL == p_list->next)
        return LIST_EMPTY;

    node_t* removed_node = p_list->next;
    p_list->next = removed_node->next;
    free(removed_node);

    return SUCCESS;
}

status_t remove_end(list_t* p_list)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(NULL == p_list->next)
        return LIST_EMPTY;

    node_t* run_prev = p_list;
    node_t* run = p_list->next;
    while(run->next != NULL)
    {
        run_prev = run;
        run = run->next;
    }
    run_prev->next = NULL;
    free(run);
    return SUCCESS;
}
status_t remove_data(list_t* p_list, data_t r_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(NULL == p_list->next)
        return LIST_EMPTY;

    node_t* run_prev = p_list;
    node_t* run = p_list->next;
    while(run != NULL)
    {
        if(run->data == r_data)
            break;
        run_prev = run;
        run = run->next;
    }
    if(NULL == run)
        return LIST_DATA_NOT_FOUND;
    run_prev->next = run->next;
    free(run);
    return SUCCESS;
}

bool find(list_t* p_list, data_t find_data)
{
    if(NULL == p_list)
        return INVALID_LIST;
    node_t* run = NULL;
    run = search_node(p_list, find_data);
    return (run!=NULL);
}

bool is_list_empty(list_t* p_list)
{
    if(NULL == p_list)
        return INVALID_LIST;
    return (p_list->next == NULL);
}
len_t get_list_length(list_t* p_list)
{
    if(NULL == p_list)
        return INVALID_LIST;
    node_t* run = p_list->next;
    len_t count = 0;
    while(run != NULL)
    {
        run = run->next;
        count++;
    }
    return count;
}
void show_list(list_t* p_list, const char* msg)
{
    if(NULL == p_list)
        return;
    if(msg)
        puts(msg);
    printf("\n[START] -> ");
    node_t* run = p_list->next;
    while(run != NULL)
    {
        printf("[%d] -> ", run->data);
        run = run->next;
    }
    printf("[END]\n");
}

//Interlist and Adcanced Functions
status_t concat_lists(list_t* p_list1, list_t* p_list2, list_t** pp_concatenated_lists)
{
    if(NULL == p_list1 || NULL == p_list2 || NULL == pp_concatenated_lists)
        return INVALID_LIST;
    list_t* p_concatenated_list = create_list();
    node_t* run = p_list1->next;
    status_t status;
    while(run != NULL)
    {
        status = insert_end(p_concatenated_list, run->data);
        run = run->next;
    }
    run = p_list2->next;
    while(run != NULL)
    {
        status = insert_end(p_concatenated_list, run->data);
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
    node_t* run = p_list1;
    while(run->next != NULL)
    {
        run = run->next;
    }
    run->next = p_list2->next;
    p_list2->next = NULL;
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

    while(1)
    {
        if(run1 == NULL)
        {
            while(run2 != NULL)
            {
                status = insert_end(p_merged_list, run2->data);
                assert(status);
                run2 = run2->next;
            }
            break;
        }
        if(NULL == run2)
        {
            while(run1 != NULL)
            {
                status = insert_end(p_merged_list, run1->data);
                assert(status);
                run1 = run1->next;
            }
            break;
        }
        if(run1->data <= run2->data)
        {
            status = insert_end(p_merged_list, run1->data);
            assert(status);
            run1 = run1->next;
        }
        else
        {
            status = insert_end(p_merged_list, run2->data);
            assert(status);
            run2 = run2->next;
        }
    }
    *pp_merged_list = p_merged_list;
    return SUCCESS;
}
status_t get_reverse_list(list_t* p_list, list_t** pp_reversed_list)
{
    if(NULL == p_list || NULL == pp_reversed_list)
        return INVALID_LIST;
    list_t* p_reversed_list = create_list();
    node_t* run = p_list->next;
    while(run != NULL)
    {
        insert_start(p_reversed_list, run->data);
        run = run->next;
    }
    *pp_reversed_list = p_reversed_list;
    return SUCCESS;
}
status_t reverse(list_t* p_list)
{
    if(NULL == p_list)
        return INVALID_LIST;
    if(p_list->next == NULL)
        return LIST_EMPTY;
    if(p_list->next->next == NULL)
        return SUCCESS;
    node_t* first_node = p_list->next;
    node_t* run = first_node->next;
    node_t* run_next = NULL;

    while(run != NULL)
    {
        run_next = run->next;

        run->next = p_list->next;
        p_list->next = run;

        run = run_next;
    }
    first_node->next = NULL;
    return SUCCESS;
}
status_t to_array(list_t* p_list, data_t** pp_array, size_t* p_size)
{
    if(p_list == NULL || pp_array == NULL)
        return INVALID_LIST;
    len_t length = get_list_length(p_list);
    node_t* run = p_list->next;
    data_t* p_array = xmalloc(length * sizeof(data_t));
    int index = 0;
    while(run != NULL)
    {
        p_array[index++] = run->data;
        run = run->next;
    }
    *p_size = index;
    *pp_array = p_array;
    return SUCCESS;
}
status_t to_list(data_t* p_array, size_t size, list_t** pp_list)
{
    if(NULL == p_array)
        return INVALID_ARRAY;
    list_t* p_list = create_list();
    int index = 0;
    while(index < size)
    {
        insert_end(p_list, p_array[index++]);
    }
    *pp_list = p_list;
    return SUCCESS;
}

status_t destroy_list(list_t** pp_list)
{
    if(NULL == pp_list)
        return INVALID_LIST;
    list_t* p_list = *pp_list;
    if(!is_list_empty(p_list))
    {
        node_t* run = p_list->next;
        node_t* run_next;
        while(run != NULL)
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

node_t* search_node(list_t* p_list, data_t search_data)
{
    node_t* run = NULL;
    if(p_list == NULL)
        return NULL;
    run = p_list->next;
    while(run != NULL)
    {
        if(run->data == search_data)
            return run;
        run = run->next;
    }
    return run;
}

node_t* get_node(data_t new_data)
{
    node_t* new_node = NULL;
    new_node = (node_t*)xmalloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->data = new_data;
    return new_node;
}

void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL;
    ptr = malloc(size_in_bytes);
    if(NULL == ptr)
    {
        fprintf(stderr, "fatal:malloc():Out of Memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}