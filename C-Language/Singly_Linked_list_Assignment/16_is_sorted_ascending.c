#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/* Exercise function - implementation will be provided separately */
status_t is_sorted_ascending(list_t* plist);

int main(void)
{
    list_t* p_list = NULL;
    data_t* p_array = NULL;
    size_t size = 0;

    /* ============================================================
       Test 1: NULL list
       Expected: TRUE
       ============================================================ */
    printf("\nTest 1: NULL list\n");

    status_t result = is_sorted_ascending(NULL);

    printf("Expected: %d\n", INVALID_LIST);
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == INVALID_LIST);

    printf("PASS\n");


    /* ============================================================
       Test 2: Empty list
       Expected: TRUE
       ============================================================ */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();
    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    result = is_sorted_ascending(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 3: Single-element list
       Expected: TRUE
       ============================================================ */
    printf("\nTest 3: Single-element list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List: [50]\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 4: Strictly increasing list
       Expected: TRUE
       ============================================================ */
    printf("\nTest 4: Strictly increasing list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List: 10 -> 20 -> 30 -> 40 -> 50\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 5: Duplicate/equal values
       Non-decreasing means equal adjacent values are allowed.
       Expected: TRUE
       ============================================================ */
    printf("\nTest 5: Duplicate/equal values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List: 10 -> 20 -> 20 -> 20 -> 30\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 6: Descending pair at the beginning
       Expected: FALSE
       ============================================================ */
    printf("\nTest 6: Descending pair at beginning\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List: 30 -> 20 -> 40 -> 50\n");
    printf("Expected: FALSE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == FALSE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 7: Descending pair in the middle
       Expected: FALSE
       ============================================================ */
    printf("\nTest 7: Descending pair in the middle\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List: 10 -> 20 -> 40 -> 30 -> 50\n");
    printf("Expected: FALSE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == FALSE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 8: Descending pair at the end
       Expected: FALSE
       ============================================================ */
    printf("\nTest 8: Descending pair at end\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 35) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List: 10 -> 20 -> 30 -> 40 -> 35\n");
    printf("Expected: FALSE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == FALSE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 9: Negative, zero and positive values
       Expected: TRUE
       ============================================================ */
    printf("\nTest 9: Negative, zero and positive values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List: -20 -> -10 -> 0 -> 10 -> 20\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 10: All equal values
       Expected: TRUE
       ============================================================ */
    printf("\nTest 10: All equal values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List: 25 -> 25 -> 25 -> 25\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Test 11: Verify list is not modified
       print_reverse-style modification is not expected here.
       The function should only check the ordering.
       ============================================================ */
    printf("\nTest 11: Verify list is not modified\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    /* Save original contents */
    assert(to_array(p_list, &p_array, &size) == SUCCESS);
    assert(size == 4);

    result = is_sorted_ascending(p_list);

    assert(result == TRUE);
    assert(get_list_length(p_list) == 4);

    /* Compare contents after function call */
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

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS: List contents remain unchanged.\n");


    /* ============================================================
       Test 12: Large/small values
       Expected: TRUE
       ============================================================ */
    printf("\nTest 12: Boundary values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, (data_t)-1000000) == SUCCESS);
    assert(insert_end(p_list, (data_t)-100) == SUCCESS);
    assert(insert_end(p_list, (data_t)0) == SUCCESS);
    assert(insert_end(p_list, (data_t)100) == SUCCESS);
    assert(insert_end(p_list, (data_t)1000000) == SUCCESS);

    result = is_sorted_ascending(p_list);

    printf("List contains small, zero and large values.\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("PASS\n");


    /* ============================================================
       Final result
       ============================================================ */
    printf("\n========================================\n");
    printf("All tests passed successfully!\n");
    printf("========================================\n");

    return EXIT_SUCCESS;
}

status_t is_sorted_ascending(list_t* p_list)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list->next;
    data_t prev_data = INT_MIN;
    while(run != NULL)
    {
        if(prev_data > run->data)
            return FALSE;
        prev_data = run->data;
        run = run->next;
    }
    return TRUE;
}