#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

len_t delete_all_occurrences(list_t* p_list, data_t value);
int main(void)
{
    list_t* p_list = NULL;
    status_t status;
    len_t deleted_count;

    printf("========================================\n");
    printf("Testing Exercise 24: Delete All Occurrences\n");
    printf("========================================\n\n");

    /*
     * Test 1: Empty list
     *
     * No nodes exist, so nothing should be deleted.
     */
    printf("Test 1: Empty list\n");

    p_list = create_list();

    deleted_count = delete_all_occurrences(p_list, 10);

    printf("Expected deleted count: 0\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 0);
    assert(get_list_length(p_list) == 0);
    assert(is_list_empty(p_list) == true);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 2: Single-element list - matching value
     *
     * [5]
     * Delete 5
     *
     * Expected: []
     * Deleted count = 1
     */
    printf("Test 2: Single-element list - matching value\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 5);

    printf("Expected deleted count: 1\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 1);
    assert(get_list_length(p_list) == 0);
    assert(is_list_empty(p_list) == true);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 3: Single-element list - non-matching value
     *
     * [5]
     * Delete 10
     *
     * Expected: [5]
     * Deleted count = 0
     */
    printf("Test 3: Single-element list - non-matching value\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 10);

    printf("Expected deleted count: 0\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 0);
    assert(get_list_length(p_list) == 1);

    {
        data_t data;

        status = get_start(p_list, &data);
        assert(status == SUCCESS);
        assert(data == 5);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 4: Multiple occurrences
     *
     * [5]->[3]->[5]->[7]->[5]
     * Delete 5
     *
     * Expected: [3]->[7]
     * Deleted count = 3
     */
    printf("Test 4: Delete multiple occurrences\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 5);

    printf("Expected deleted count: 3\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 3);
    assert(get_list_length(p_list) == 2);

    {
        data_t data;

        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == 3);

        assert(get_end(p_list, &data) == SUCCESS);
        assert(data == 7);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 5: Delete all nodes
     *
     * [8]->[8]->[8]->[8]
     * Delete 8
     *
     * Expected: []
     * Deleted count = 4
     */
    printf("Test 5: Delete all nodes\n");

    p_list = create_list();

    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 8);

    printf("Expected deleted count: 4\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 4);
    assert(get_list_length(p_list) == 0);
    assert(is_list_empty(p_list) == true);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 6: Consecutive occurrences
     *
     * [1]->[5]->[5]->[5]->[10]
     * Delete 5
     *
     * Expected: [1]->[10]
     * Deleted count = 3
     *
     * This verifies that consecutive matching nodes are all removed.
     */
    printf("Test 6: Consecutive occurrences\n");

    p_list = create_list();

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 5);

    printf("Expected deleted count: 3\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 3);
    assert(get_list_length(p_list) == 2);

    {
        data_t data;

        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == 1);

        assert(get_end(p_list, &data) == SUCCESS);
        assert(data == 10);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 7: Matching nodes at beginning and end
     *
     * [5]->[10]->[20]->[5]
     * Delete 5
     *
     * Expected: [10]->[20]
     * Deleted count = 2
     */
    printf("Test 7: Matching nodes at beginning and end\n");

    p_list = create_list();

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 5);

    printf("Expected deleted count: 2\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 2);
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
     * Test 8: Zero values
     *
     * [0]->[5]->[0]->[10]->[0]
     * Delete 0
     *
     * Expected: [5]->[10]
     * Deleted count = 3
     */
    printf("Test 8: Zero values\n");

    p_list = create_list();

    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 0);

    printf("Expected deleted count: 3\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 3);
    assert(get_list_length(p_list) == 2);

    {
        data_t data;

        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == 5);

        assert(get_end(p_list, &data) == SUCCESS);
        assert(data == 10);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 9: Negative values
     *
     * [-5]->[-10]->[-5]->[0]->[-5]
     * Delete -5
     *
     * Expected: [-10]->[0]
     * Deleted count = 3
     */
    printf("Test 9: Negative values\n");

    p_list = create_list();

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, -5);

    printf("Expected deleted count: 3\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 3);
    assert(get_list_length(p_list) == 2);

    {
        data_t data;

        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == -10);

        assert(get_end(p_list, &data) == SUCCESS);
        assert(data == 0);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 10: No occurrence
     *
     * [10]->[20]->[30]
     * Delete 99
     *
     * Expected: list unchanged
     * Deleted count = 0
     */
    printf("Test 10: Value not present\n");

    p_list = create_list();

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 99);

    printf("Expected deleted count: 0\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 0);
    assert(get_list_length(p_list) == 3);

    {
        data_t data;

        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == 10);

        assert(get_end(p_list, &data) == SUCCESS);
        assert(data == 30);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 11: Large/small values
     *
     * Verify that the function handles ordinary extreme integer values
     * without requiring arithmetic operations on the data.
     */
    printf("Test 11: Large/small values\n");

    p_list = create_list();

    assert(insert_end(p_list, -1000000) == SUCCESS);
    assert(insert_end(p_list, 1000000) == SUCCESS);
    assert(insert_end(p_list, -1000000) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -1000000) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, -1000000);

    printf("Expected deleted count: 3\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 3);
    assert(get_list_length(p_list) == 2);

    {
        data_t data;

        assert(get_start(p_list, &data) == SUCCESS);
        assert(data == 1000000);

        assert(get_end(p_list, &data) == SUCCESS);
        assert(data == 0);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    /*
     * Test 12: Verify remaining list contents exactly
     *
     * [1]->[2]->[3]->[2]->[4]->[2]->[5]
     * Delete 2
     *
     * Expected: [1]->[3]->[4]->[5]
     * Deleted count = 3
     */
    printf("Test 12: Verify complete remaining list\n");

    p_list = create_list();

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);

    deleted_count = delete_all_occurrences(p_list, 2);

    printf("Expected deleted count: 3\n");
    printf("Actual deleted count:   %d\n", (int)deleted_count);

    assert(deleted_count == 3);
    assert(get_list_length(p_list) == 4);

    {
        data_t* p_array = NULL;
        size_t size = 0;

        status = to_array(p_list, &p_array, &size);

        assert(status == SUCCESS);
        assert(size == 4);

        assert(p_array[0] == 1);
        assert(p_array[1] == 3);
        assert(p_array[2] == 4);
        assert(p_array[3] == 5);

        free(p_array);
    }

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("Passed.\n\n");


    printf("========================================\n");
    printf("All tests passed successfully!\n");
    printf("========================================\n");

    return EXIT_SUCCESS;
}
len_t delete_all_occurrences(list_t* p_list, data_t value)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list->next;
    node_t* run_prev = p_list;
    len_t count = 0;
    while(run != NULL)
    {   
        if(run->data == value)
        {
            count++;
            run_prev->next = run->next;
            free(run);
            run = run_prev->next;
        }
        else {
            run_prev = run;
            run = run->next;
        }
    }
    return count;
}