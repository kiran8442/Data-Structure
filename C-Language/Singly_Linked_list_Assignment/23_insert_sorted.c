#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
status_t are_lists_equal(list_t* p_list1, list_t* p_list2);
status_t insert_sorted(list_t* plist, data_t new_data);
int main(void)
{
    list_t* p_list = NULL;
    status_t status;

    printf("========================================\n");
    printf("Testing Exercise 23: Insert in Sorted Order\n");
    printf("========================================\n\n");

    /*
     * Test 1: Empty list
     * Insert into an empty list.
     * Expected: one element.
     */
    printf("Test 1: Insert into empty list\n");

    p_list = create_list();

    status = insert_sorted(p_list, 25);

    printf("Expected status: %d\n", SUCCESS);
    printf("Actual status:   %d\n", status);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 1);

    {
        data_t data;
        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == 25);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 2: Single-element list
     * Insert a value smaller than the existing element.
     * Expected: [10]->[20]
     */
    printf("Test 2: Insert before single element\n");

    p_list = create_list();

    assert(insert_end(p_list, 20) == SUCCESS);

    status = insert_sorted(p_list, 10);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 2);

    {
        data_t data;

        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == 10);

        assert(get_end(p_list, &data) == SUCCESS);
        assert(data == 20);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 3: Insert at beginning
     * Existing: [20]->[30]->[40]
     * Insert: 10
     * Expected: [10]->[20]->[30]->[40]
     */
    printf("Test 3: Insert at beginning\n");

    p_list = create_list();

    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    status = insert_sorted(p_list, 10);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 4);

    {
        data_t data;

        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == 10);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 4: Insert in the middle
     * Existing: [10]->[20]->[40]->[50]
     * Insert: 35
     * Expected: [10]->[20]->[35]->[40]->[50]
     */
    printf("Test 4: Insert in the middle\n");

    p_list = create_list();

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);

    status = insert_sorted(p_list, 35);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 5);

    {
        data_t data;
        list_t* p_expected = create_list();

        assert(insert_end(p_expected, 10) == SUCCESS);
        assert(insert_end(p_expected, 20) == SUCCESS);
        assert(insert_end(p_expected, 35) == SUCCESS);
        assert(insert_end(p_expected, 40) == SUCCESS);
        assert(insert_end(p_expected, 50) == SUCCESS);

        assert(are_lists_equal(p_list, p_expected) == SUCCESS);

        /* Prevent unused variable warning if needed by compiler settings. */
        (void)data;

        destroy_list(&p_expected);
        assert(p_expected == NULL);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 5: Insert at end
     * Existing: [10]->[20]->[30]
     * Insert: 40
     * Expected: [10]->[20]->[30]->[40]
     */
    printf("Test 5: Insert at end\n");

    p_list = create_list();

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = insert_sorted(p_list, 40);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 4);

    {
        data_t data;

        assert(get_end(p_list, &data) == SUCCESS);
        assert(data == 40);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 6: Insert duplicate value
     * Existing: [10]->[20]->[20]->[30]
     * Insert: 20
     *
     * Expected:
     * [10]->[20]->[20]->[20]->[30]
     *
     * Only ordering and count are important; duplicates are valid.
     */
    printf("Test 6: Insert duplicate value\n");

    p_list = create_list();

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = insert_sorted(p_list, 20);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 5);

    {
        list_t* p_expected = create_list();

        assert(insert_end(p_expected, 10) == SUCCESS);
        assert(insert_end(p_expected, 20) == SUCCESS);
        assert(insert_end(p_expected, 20) == SUCCESS);
        assert(insert_end(p_expected, 20) == SUCCESS);
        assert(insert_end(p_expected, 30) == SUCCESS);

        assert(are_lists_equal(p_list, p_expected) == SUCCESS);

        destroy_list(&p_expected);
        assert(p_expected == NULL);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 7: Negative and zero values
     * Existing: [-10]->[0]->[10]
     * Insert: -5
     * Expected: [-10]->[-5]->[0]->[10]
     */
    printf("Test 7: Negative and zero values\n");

    p_list = create_list();

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    status = insert_sorted(p_list, -5);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 4);

    {
        list_t* p_expected = create_list();

        assert(insert_end(p_expected, -10) == SUCCESS);
        assert(insert_end(p_expected, -5) == SUCCESS);
        assert(insert_end(p_expected, 0) == SUCCESS);
        assert(insert_end(p_expected, 10) == SUCCESS);

        assert(are_lists_equal(p_list, p_expected) == SUCCESS);

        destroy_list(&p_expected);
        assert(p_expected == NULL);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 8: Insert a value equal to the smallest element
     * Existing: [10]->[20]->[30]
     * Insert: 10
     *
     * Expected: [10]->[10]->[20]->[30]
     */
    printf("Test 8: Duplicate smallest value\n");

    p_list = create_list();

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = insert_sorted(p_list, 10);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 4);

    {
        list_t* p_expected = create_list();

        assert(insert_end(p_expected, 10) == SUCCESS);
        assert(insert_end(p_expected, 10) == SUCCESS);
        assert(insert_end(p_expected, 20) == SUCCESS);
        assert(insert_end(p_expected, 30) == SUCCESS);

        assert(are_lists_equal(p_list, p_expected) == SUCCESS);

        destroy_list(&p_expected);
        assert(p_expected == NULL);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 9: Duplicate largest value
     * Existing: [10]->[20]->[30]
     * Insert: 30
     *
     * Expected: [10]->[20]->[30]->[30]
     */
    printf("Test 9: Duplicate largest value\n");

    p_list = create_list();

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = insert_sorted(p_list, 30);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 4);

    {
        list_t* p_expected = create_list();

        assert(insert_end(p_expected, 10) == SUCCESS);
        assert(insert_end(p_expected, 20) == SUCCESS);
        assert(insert_end(p_expected, 30) == SUCCESS);
        assert(insert_end(p_expected, 30) == SUCCESS);

        assert(are_lists_equal(p_list, p_expected) == SUCCESS);

        destroy_list(&p_expected);
        assert(p_expected == NULL);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 10: Large and small values
     * Verify ordering without arithmetic overflow.
     */
    printf("Test 10: Large and small values\n");

    p_list = create_list();

    assert(insert_end(p_list, -1000000) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1000000) == SUCCESS);

    status = insert_sorted(p_list, 500000);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 4);

    {
        list_t* p_expected = create_list();

        assert(insert_end(p_expected, -1000000) == SUCCESS);
        assert(insert_end(p_expected, 0) == SUCCESS);
        assert(insert_end(p_expected, 500000) == SUCCESS);
        assert(insert_end(p_expected, 1000000) == SUCCESS);

        assert(are_lists_equal(p_list, p_expected) == SUCCESS);

        destroy_list(&p_expected);
        assert(p_expected == NULL);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    printf("========================================\n");
    printf("All tests passed successfully!\n");
    printf("========================================\n");

    return EXIT_SUCCESS;
}
status_t insert_sorted(list_t* p_list, data_t new_data)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list->next;
    node_t* run_prev = p_list;
    int index = 0;
    while(run != NULL)
    {   
        if(run->data > new_data)
            break;
        run_prev = run;
        run = run->next;
    }
    node_t* new_node = get_node(new_data);
    new_node->next =  run_prev->next;
    run_prev->next = new_node;
    return SUCCESS;
}
status_t are_lists_equal(list_t* p_list1, list_t* p_list2)
{
    if(p_list1 == NULL && p_list2 == NULL ||
       p_list1->next == NULL && p_list2->next == NULL)
        return TRUE;
    if(p_list1 == NULL || p_list2 == NULL)
        return FALSE;

    node_t* run1 = p_list1->next;
    node_t* run2 = p_list2->next;
    while(run1 != NULL && run2 != NULL)
    {   
        if(run1->data != run2->data)
            return FALSE;
        run1 = run1->next;
        run2 = run2->next;
    }
    if(run1 != NULL)
        return FALSE;
    if(run2 != NULL)
        return FALSE;
    return TRUE;
}