#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
 * Exercise 9:
 * Count Occurrences
 *
 * The implementation of count_occurrences() must be provided separately.
 */
int count_occurrences(list_t* plist, data_t value);

int main(void)
{
    list_t* p_list = NULL;
    int result;

    /*
     * Test 1: NULL list
     *
     * There are no nodes, so the expected count is 0.
     */
    printf("\nTest 1: NULL list\n");

    result = count_occurrences(NULL, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);


    /*
     * Test 2: Empty list
     *
     * Searching any value in an empty list should return 0.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    result = count_occurrences(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single-element list - value exists
     *
     * List: [10]
     *
     * 10 occurs exactly once.
     */
    printf("\nTest 3: Single element - value exists\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_occurrences(p_list, 10);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single-element list - value does not exist
     *
     * List: [10]
     *
     * 20 does not occur.
     */
    printf("\nTest 4: Single element - value does not exist\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_occurrences(p_list, 20);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Multiple elements - normal case
     *
     * List: [10]->[20]->[10]->[30]->[10]
     *
     * 10 occurs 3 times.
     */
    printf("\nTest 5: Multiple elements - normal case\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_occurrences(p_list, 10);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Value occurs exactly once
     *
     * List: [10]->[20]->[30]->[40]
     *
     * 30 occurs once.
     */
    printf("\nTest 6: Value occurs once\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = count_occurrences(p_list, 30);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Value does not exist
     *
     * List: [10]->[20]->[30]->[40]
     *
     * 99 does not occur.
     */
    printf("\nTest 7: Value does not exist\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = count_occurrences(p_list, 99);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: All elements are the same
     *
     * List: [7]->[7]->[7]->[7]->[7]
     *
     * 7 occurs 5 times.
     */
    printf("\nTest 8: All elements are duplicates\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);

    result = count_occurrences(p_list, 7);

    printf("Expected: 5\n");
    printf("Actual:   %d\n", result);

    assert(result == 5);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: Zero values
     *
     * List: [0]->[10]->[0]->[-10]->[0]
     *
     * 0 occurs 3 times.
     */
    printf("\nTest 9: Zero values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);

    result = count_occurrences(p_list, 0);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: Negative values
     *
     * List: [-5]->[-10]->[-5]->[0]->[-5]
     *
     * -5 occurs 3 times.
     */
    printf("\nTest 10: Negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);

    result = count_occurrences(p_list, -5);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: Positive and negative values together
     *
     * List: [-10]->[10]->[-10]->[20]->[-10]->[10]
     *
     * -10 occurs 3 times.
     * 10 occurs 2 times.
     */
    printf("\nTest 11: Positive and negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_occurrences(p_list, -10);

    printf("Expected occurrences of -10: 3\n");
    printf("Actual:                       %d\n", result);

    assert(result == 3);

    result = count_occurrences(p_list, 10);

    printf("Expected occurrences of 10: 2\n");
    printf("Actual:                      %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: Large and small data values
     *
     * Verify that counting works correctly with boundary integer
     * values without performing arithmetic on the data values.
     */
    printf("\nTest 12: Large and small values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);
    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    result = count_occurrences(p_list, INT_MIN);

    printf("Expected occurrences of INT_MIN: 2\n");
    printf("Actual:                          %d\n", result);

    assert(result == 2);

    result = count_occurrences(p_list, INT_MAX);

    printf("Expected occurrences of INT_MAX: 2\n");
    printf("Actual:                          %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: Count different values in the same list
     *
     * This verifies that one call does not modify the list.
     */
    printf("\nTest 13: Multiple searches on the same list\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_occurrences(p_list, 5);
    assert(result == 3);

    result = count_occurrences(p_list, 10);
    assert(result == 2);

    result = count_occurrences(p_list, 20);
    assert(result == 1);

    result = count_occurrences(p_list, 100);
    assert(result == 0);

    printf("All multiple occurrence checks passed.\n");

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
len_t count_occurrences(list_t* p_list, data_t value)
{
    if(p_list == NULL)
        return 0;

    node_t* run = p_list->next;
    len_t count = 0;

    while(run != NULL)
    {
        if(run->data == value)
            count++;
        run = run->next;
    }
    return count;
}