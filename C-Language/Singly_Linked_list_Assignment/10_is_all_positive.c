#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "list.h"

/*
 * Exercise 10:
 * Check All Positive
 *
 * The implementation of is_all_positive() must be provided separately.
 */
status_t is_all_positive(list_t* plist);

int main(void)
{
    list_t* p_list = NULL;
    status_t result;

    /*
     * Test 1: NULL list
     *
     * There are no elements to violate the condition.
     * This is treated the same as an empty list.
     */
    printf("\nTest 1: NULL list\n");

    result = is_all_positive(NULL);

    printf("Expected: %d\n", INVALID_LIST);
    printf("Actual:   %d\n", result);

    assert(result == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * Explicit requirement:
     * An empty list should return TRUE.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    result = is_all_positive(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single positive element
     *
     * List: [10]
     *
     * 10 > 0, so result should be TRUE.
     */
    printf("\nTest 3: Single positive element\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single zero
     *
     * List: [0]
     *
     * Zero is NOT positive.
     */
    printf("\nTest 4: Single zero\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 0) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Single negative element
     *
     * List: [-10]
     *
     * Negative value is NOT positive.
     */
    printf("\nTest 5: Single negative element\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, -10) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Multiple positive elements
     *
     * List: [10]->[20]->[30]->[40]
     *
     * Every element is positive.
     */
    printf("\nTest 6: Multiple positive elements\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Negative value in the first position
     *
     * List: [-10]->[20]->[30]->[40]
     *
     * The first element violates the condition.
     */
    printf("\nTest 7: Negative value at first position\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Zero in the middle
     *
     * List: [10]->[20]->[0]->[40]
     *
     * Zero is not positive.
     */
    printf("\nTest 8: Zero in the middle\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: Negative value at the last position
     *
     * List: [10]->[20]->[30]->[-40]
     *
     * Last element violates the condition.
     */
    printf("\nTest 9: Negative value at last position\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, -40) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: Duplicate positive values
     *
     * List: [10]->[10]->[10]->[20]->[20]
     *
     * All elements are positive.
     */
    printf("\nTest 10: Duplicate positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: Positive, zero, and negative values
     *
     * List: [10]->[20]->[0]->[30]->[-5]
     *
     * Presence of either zero or a negative value must result in FALSE.
     */
    printf("\nTest 11: Positive, zero, and negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: Large positive values
     *
     * Verify that large valid positive values are accepted.
     */
    printf("\nTest 12: Large positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MAX) == SUCCESS);
    assert(insert_end(p_list, 100000) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: Smallest negative value
     *
     * INT_MIN is negative and therefore must make the result FALSE.
     */
    printf("\nTest 13: INT_MIN\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: Boundary value 1
     *
     * 1 is the smallest positive integer.
     */
    printf("\nTest 14: Smallest positive value\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);

    result = is_all_positive(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 15: Verify the list is not modified
     *
     * Calling is_all_positive() should only inspect the list.
     */
    printf("\nTest 15: List remains unchanged\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    result = is_all_positive(p_list);

    assert(result == TRUE);

    assert(get_list_length(p_list) == 3);

    data_t start_data;
    data_t end_data;

    assert(get_start(p_list, &start_data) == SUCCESS);
    assert(get_end(p_list, &end_data) == SUCCESS);

    assert(start_data == 10);
    assert(end_data == 30);

    printf("List remains unchanged after function call.\n");

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
status_t is_all_positive(list_t* p_list)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list->next;
    
    while(run != NULL)
    {
        if(run->data <= 0)
            return FALSE;
        run = run->next;
    }
    return TRUE;
}