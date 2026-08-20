#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/* Exercise function declaration */
int count_in_range(list_t* p_list, data_t low, data_t high);

int main(void)
{
    list_t* p_list = NULL;
    int result;

    /*
     * Test 1: Empty list
     * No nodes are present, so the count must be 0.
     */
    printf("Test 1: Empty list\n");

    p_list = create_list();

    result = count_in_range(p_list, 5, 10);

    printf("Expected: 0, Actual: %d\n", result);
    assert(result == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 2: Single-element list - value inside range
     */
    printf("Test 2: Single element inside range\n");

    p_list = create_list();
    assert(insert_end(p_list, 7) == SUCCESS);

    result = count_in_range(p_list, 5, 10);

    printf("Expected: 1, Actual: %d\n", result);
    assert(result == 1);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 3: Single-element list - value outside range
     */
    printf("Test 3: Single element outside range\n");

    p_list = create_list();
    assert(insert_end(p_list, 20) == SUCCESS);

    result = count_in_range(p_list, 5, 10);

    printf("Expected: 0, Actual: %d\n", result);
    assert(result == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 4: Normal multiple-element list
     *
     * [5, 22, 8, 3, 25, 7]
     * Range: [5, 10]
     *
     * Matching values: 5, 8, 7
     */
    printf("Test 4: Normal multiple-element list\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 22) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);

    result = count_in_range(p_list, 5, 10);

    printf("Expected: 3, Actual: %d\n", result);
    assert(result == 3);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 5: Inclusive lower and upper boundaries
     *
     * Both 5 and 10 must be counted.
     */
    printf("Test 5: Inclusive boundaries\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);
    assert(insert_end(p_list, 11) == SUCCESS);

    result = count_in_range(p_list, 5, 10);

    printf("Expected: 2, Actual: %d\n", result);
    assert(result == 2);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 6: Duplicate values
     *
     * Every occurrence inside the range must be counted.
     */
    printf("Test 6: Duplicate values\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = count_in_range(p_list, 5, 7);

    printf("Expected: 5, Actual: %d\n", result);
    assert(result == 5);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 7: Negative and zero values
     */
    printf("Test 7: Negative and zero values\n");

    p_list = create_list();

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_in_range(p_list, -5, 5);

    printf("Expected: 5, Actual: %d\n", result);
    assert(result == 5);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 8: low == high
     *
     * Only values exactly equal to the boundary should be counted.
     */
    printf("Test 8: Single-value range (low == high)\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 15) == SUCCESS);

    result = count_in_range(p_list, 10, 10);

    printf("Expected: 2, Actual: %d\n", result);
    assert(result == 2);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 9: No values inside the range
     */
    printf("Test 9: No values inside range\n");

    p_list = create_list();

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = count_in_range(p_list, 5, 10);

    printf("Expected: 0, Actual: %d\n", result);
    assert(result == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 10: All values inside the range
     */
    printf("Test 10: All values inside range\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 6) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_in_range(p_list, 5, 10);

    printf("Expected: 5, Actual: %d\n", result);
    assert(result == 5);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 11: low > high
     *
     * No value can satisfy value >= low && value <= high.
     * Expected result is 0.
     */
    printf("Test 11: low greater than high\n");

    p_list = create_list();

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = count_in_range(p_list, 10, 5);

    printf("Expected: 0, Actual: %d\n", result);
    assert(result == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 12: Large values
     *
     * Uses INT-like boundary values only if data_t can safely represent them.
     * Keep values within a safe range for the existing data_t type.
     */
    printf("Test 12: Large and small values\n");

    p_list = create_list();

    assert(insert_end(p_list, -1000000) == SUCCESS);
    assert(insert_end(p_list, -500000) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 500000) == SUCCESS);
    assert(insert_end(p_list, 1000000) == SUCCESS);

    result = count_in_range(p_list, -500000, 500000);

    printf("Expected: 3, Actual: %d\n", result);
    assert(result == 3);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 13: NULL list
     *
     * Include this only if count_in_range() is expected to safely
     * handle NULL as an empty list.
     */
    printf("Test 13: NULL list\n");

    result = count_in_range(NULL, 5, 10);

    printf("Expected: 0, Actual: %d\n", result);
    assert(result == 0);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}

len_t count_in_range(list_t* p_list, data_t low, data_t high)
{
    if(p_list == NULL || p_list->next == NULL)
        return 0;
    node_t* run = p_list->next;
    len_t count = 0;
    while(run != NULL)
    {
        if(run->data <= high && run->data >= low)
            count++;
        run = run->next;
    }
    return count;
}