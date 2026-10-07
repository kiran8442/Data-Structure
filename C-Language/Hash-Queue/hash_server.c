#include <stdio.h>
#include <assert.h>
#include "hash.h"

size_t hash(hkey_t key, size_t bucket_size)
{
    return (key % bucket_size);
}
/*Hash Table Interface*/
hashq_t* create_hashq(size_t bucket_size)
{
    hashq_t* p_hashq = xmalloc(sizeof(hashq_t));
    p_hashq->pp_list_arr = (list_t**)xmalloc(sizeof(list_t*) * bucket_size);
    p_hashq->bucket_size = bucket_size;
    for(int i = 0; i < p_hashq->bucket_size; i++)
        p_hashq->pp_list_arr[i] = NULL;
    return p_hashq;
}
status_t add_key(hashq_t* p_hashq, hkey_t key)
{
    if(p_hashq == NULL)
        return INVALID_LIST;
    size_t hash_key = hash(key, p_hashq->bucket_size);

    status_t status;
    list_t** pp_list = p_hashq->pp_list_arr;
    status = insert_end(&(pp_list[hash_key]), key);

    return status;
}
status_t remove_key(hashq_t* p_hashq, hkey_t key)
{
    if(p_hashq == NULL)
        return INVALID_LIST;
    size_t hash_key = hash(key, p_hashq->bucket_size);
    status_t status;
    status = remove_data(&(p_hashq->pp_list_arr[hash_key]), key);
    return status;
}
status_t search_key(hashq_t* p_hashq, hkey_t key)
{
    if(p_hashq == NULL)
        return INVALID_LIST;
    size_t hash_key = hash(key, p_hashq->bucket_size);
    status_t status;
    status = search_data(p_hashq->pp_list_arr[hash_key], key);
    return status;
}
void hash_stat(hashq_t* p_hashq)
{
    if(p_hashq == NULL)
        return;
    for(int i = 0; i < p_hashq->bucket_size; i++)
    {
        printf("\n[%d]    <->\t", i);
        show_list(p_hashq->pp_list_arr[i]);
    }
    printf("\n\n");
}
status_t destroy_hashq(hashq_t** pp_hashq)
{
    hashq_t* p_hashq = *pp_hashq;
    if(pp_hashq == NULL || p_hashq == NULL)
        return INVALID_LIST;
    for(int i = 0; i < p_hashq->bucket_size; i++)
    {
        status_t status;
        status = destroy_list(&(p_hashq->pp_list_arr[i]));
        assert(status == SUCCESS);
    }
    free(p_hashq->pp_list_arr);
    p_hashq->pp_list_arr = NULL;
    p_hashq->bucket_size = 0;
    free(p_hashq);
    *pp_hashq = NULL;
    return SUCCESS;
}

/*Internal List Routines (DLL chains)*/
void Display(list_t* p_list)
{
    if(p_list == NULL)
        return;
    printf("[START]-> ");
    node_t* run = p_list;
    while(run != NULL)
    {
        printf("[%d]-> ",run->key);
        run = run->next;
    }
    printf("[END]");
    return;
}
status_t insert_end(list_t** pp_list, hkey_t key)
{

    if(pp_list == NULL)
        return INVALID_LIST;

    list_t* p_list = *pp_list;
    if(p_list == NULL)
    {
        *pp_list = get_node(key);
        return SUCCESS;
    }

    node_t* run = p_list;
    while(run->next != NULL)
    {
        run = run->next;
    }
    node_t* new_node = get_node(key);
    new_node->prev = run;
    run->next = new_node;
    return SUCCESS;
}
status_t remove_data(list_t** p_list, hkey_t key)
{
    node_t* run = *p_list;
    while(run != NULL)
    {
        if(run->key == key)
        {
            run->prev->next = run->next;
            if(run->next != NULL)
                run->next->prev = run->prev;
            free(run);
            return SUCCESS;
        }
        run = run->next;
    }
    return LIST_DATA_NOT_FOUND;
}
status_t search_data(list_t* p_list, hkey_t key)
{
    node_t* run = p_list;
    while(run != NULL)
    {
        if(run->key == key)
            return SUCCESS;
        run = run->next;
    }
    return LIST_DATA_NOT_FOUND;
}
node_t* search_node(list_t* p_list, hkey_t key)
{
    node_t* run = p_list;
    while(run != NULL)
    {
        if(run->key == key)
            return run;
        run = run->next;
    }
    return NULL;
}
len_t get_list_length(list_t* p_list)
{
    node_t* run = p_list;
    len_t count = 0;
    while(run != NULL)
    {
        run = run->next;
        count++;
    }
    return count;
}
void show_list(list_t* p_list)
{
    if(p_list == NULL)
        return;
    node_t* run = p_list;
    while(run != NULL)
    {
        printf("<-|%d|-> ",run->key);
        run = run->next;
    }
}
status_t destroy_list(list_t** pp_list)
{
    if(pp_list == NULL || *pp_list == NULL)
        return LIST_EMPTY;
    node_t* run = *pp_list;
    node_t* run_next = *pp_list;
    while(run != NULL)
    {
        run_next = run->next;
        free(run);
        run = run_next;
    }
    *pp_list = NULL;
    return SUCCESS;
}
node_t* get_node(hkey_t key)
{

    node_t* new_node = (node_t*)xmalloc(sizeof(node_t));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->key = key;

    return new_node;
}
void* xmalloc(size_t nr_bytes)
{
    void* ptr = NULL;
    ptr = malloc(nr_bytes);
    if(ptr == NULL)
    {
        fprintf(stderr, "Memory Allocation Failed\n");
        return NULL;
    }
    return ptr;
}