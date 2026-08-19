#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * Exercise 8:
 * Get Data at Index
 *
 * The implementation of get_data_at_index() must be provided separately.
 */
status_t get_data_at_index(list_t* p_list, len_t index, data_t* p_data);

int main(void)
{
    list_t* p_list = NULL;
    data_t data;
    status_t status;

    /*
     * Test 1: NULL list
     *
     * No valid data can be retrieved from a NULL list.
     */
    printf("\nTest 1: NULL list\n");

    data = 999;

    status = get_data_at_index(NULL, 0, &data);

    printf("Expected status: %d\n", LIST_DATA_NOT_FOUND);
    printf("Actual status:   %d\n", status);

    assert(status == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * There are no data nodes, so index 0 is invalid.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    data = 999;

    status = get_data_at_index(p_list, 0, &data);

    printf("Expected status: %d\n", LIST_DATA_NOT_FOUND);
    printf("Actual status:   %d\n", status);

    assert(status == LIST_DATA_NOT_FOUND);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single-element list, index 0
     *
     * List: [42]
     *
     * Index 0 should return 42.
     */
    printf("\nTest 3: Single element, index 0\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 42) == SUCCESS);

    data = 0;

    status = get_data_at_index(p_list, 0, &data);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected data:   42\n");
    printf("Actual data:     %d\n", data);

    assert(status == SUCCESS);
    assert(data == 42);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single-element list, invalid index
     *
     * List: [42]
     *
     * Index 1 is outside the list.
     */
    printf("\nTest 4: Single element, index 1\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 42) == SUCCESS);

    data = 999;

    status = get_data_at_index(p_list, 1, &data);

    printf("Expected status: %d\n", LIST_DATA_NOT_FOUND);
    printf("Actual status:   %d\n", status);

    assert(status == LIST_DATA_NOT_FOUND);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Multiple elements, index 0
     *
     * List: [10]->[20]->[30]->[40]
     *
     * Index 0 should return 10.
     */
    printf("\nTest 5: Multiple elements, first index\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    data = 0;

    status = get_data_at_index(p_list, 0, &data);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected data:   10\n");
    printf("Actual data:     %d\n", data);

    assert(status == SUCCESS);
    assert(data == 10);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Multiple elements, middle index
     *
     * List: [10]->[20]->[30]->[40]
     *
     * Index 2 should return 30.
     *
     * This is the exercise example.
     */
    printf("\nTest 6: Multiple elements, middle index\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    data = 0;

    status = get_data_at_index(p_list, 2, &data);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected data:   30\n");
    printf("Actual data:     %d\n", data);

    assert(status == SUCCESS);
    assert(data == 30);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Multiple elements, last valid index
     *
     * List: [10]->[20]->[30]->[40]
     *
     * Index 3 should return 40.
     */
    printf("\nTest 7: Last valid index\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    data = 0;

    status = get_data_at_index(p_list, 3, &data);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected data:   40\n");
    printf("Actual data:     %d\n", data);

    assert(status == SUCCESS);
    assert(data == 40);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Index equal to list length
     *
     * List length = 4
     *
     * Valid indexes are 0, 1, 2, 3.
     * Index 4 must be invalid.
     */
    printf("\nTest 8: Index equal to list length\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    data = 999;

    status = get_data_at_index(p_list, 4, &data);

    printf("Expected status: %d\n", LIST_DATA_NOT_FOUND);
    printf("Actual status:   %d\n", status);

    assert(status == LIST_DATA_NOT_FOUND);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: Index greater than list length
     *
     * List length = 4.
     * Index 100 is invalid.
     */
    printf("\nTest 9: Index greater than list length\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    data = 999;

    status = get_data_at_index(p_list, 100, &data);

    printf("Expected status: %d\n", LIST_DATA_NOT_FOUND);
    printf("Actual status:   %d\n", status);

    assert(status == LIST_DATA_NOT_FOUND);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: Duplicate values
     *
     * List: [10]->[20]->[10]->[30]->[10]
     *
     * Verify that the function retrieves data based on POSITION,
     * not based on searching for a value.
     */
    printf("\nTest 10: Duplicate values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    data = 0;

    status = get_data_at_index(p_list, 2, &data);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected data:   10\n");
    printf("Actual data:     %d\n", data);

    assert(status == SUCCESS);
    assert(data == 10);

    data = 0;

    status = get_data_at_index(p_list, 3, &data);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected data:   30\n");
    printf("Actual data:     %d\n", data);

    assert(status == SUCCESS);
    assert(data == 30);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: Negative and zero data values
     *
     * List: [-20]->[-10]->[0]->[10]->[20]
     *
     * Verify that data values themselves can be negative or zero.
     */
    printf("\nTest 11: Negative and zero data values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    data = 999;

    status = get_data_at_index(p_list, 0, &data);

    assert(status == SUCCESS);
    assert(data == -20);

    data = 999;

    status = get_data_at_index(p_list, 2, &data);

    assert(status == SUCCESS);
    assert(data == 0);

    data = 999;

    status = get_data_at_index(p_list, 4, &data);

    assert(status == SUCCESS);
    assert(data == 20);

    printf("Index 0 -> -20\n");
    printf("Index 2 -> 0\n");
    printf("Index 4 -> 20\n");

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: Negative index
     *
     * This test is applicable only if len_t is a signed type.
     *
     * If len_t is unsigned in your list.h, a negative index cannot
     * be represented and this test should be omitted.
     */
#if defined(__GNUC__) || defined(__clang__)
    if (((len_t)-1) < (len_t)0)
    {
        printf("\nTest 12: Negative index\n");

        p_list = create_list();

        assert(p_list != NULL);

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);

        data = 999;

        status = get_data_at_index(p_list, (len_t)-1, &data);

        printf("Expected status: %d\n", LIST_DATA_NOT_FOUND);
        printf("Actual status:   %d\n", status);

        assert(status == LIST_DATA_NOT_FOUND);

        assert(destroy_list(&p_list) == SUCCESS);
        assert(p_list == NULL);
    }
#endif


    /*
     * Test 13: Large data values
     *
     * The index operation should not depend on the magnitude of
     * the stored data.
     */
    printf("\nTest 13: Large and small data values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    data = 0;

    status = get_data_at_index(p_list, 0, &data);

    printf("Index 0 expected: %d\n", INT_MIN);
    printf("Index 0 actual:   %d\n", data);

    assert(status == SUCCESS);
    assert(data == INT_MIN);

    data = 0;

    status = get_data_at_index(p_list, 2, &data);

    printf("Index 2 expected: %d\n", INT_MAX);
    printf("Index 2 actual:   %d\n", data);

    assert(status == SUCCESS);
    assert(data == INT_MAX);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: Multiple index lookups on the same list
     *
     * Ensures the function does not modify the list while retrieving
     * data.
     */
    printf("\nTest 14: Multiple index lookups\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 100) == SUCCESS);
    assert(insert_end(p_list, 200) == SUCCESS);
    assert(insert_end(p_list, 300) == SUCCESS);
    assert(insert_end(p_list, 400) == SUCCESS);
    assert(insert_end(p_list, 500) == SUCCESS);

    data = 0;

    status = get_data_at_index(p_list, 0, &data);
    assert(status == SUCCESS);
    assert(data == 100);

    status = get_data_at_index(p_list, 4, &data);
    assert(status == SUCCESS);
    assert(data == 500);

    status = get_data_at_index(p_list, 2, &data);
    assert(status == SUCCESS);
    assert(data == 300);

    status = get_data_at_index(p_list, 1, &data);
    assert(status == SUCCESS);
    assert(data == 200);

    printf("Multiple index lookups completed successfully.\n");

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
status_t get_data_at_index(list_t* p_list, int index, data_t* p_data)
{
    if(p_list == NULL)
        return INVALID_LIST;
    
    node_t* run = p_list->next;
    int i = 0;
    while(run != NULL)
    {
        if(index == i)
        {
            *p_data = run->data;
            return SUCCESS;
        } 
        i++;
        run = run->next;
    }
    return LIST_DATA_NOT_FOUND;
}