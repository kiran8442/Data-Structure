#include <assert.h>
#include <limits.h>
#include "list.h"

/*
 * Exercise 3:
 * Count Nodes Less Than X
 *
 * The implementation of count_less() must be provided separately.
 */
int count_less(list_t* p_list, data_t value);

int main(void)
{
    list_t* p_list = NULL;
    int result;

    /*
     * Test 1: NULL list
     *
     * No nodes exist, so the expected count is 0.
     */
    printf("\nTest 1: NULL list\n");

    result = count_less(NULL, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * Expected count: 0.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    result = count_less(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single element less than X
     *
     * List: [5]
     * X = 10
     *
     * Expected count: 1.
     */
    printf("\nTest 3: Single element less than X\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 5) == SUCCESS);

    result = count_less(p_list, 10);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single element equal to X
     *
     * Strictly less than means equality must NOT be counted.
     *
     * List: [10]
     * X = 10
     *
     * Expected count: 0.
     */
    printf("\nTest 4: Single element equal to X\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_less(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Single element greater than X
     *
     * List: [20]
     * X = 10
     *
     * Expected count: 0.
     */
    printf("\nTest 5: Single element greater than X\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = count_less(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Example from the exercise
     *
     * List: [20]->[5]->[20]->[2]->[45]->[60]
     * X = 12
     *
     * Values less than 12:
     * 5, 2
     *
     * Expected count: 2.
     */
    printf("\nTest 6: Exercise example\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 45) == SUCCESS);
    assert(insert_end(p_list, 60) == SUCCESS);

    result = count_less(p_list, 12);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Negative, zero and positive values
     *
     * List: [-10]->[-5]->[0]->[5]->[10]
     * X = 5
     *
     * Values less than 5:
     * -10, -5, 0
     *
     * Expected count: 3.
     */
    printf("\nTest 7: Negative, zero and positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_less(p_list, 5);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: X is negative
     *
     * List: [-20]->[-10]->[-5]->[0]->[10]
     * X = -5
     *
     * Values strictly less than -5:
     * -20, -10
     *
     * Expected count: 2.
     */
    printf("\nTest 8: Negative X\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_less(p_list, -5);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: Duplicate values
     *
     * List: [5]->[5]->[10]->[5]->[20]
     * X = 10
     *
     * All three occurrences of 5 must be counted.
     *
     * Expected count: 3.
     */
    printf("\nTest 9: Duplicate values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = count_less(p_list, 10);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: All elements equal to X
     *
     * List: [10]->[10]->[10]->[10]
     * X = 10
     *
     * Because the comparison is strictly less than,
     * none of the elements should be counted.
     *
     * Expected count: 0.
     */
    printf("\nTest 10: All elements equal to X\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_less(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: All elements less than X
     *
     * List: [1]->[2]->[3]->[4]
     * X = 10
     *
     * Expected count: 4.
     */
    printf("\nTest 11: All elements less than X\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);

    result = count_less(p_list, 10);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: All elements greater than X
     *
     * List: [20]->[30]->[40]->[50]
     * X = 10
     *
     * Expected count: 0.
     */
    printf("\nTest 12: All elements greater than X\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);

    result = count_less(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: Zero as X
     *
     * List: [-10]->[-1]->[0]->[1]->[10]
     * X = 0
     *
     * Values less than 0:
     * -10, -1
     *
     * Expected count: 2.
     */
    printf("\nTest 13: X = 0\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_less(p_list, 0);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: INT boundary values
     *
     * List:
     * INT_MIN, -1, 0, 1, INT_MAX
     *
     * X = 0
     *
     * Values less than 0:
     * INT_MIN, -1
     *
     * Expected count: 2.
     */
    printf("\nTest 14: INT boundary values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    result = count_less(p_list, 0);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 15: X = INT_MIN
     *
     * No int value can be strictly less than INT_MIN.
     *
     * Expected count: 0.
     */
    printf("\nTest 15: X = INT_MIN\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    result = count_less(p_list, INT_MIN);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 16: X = INT_MAX
     *
     * Every element except INT_MAX is strictly less than INT_MAX.
     *
     * Expected count: 4.
     */
    printf("\nTest 16: X = INT_MAX\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    result = count_less(p_list, INT_MAX);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
len_t count_less(list_t* p_list, data_t x)
{
    len_t count  = 0;

    if(p_list == NULL)
        return INVALID_LIST;
    
    node_t* run = p_list->next;
    
    while(run != NULL)
    {
        if(run->data < x)
            count++;
        run = run->next;
    }
    
    return count;
}