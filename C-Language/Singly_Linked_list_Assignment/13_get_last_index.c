#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* Exercise function declaration */
int get_last_index(list_t* plist, data_t value);

int main(void)
{
    int result;

    /*
     * Test 1: NULL list
     * No list exists. The value cannot be found.
     */
    printf("Test 1: NULL list\n");

    result = get_last_index(NULL, 10);

    printf("Expected: -1\n");
    printf("Actual:   %d\n", result);

    assert(result == -1);

    /*
     * Test 2: Empty list
     * An empty list contains no value.
     */
    printf("\nTest 2: Empty list\n");

    list_t* p_list = create_list();
    assert(p_list != NULL);

    result = get_last_index(p_list, 10);

    printf("Expected: -1\n");
    printf("Actual:   %d\n", result);

    assert(result == -1);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 3: Single-element list - value found
     */
    printf("\nTest 3: Single-element list - value found\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);

    result = get_last_index(p_list, 10);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 4: Single-element list - value not found
     */
    printf("\nTest 4: Single-element list - value not found\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);

    result = get_last_index(p_list, 20);

    printf("Expected: -1\n");
    printf("Actual:   %d\n", result);

    assert(result == -1);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 5: Multiple elements - normal case
     *
     * [10] [20] [30] [20]
     * value = 20
     * Last occurrence is at index 3.
     */
    printf("\nTest 5: Multiple elements - duplicate value\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = get_last_index(p_list, 20);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 6: Value occurs at first and last positions
     *
     * [10] [20] [30] [40] [10]
     * value = 10
     * Last occurrence is index 4.
     */
    printf("\nTest 6: Value at first and last positions\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = get_last_index(p_list, 10);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 7: Value occurs multiple times including middle and last
     *
     * [5] [10] [5] [20] [5] [30]
     * value = 5
     * Last occurrence is index 4.
     */
    printf("\nTest 7: Multiple occurrences\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    result = get_last_index(p_list, 5);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 8: Value appears only once
     *
     * [10] [20] [30] [40]
     * value = 30
     * Expected index = 2.
     */
    printf("\nTest 8: Value occurs only once\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = get_last_index(p_list, 30);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 9: Value not present
     */
    printf("\nTest 9: Value not present\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    result = get_last_index(p_list, 99);

    printf("Expected: -1\n");
    printf("Actual:   %d\n", result);

    assert(result == -1);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 10: Zero value
     *
     * Zero is a valid data value and should be handled normally.
     *
     * [0] [10] [0] [-5]
     * value = 0
     * Last occurrence is index 2.
     */
    printf("\nTest 10: Zero value\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);

    result = get_last_index(p_list, 0);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 11: Negative values
     *
     * [-10] [-5] [-10] [0]
     * value = -10
     * Last occurrence is index 2.
     */
    printf("\nTest 11: Negative values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);

    result = get_last_index(p_list, -10);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 12: All elements are the same
     *
     * [7] [7] [7] [7] [7]
     * value = 7
     * Last occurrence is index 4.
     */
    printf("\nTest 12: All elements are duplicates\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);

    result = get_last_index(p_list, 7);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 13: Large and small values
     *
     * Values are chosen as ordinary data_t values to avoid
     * assumptions about integer limits.
     */
    printf("\nTest 13: Large and small values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 1000000) == SUCCESS);
    assert(insert_end(p_list, -1000000) == SUCCESS);
    assert(insert_end(p_list, 1000000) == SUCCESS);
    assert(insert_end(p_list, 500) == SUCCESS);

    result = get_last_index(p_list, 1000000);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 14: Match at the last element only
     *
     * [10] [20] [30] [40] [50]
     * value = 50
     * Expected index = 4.
     */
    printf("\nTest 14: Match at last element\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);

    result = get_last_index(p_list, 50);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
int get_last_index(list_t* p_list, data_t rvalue)
{
    if(p_list == NULL)
        return -1;

    node_t* run = p_list->next;
    int index = 0;
    int last_index = -1;
    while(run != NULL)
    {
        if(run->data == rvalue)
            last_index = index;
        run = run->next;
        index++;
    }
    return last_index;
}