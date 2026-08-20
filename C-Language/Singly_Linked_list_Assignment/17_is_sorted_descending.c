#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/* Exercise function declaration */
status_t is_sorted_descending(list_t* p_list);

int main(void)
{
    list_t* p_list = NULL;
    status_t result;

    /*
     * Test 1: NULL list
     *
     * A NULL list is an invalid list. For defensive handling,
     * expect FALSE.
     */
    printf("Test 1: NULL list\n");

    result = is_sorted_descending(NULL);

    printf("Expected: %d\n", INVALID_LIST);
    printf("Actual:   %d\n", INVALID_LIST);

    assert(result == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * The exercise explicitly states that an empty list
     * is considered sorted.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();
    assert(p_list != NULL);

    result = is_sorted_descending(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 3: Single-element list
     *
     * A single-element list is explicitly considered sorted.
     */
    printf("\nTest 3: Single-element list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 42) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [42]\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 4: Strictly descending positive values
     *
     * [50]->[40]->[30]->[20]->[10]
     */
    printf("\nTest 4: Strictly descending positive values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [50]->[40]->[30]->[20]->[10]\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 5: Descending list with duplicate values
     *
     * Non-increasing order allows equal adjacent values.
     *
     * [50]->[40]->[40]->[30]->[30]->[10]
     */
    printf("\nTest 5: Descending list with duplicates\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [50]->[40]->[40]->[30]->[30]->[10]\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 6: All elements equal
     *
     * [25]->[25]->[25]->[25]
     *
     * Equal values satisfy non-increasing order.
     */
    printf("\nTest 6: All elements equal\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [25]->[25]->[25]->[25]\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 7: Descending values containing zero and negative values
     *
     * [10]->[5]->[0]->[-5]->[-10]
     */
    printf("\nTest 7: Descending values with zero and negatives\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [10]->[5]->[0]->[-5]->[-10]\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 8: Ascending list
     *
     * [10]->[20]->[30]->[40]
     *
     * This is not descending.
     */
    printf("\nTest 8: Ascending list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [10]->[20]->[30]->[40]\n");
    printf("Expected: FALSE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == FALSE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 9: One ordering violation in the middle
     *
     * [50]->[40]->[45]->[30]
     *
     * 45 comes after 40, so descending order is violated.
     */
    printf("\nTest 9: Single ordering violation\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 45) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [50]->[40]->[45]->[30]\n");
    printf("Expected: FALSE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == FALSE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 10: Violation at the beginning
     *
     * [40]->[50]->[30]
     *
     * The first pair already violates descending order.
     */
    printf("\nTest 10: Violation at the beginning\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [40]->[50]->[30]\n");
    printf("Expected: FALSE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == FALSE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 11: Violation at the end
     *
     * [50]->[40]->[30]->[35]
     *
     * The last pair violates descending order.
     */
    printf("\nTest 11: Violation at the end\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 35) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [50]->[40]->[30]->[35]\n");
    printf("Expected: FALSE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == FALSE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 12: Large/small values
     *
     * No arithmetic is performed by the exercise, so these values
     * are safe as long as they are representable by data_t.
     */
    printf("\nTest 12: Large/small values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 1000000) == SUCCESS);
    assert(insert_end(p_list, 500000) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -500000) == SUCCESS);
    assert(insert_end(p_list, -1000000) == SUCCESS);

    result = is_sorted_descending(p_list);

    printf("List: [1000000]->[500000]->[0]->[-500000]->[-1000000]\n");
    printf("Expected: TRUE\n");
    printf("Actual:   %s\n", result == TRUE ? "TRUE" : "FALSE");

    assert(result == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}

status_t is_sorted_descending(list_t* p_list)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list->next;
    data_t prev_data = INT_MAX;
    if(run != NULL)
        prev_data = run->data;
    while(run != NULL)
    {
        if(prev_data < run->data)
            return FALSE;
        prev_data = run->data;
        run = run->next;
    }
    return TRUE;
}