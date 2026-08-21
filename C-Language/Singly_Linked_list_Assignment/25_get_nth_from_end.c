#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

status_t get_nth_from_end(list_t* plist, int n, data_t* p_data);

int main(void)
{
    status_t status;
    data_t data;

    /*
     * Test 1: NULL list
     *
     * A NULL list is invalid, so the function should report
     * LIST_DATA_NOT_FOUND.
     */
    printf("Test 1: NULL list\n");

    data = 12345;

    status = get_nth_from_end(NULL, 0, &data);

    printf("Expected: INVALID_LIST\n");
    printf("Actual:   %d\n", status);

    assert(status == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * An empty list has no Nth node from the end.
     */
    printf("\nTest 2: Empty list\n");

    {
        list_t* p_list = create_list();

        data = 12345;

        status = get_nth_from_end(p_list, 0, &data);

        printf("Expected: LIST_DATA_NOT_FOUND\n");
        printf("Actual:   %d\n", status);

        assert(status == LIST_DATA_NOT_FOUND);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 3: Single-element list
     *
     * For a list containing one element:
     * n = 0 must return that element.
     */
    printf("\nTest 3: Single-element list\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 42) == SUCCESS);

        data = 0;

        status = get_nth_from_end(p_list, 0, &data);

        printf("Expected: SUCCESS, data = 42\n");
        printf("Actual:   status = %d, data = %d\n", status, data);

        assert(status == SUCCESS);
        assert(data == 42);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 4: Single-element list with invalid n
     *
     * n = 1 is outside the valid range because the list
     * contains only one element.
     */
    printf("\nTest 4: Single-element list, n >= length\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 42) == SUCCESS);

        data = 12345;

        status = get_nth_from_end(p_list, 1, &data);

        printf("Expected: LIST_DATA_NOT_FOUND\n");
        printf("Actual:   %d\n", status);

        assert(status == LIST_DATA_NOT_FOUND);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 5: Negative n
     *
     * Negative positions are explicitly invalid.
     */
    printf("\nTest 5: Negative n\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);

        data = 12345;

        status = get_nth_from_end(p_list, -1, &data);

        printf("Expected: LIST_DATA_NOT_FOUND\n");
        printf("Actual:   %d\n", status);

        assert(status == LIST_DATA_NOT_FOUND);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 6: Normal multiple-element list
     *
     * [10]->[20]->[30]->[40]->[50]
     *
     * n = 2 means the third node from the end:
     * [30]
     */
    printf("\nTest 6: Multiple-element list, n = 2\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);
        assert(insert_end(p_list, 40) == SUCCESS);
        assert(insert_end(p_list, 50) == SUCCESS);

        data = 0;

        status = get_nth_from_end(p_list, 2, &data);

        printf("Expected: SUCCESS, data = 30\n");
        printf("Actual:   status = %d, data = %d\n", status, data);

        assert(status == SUCCESS);
        assert(data == 30);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 7: n = 0
     *
     * n = 0 must return the last element.
     */
    printf("\nTest 7: n = 0, last element\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);
        assert(insert_end(p_list, 40) == SUCCESS);
        assert(insert_end(p_list, 50) == SUCCESS);

        data = 0;

        status = get_nth_from_end(p_list, 0, &data);

        printf("Expected: SUCCESS, data = 50\n");
        printf("Actual:   status = %d, data = %d\n", status, data);

        assert(status == SUCCESS);
        assert(data == 50);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 8: n = length - 1
     *
     * This is the opposite boundary:
     * n = 4 in a 5-element list must return the first element.
     */
    printf("\nTest 8: n = length - 1, first element\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);
        assert(insert_end(p_list, 40) == SUCCESS);
        assert(insert_end(p_list, 50) == SUCCESS);

        data = 0;

        status = get_nth_from_end(p_list, 4, &data);

        printf("Expected: SUCCESS, data = 10\n");
        printf("Actual:   status = %d, data = %d\n", status, data);

        assert(status == SUCCESS);
        assert(data == 10);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 9: n >= length
     *
     * Both n == length and n > length are invalid.
     */
    printf("\nTest 9: n >= length\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);

        data = 12345;

        status = get_nth_from_end(p_list, 3, &data);

        printf("Expected: LIST_DATA_NOT_FOUND for n == length\n");
        printf("Actual:   %d\n", status);

        assert(status == LIST_DATA_NOT_FOUND);

        status = get_nth_from_end(p_list, 100, &data);

        printf("Expected: LIST_DATA_NOT_FOUND for n > length\n");
        printf("Actual:   %d\n", status);

        assert(status == LIST_DATA_NOT_FOUND);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 10: Duplicate values
     *
     * Duplicate data must not affect the position-based calculation.
     */
    printf("\nTest 10: Duplicate values\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 5) == SUCCESS);
        assert(insert_end(p_list, 5) == SUCCESS);
        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 5) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);

        data = 0;

        status = get_nth_from_end(p_list, 2, &data);

        printf("Expected: SUCCESS, data = 10\n");
        printf("Actual:   status = %d, data = %d\n", status, data);

        assert(status == SUCCESS);
        assert(data == 10);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 11: Positive, negative and zero values
     *
     * Verifies that data values themselves do not affect
     * position-based lookup.
     */
    printf("\nTest 11: Positive, negative and zero values\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, -100) == SUCCESS);
        assert(insert_end(p_list, 0) == SUCCESS);
        assert(insert_end(p_list, 100) == SUCCESS);
        assert(insert_end(p_list, -200) == SUCCESS);
        assert(insert_end(p_list, 200) == SUCCESS);

        data = 0;

        status = get_nth_from_end(p_list, 3, &data);

        printf("Expected: SUCCESS, data = 0\n");
        printf("Actual:   status = %d, data = %d\n", status, data);

        assert(status == SUCCESS);
        assert(data == 0);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 12: Large/small values
     *
     * Uses values within the data_t range. The position lookup
     * should work independently of the magnitude of the values.
     */
    printf("\nTest 12: Large/small values\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, (data_t)-1000000) == SUCCESS);
        assert(insert_end(p_list, (data_t)0) == SUCCESS);
        assert(insert_end(p_list, (data_t)1000000) == SUCCESS);

        data = 0;

        status = get_nth_from_end(p_list, 1, &data);

        printf("Expected: SUCCESS, data = 0\n");
        printf("Actual:   status = %d, data = %d\n", status, data);

        assert(status == SUCCESS);
        assert(data == (data_t)0);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 13: Verify that the list is not modified
     *
     * Calling get_nth_from_end() should only retrieve data.
     * The list must remain unchanged.
     */
    printf("\nTest 13: Verify list remains unchanged\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);
        assert(insert_end(p_list, 40) == SUCCESS);

        data = 0;

        status = get_nth_from_end(p_list, 1, &data);

        printf("Expected: SUCCESS, data = 30\n");
        printf("Actual:   status = %d, data = %d\n", status, data);

        assert(status == SUCCESS);
        assert(data == 30);

        /* Verify length remains unchanged. */
        assert(get_list_length(p_list) == 4);

        /* Verify first element remains unchanged. */
        status = get_start(p_list, &data);
        assert(status == SUCCESS);
        assert(data == 10);

        /* Verify last element remains unchanged. */
        status = get_end(p_list, &data);
        assert(status == SUCCESS);
        assert(data == 40);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
status_t get_nth_from_end(list_t* p_list, int n, data_t* p_data)
{
    if(p_list == NULL)
        return INVALID_LIST;
    if(get_list_length(p_list) <= n || n < 0)
        return LIST_DATA_NOT_FOUND;
    int index = 0;
    node_t* run = p_list->next;
    node_t* run_prev = p_list->next;
    while(run != NULL && index <= n)
    {   
        run = run->next;
        index++;
    }
    while(run != NULL)
    {
        run_prev = run_prev->next;
        run = run->next;
    }
    *p_data = run_prev->data;
    return SUCCESS;
}