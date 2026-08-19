#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
 * Exercise 11:
 * Check All Negative
 *
 * Implementation must be provided separately.
 */
status_t is_all_negative(list_t* plist);

int main(void)
{
    list_t* p_list = NULL;
    status_t result;

    /*
     * Test 1: NULL list
     *
     * No elements violate the condition.
     * Treat NULL the same as an empty list.
     */
    printf("\nTest 1: NULL list\n");

    result = is_all_negative(NULL);

    printf("Expected: %d\n", INVALID_LIST);
    printf("Actual:   %d\n", INVALID_LIST);

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

    result = is_all_negative(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single negative value
     *
     * List: [-10]
     */
    printf("\nTest 3: Single negative value\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, -10) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single zero
     *
     * Zero is NOT negative.
     */
    printf("\nTest 4: Single zero\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 0) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Single positive value
     *
     * Positive value is NOT negative.
     */
    printf("\nTest 5: Single positive value\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Multiple negative values
     *
     * List: [-5]->[-3]->[-8]
     *
     * This matches the exercise example.
     */
    printf("\nTest 6: Multiple negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -3) == SUCCESS);
    assert(insert_end(p_list, -8) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Positive value at the beginning
     *
     * List: [10]->[-5]->[-8]
     */
    printf("\nTest 7: Positive value at first position\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -8) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Zero in the middle
     *
     * List: [-5]->[0]->[-8]
     *
     * Zero is not negative.
     */
    printf("\nTest 8: Zero in the middle\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -8) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: Positive value at the end
     *
     * List: [-5]->[-8]->[10]
     */
    printf("\nTest 9: Positive value at last position\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -8) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: Duplicate negative values
     *
     * List: [-5]->[-5]->[-5]->[-8]
     */
    printf("\nTest 10: Duplicate negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -8) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: Mixed negative and positive values
     *
     * List: [-10]->[-20]->[30]->[-40]
     */
    printf("\nTest 11: Mixed negative and positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, -40) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: FALSE\n");
    printf("Actual:   %d\n", result);

    assert(result == FALSE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: Boundary value -1
     *
     * -1 is the largest possible negative integer.
     */
    printf("\nTest 12: Boundary negative value -1\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -1) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: INT_MIN
     *
     * INT_MIN is negative and must return TRUE.
     */
    printf("\nTest 13: INT_MIN\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: Large negative values
     *
     * All values are negative.
     */
    printf("\nTest 14: Large negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -100000) == SUCCESS);
    assert(insert_end(p_list, -500000) == SUCCESS);
    assert(insert_end(p_list, -1000000) == SUCCESS);

    result = is_all_negative(p_list);

    printf("Expected: TRUE\n");
    printf("Actual:   %d\n", result);

    assert(result == TRUE);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 15: List remains unchanged
     *
     * The exercise function should only inspect the list.
     */
    printf("\nTest 15: List remains unchanged\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, -30) == SUCCESS);

    result = is_all_negative(p_list);

    assert(result == TRUE);

    assert(get_list_length(p_list) == 3);

    data_t start_data;
    data_t end_data;

    assert(get_start(p_list, &start_data) == SUCCESS);
    assert(get_end(p_list, &end_data) == SUCCESS);

    assert(start_data == -10);
    assert(end_data == -30);

    printf("List remains unchanged after function call.\n");

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
status_t is_all_negative(list_t* p_list)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list->next;
    
    while(run != NULL)
    {
        if(run->data >= 0)
            return FALSE;
        run = run->next;
    }
    return TRUE;
}