#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
 * Exercise 12:
 * Find First Index of Value
 *
 * Implementation must be provided separately.
 */
int get_first_index(list_t* plist, data_t value);

int main(void)
{
    list_t* p_list = NULL;
    int result;

    /*
     * Test 1: NULL list
     *
     * No value can be found in a NULL list.
     */
    printf("\nTest 1: NULL list\n");

    result = get_first_index(NULL, 10);

    printf("Expected: -1\n");
    printf("Actual:   %d\n", result);

    assert(result == -1);


    /*
     * Test 2: Empty list
     *
     * List: [START]
     *
     * Value is not present.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    result = get_first_index(p_list, 10);

    printf("Expected: -1\n");
    printf("Actual:   %d\n", result);

    assert(result == -1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single element - value found
     *
     * List: [10]
     * Index: 0
     */
    printf("\nTest 3: Single element - found\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = get_first_index(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single element - value not found
     *
     * List: [10]
     */
    printf("\nTest 4: Single element - not found\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = get_first_index(p_list, 20);

    printf("Expected: -1\n");
    printf("Actual:   %d\n", result);

    assert(result == -1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Value at first index
     *
     * List: [20]->[30]->[40]
     *
     * 20 is at index 0.
     */
    printf("\nTest 5: Value at first index\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = get_first_index(p_list, 20);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Value at middle index
     *
     * List: [10]->[20]->[30]->[40]
     *
     * 30 is at index 2.
     */
    printf("\nTest 6: Value at middle index\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = get_first_index(p_list, 30);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Value at last index
     *
     * List: [10]->[20]->[30]->[40]
     *
     * 40 is at index 3.
     */
    printf("\nTest 7: Value at last index\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = get_first_index(p_list, 40);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Value not found
     *
     * List: [10]->[20]->[30]->[40]
     *
     * 50 does not exist.
     */
    printf("\nTest 8: Value not found\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = get_first_index(p_list, 50);

    printf("Expected: -1\n");
    printf("Actual:   %d\n", result);

    assert(result == -1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: Duplicate values
     *
     * List: [10]->[20]->[30]->[20]->[40]
     *
     * 20 occurs at indices 1 and 3.
     * The function must return the FIRST occurrence: 1.
     */
    printf("\nTest 9: Duplicate values - first occurrence\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = get_first_index(p_list, 20);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: Value occurs multiple times including index 0
     *
     * List: [20]->[10]->[20]->[30]->[20]
     *
     * First occurrence of 20 is index 0.
     */
    printf("\nTest 10: Duplicate value including first element\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = get_first_index(p_list, 20);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: Zero value
     *
     * List: [10]->[0]->[20]
     *
     * Zero is a valid data value.
     */
    printf("\nTest 11: Zero value\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = get_first_index(p_list, 0);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: Negative value
     *
     * List: [-10]->[20]->[-30]
     */
    printf("\nTest 12: Negative value\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, -30) == SUCCESS);

    result = get_first_index(p_list, -30);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: Duplicate negative values
     *
     * List: [-5]->[-10]->[-5]->[-20]
     *
     * First -5 is at index 0.
     */
    printf("\nTest 13: Duplicate negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -20) == SUCCESS);

    result = get_first_index(p_list, -5);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: Large and small values
     *
     * Verify that data_t boundary values can be searched.
     */
    printf("\nTest 14: Large/small values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MAX) == SUCCESS);
    assert(insert_end(p_list, 100) == SUCCESS);
    assert(insert_end(p_list, INT_MIN) == SUCCESS);

    result = get_first_index(p_list, INT_MIN);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 15: Value occurs only once after several elements
     *
     * List: [1]->[2]->[3]->[4]->[5]->[6]
     *
     * Search for 5 => index 4.
     */
    printf("\nTest 15: Value near the end\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 6) == SUCCESS);

    result = get_first_index(p_list, 5);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 16: List remains unchanged
     *
     * Searching must not modify the list.
     */
    printf("\nTest 16: List remains unchanged\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    result = get_first_index(p_list, 20);

    assert(result == 1);
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
int get_first_index(list_t* p_list, data_t rvalue)
{
    if(p_list == NULL)
        return -1;

    node_t* run = p_list->next;
    int index = 0;
    while(run != NULL)
    {
        if(run->data == rvalue)
            return index;
        run = run->next;
        index++;
    }
    return -1;
}