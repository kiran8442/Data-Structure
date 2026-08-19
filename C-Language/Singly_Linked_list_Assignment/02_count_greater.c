#include <assert.h>
#include <limits.h>
#include "list.h"

/*
 * Exercise 2:
 * Count Nodes Greater Than X
 *
 * Implemented separately by the student.
 */
int count_greater(list_t* plist, data_t value);

int main(void)
{
    list_t* p_list = NULL;
    int result;

    /*
     * Test 1: NULL list
     *
     * A NULL list is a reasonable defensive-input case.
     * Expected result: 0
     */
    printf("\nTest 1: NULL list\n");

    result = count_greater(NULL, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * No data nodes exist.
     * Expected result: 0.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    result = count_greater(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single-element list
     *
     * Element is greater than X.
     * Expected result: 1.
     */
    printf("\nTest 3: Single element - greater than X\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = count_greater(p_list, 10);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single-element list - equal to X
     *
     * The comparison is strictly greater than.
     * Equal values must NOT be counted.
     */
    printf("\nTest 4: Single element - equal to X\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_greater(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Single-element list - less than X
     *
     * Element is not greater than X.
     * Expected result: 0.
     */
    printf("\nTest 5: Single element - less than X\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 5) == SUCCESS);

    result = count_greater(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Multiple elements
     *
     * List: 5, 15, 10, 20, 3
     * X = 10
     *
     * Values greater than 10:
     * 15, 20
     *
     * Expected result: 2.
     */
    printf("\nTest 6: Multiple elements\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 15) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);

    result = count_greater(p_list, 10);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Negative, zero and positive values
     *
     * List: -10, -5, 0, 5, 10
     * X = -5
     *
     * Values greater than -5:
     * 0, 5, 10
     *
     * Expected result: 3.
     */
    printf("\nTest 7: Negative, zero and positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_greater(p_list, -5);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Duplicate values
     *
     * List: 10, 20, 20, 5, 20
     * X = 10
     *
     * All three occurrences of 20 must be counted.
     * Expected result: 3.
     */
    printf("\nTest 8: Duplicate values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = count_greater(p_list, 10);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: All elements equal to X
     *
     * List: 10, 10, 10, 10
     * X = 10
     *
     * None should be counted because the comparison
     * must be strictly greater than.
     */
    printf("\nTest 9: All elements equal to X\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_greater(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: All elements greater than X
     *
     * List: 11, 12, 13, 14
     * X = 10
     *
     * Expected result: 4.
     */
    printf("\nTest 10: All elements greater than X\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 11) == SUCCESS);
    assert(insert_end(p_list, 12) == SUCCESS);
    assert(insert_end(p_list, 13) == SUCCESS);
    assert(insert_end(p_list, 14) == SUCCESS);

    result = count_greater(p_list, 10);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: All elements less than X
     *
     * List: 1, 2, 3, 4
     * X = 10
     *
     * Expected result: 0.
     */
    printf("\nTest 11: All elements less than X\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);

    result = count_greater(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: INT boundary values
     *
     * Verify that the function handles the smallest and largest
     * representable int values without arithmetic overflow.
     */
    printf("\nTest 12: INT boundary values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    result = count_greater(p_list, 0);

    /*
     * Values greater than 0:
     * 1, INT_MAX
     *
     * Expected result: 2.
     */
    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: X is INT_MAX
     *
     * No int value can be greater than INT_MAX.
     * Expected result: 0.
     */
    printf("\nTest 13: X = INT_MAX\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    result = count_greater(p_list, INT_MAX);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: X is INT_MIN
     *
     * Every value except INT_MIN itself is greater than INT_MIN.
     *
     * List: INT_MIN, -1, 0, 1, INT_MAX
     *
     * Expected result: 4.
     */
    printf("\nTest 14: X = INT_MIN\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    result = count_greater(p_list, INT_MIN);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
len_t count_greater(list_t* p_list, data_t x)
{
    len_t count  = 0;

    if(p_list == NULL)
        return INVALID_LIST;
    
    node_t* run = p_list->next;
    
    while(run != NULL)
    {
        if(run->data > x)
            count++;
        run = run->next;
    }
    
    return count;
}