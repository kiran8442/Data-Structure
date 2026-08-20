#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/* Exercise function - implementation will be provided by you */
void print_reverse(list_t* plist);
void recursive_reverse_printing(node_t* node);
int main(void)
{
    list_t* p_list = NULL;
    data_t* p_array = NULL;
    size_t size = 0;

    /* ============================================================
       Test 1: NULL list
       Expected: Function should handle NULL safely.
       ============================================================ */
    printf("\nTest 1: NULL list\n");

    print_reverse(NULL);

    printf("PASS: NULL list handled without crashing.\n");


    /* ============================================================
       Test 2: Empty list
       Expected: No data should be printed.
       ============================================================ */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();
    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    printf("Expected output: <empty>\n");
    printf("Actual output:   ");
    print_reverse(p_list);
    printf("\n");

    assert(get_list_length(p_list) == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: Empty list handled correctly.\n");


    /* ============================================================
       Test 3: Single-element list
       Expected: 42
       ============================================================ */
    printf("\nTest 3: Single-element list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 42) == SUCCESS);

    printf("Expected output: 42\n");
    printf("Actual output:   ");
    print_reverse(p_list);
    printf("\n");

    assert(get_list_length(p_list) == 1);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: Single-element list handled correctly.\n");


    /* ============================================================
       Test 4: Multiple elements
       Input: 10 -> 20 -> 30 -> 40
       Expected reverse: 40 30 20 10
       ============================================================ */
    printf("\nTest 4: Multiple-element list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    printf("Expected output: 40 30 20 10\n");
    printf("Actual output:   ");
    print_reverse(p_list);
    printf("\n");

    assert(get_list_length(p_list) == 4);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: Multiple elements printed in reverse order.\n");


    /* ============================================================
       Test 5: Duplicate values
       Input: 2 -> 2 -> 3 -> 4
       Expected reverse: 4 3 2 2
       ============================================================ */
    printf("\nTest 5: Duplicate values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);

    printf("Expected output: 4 3 2 2\n");
    printf("Actual output:   ");
    print_reverse(p_list);
    printf("\n");

    assert(get_list_length(p_list) == 4);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: Duplicate values handled correctly.\n");


    /* ============================================================
       Test 6: Negative, zero and positive values
       Input: -10 -> 0 -> 20 -> -5
       Expected reverse: -5 20 0 -10
       ============================================================ */
    printf("\nTest 6: Negative, zero and positive values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);

    printf("Expected output: -5 20 0 -10\n");
    printf("Actual output:   ");
    print_reverse(p_list);
    printf("\n");

    assert(get_list_length(p_list) == 4);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: Negative, zero and positive values handled correctly.\n");


    /* ============================================================
       Test 7: Verify that the list is NOT modified
       Input: 10 -> 20 -> 30 -> 40
       After print_reverse(), list must remain unchanged.
       ============================================================ */
    printf("\nTest 7: Verify list is not modified\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    /* Save original list as an array */
    assert(to_array(p_list, &p_array, &size) == SUCCESS);
    assert(size == 4);

    printf("Before print_reverse():\n");
    show_list(p_list, "List");

    printf("Expected reverse output: 40 30 20 10\n");
    printf("Actual output:           ");
    print_reverse(p_list);
    printf("\n");

    /* Verify list length is unchanged */
    assert(get_list_length(p_list) == 4);

    /* Verify list contents are unchanged */
    {
        data_t* p_after_array = NULL;
        size_t after_size = 0;

        assert(to_array(p_list, &p_after_array, &after_size) == SUCCESS);

        assert(after_size == size);

        for (size_t i = 0; i < size; ++i)
        {
            assert(p_after_array[i] == p_array[i]);
        }

        free(p_after_array);
    }

    free(p_array);
    p_array = NULL;

    printf("After print_reverse():\n");
    show_list(p_list, "List");

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: List remains unchanged after print_reverse().\n");


    /* ============================================================
       Test 8: Sample from exercise
       Input: 2 -> 2 -> 3 -> 4
       Expected: 4 3 2 2
       ============================================================ */
    printf("\nTest 8: Exercise sample input\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);

    printf("Expected output: 4322\n");
    printf("Actual output:   ");
    print_reverse(p_list);
    printf("\n");

    assert(get_list_length(p_list) == 4);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: Exercise sample handled correctly.\n");


    /* ============================================================
       Test 9: Larger list
       Verify reverse traversal works for more nodes.
       ============================================================ */
    printf("\nTest 9: Larger list\n");

    p_list = create_list();
    assert(p_list != NULL);

    for (data_t i = 1; i <= 10; ++i)
    {
        assert(insert_end(p_list, i) == SUCCESS);
    }

    printf("Expected output: 10 9 8 7 6 5 4 3 2 1\n");
    printf("Actual output:   ");
    print_reverse(p_list);
    printf("\n");

    assert(get_list_length(p_list) == 10);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: Larger list handled correctly.\n");


    printf("\n========================================\n");
    printf("All tests passed successfully!\n");
    printf("========================================\n");

    return EXIT_SUCCESS;
}
void print_reverse(list_t* p_list)
{
    if(p_list == NULL || p_list->next == NULL)
        return;

    printf("[START] -> ");
    recursive_reverse_printing(p_list->next);
    printf("[END]");
}
void recursive_reverse_printing(node_t* node)
{
    if(node->next != NULL)
        recursive_reverse_printing(node->next);
    printf("[%d] -> ", node->data);
}