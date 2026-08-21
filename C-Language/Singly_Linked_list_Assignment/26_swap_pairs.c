#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

status_t swap_pairs(list_t* plist);


/*
 * Helper used only by main() to verify the resulting list.
 * It uses the existing public API and does not implement
 * the exercise function.
 */
static void assert_list_contents(list_t* p_list,
                                 const data_t expected[],
                                 size_t expected_size)
{
    data_t* actual = NULL;
    size_t actual_size = 0;
    size_t i;

    assert(p_list != NULL);

    assert(to_array(p_list, &actual, &actual_size) == SUCCESS);
    assert(actual_size == expected_size);

    for (i = 0; i < expected_size; ++i)
    {
        assert(actual[i] == expected[i]);
    }

    free(actual);
}


int main(void)
{
    status_t status;


    /*
     * Test 1: NULL list
     *
     * There are no nodes to swap.
     * NULL is treated as an invalid list.
     */
    printf("Test 1: NULL list\n");

    status = swap_pairs(NULL);

    printf("Expected: INVALID_LIST\n");
    printf("Actual:   %d\n", status);

    assert(status == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * Nothing should be swapped.
     */
    printf("\nTest 2: Empty list\n");

    {
        list_t* p_list = create_list();

        status = swap_pairs(p_list);

        printf("Expected: SUCCESS\n");
        printf("Actual:   %d\n", status);

        assert(status == SUCCESS);
        assert(is_list_empty(p_list) == true);
        assert(get_list_length(p_list) == 0);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 3: Single-element list
     *
     * There is no pair, so the only node must remain unchanged.
     */
    printf("\nTest 3: Single-element list\n");

    {
        list_t* p_list = create_list();
        const data_t expected[] = {42};

        assert(insert_end(p_list, 42) == SUCCESS);

        status = swap_pairs(p_list);

        printf("Expected: SUCCESS, [42]\n");
        printf("Actual:   %d\n", status);

        assert(status == SUCCESS);
        assert_list_contents(p_list, expected, 1);
        assert(get_list_length(p_list) == 1);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 4: Two-element list
     *
     * [1]->[2]
     *
     * Expected:
     * [2]->[1]
     */
    printf("\nTest 4: Two-element list\n");

    {
        list_t* p_list = create_list();
        const data_t expected[] = {2, 1};

        assert(insert_end(p_list, 1) == SUCCESS);
        assert(insert_end(p_list, 2) == SUCCESS);

        status = swap_pairs(p_list);

        printf("Expected: SUCCESS, [2]->[1]\n");
        printf("Actual:   %d\n", status);

        assert(status == SUCCESS);
        assert_list_contents(p_list, expected, 2);
        assert(get_list_length(p_list) == 2);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 5: Even number of nodes
     *
     * [1]->[2]->[3]->[4]
     *
     * Expected:
     * [2]->[1]->[4]->[3]
     */
    printf("\nTest 5: Even number of nodes\n");

    {
        list_t* p_list = create_list();
        const data_t expected[] = {2, 1, 4, 3};

        assert(insert_end(p_list, 1) == SUCCESS);
        assert(insert_end(p_list, 2) == SUCCESS);
        assert(insert_end(p_list, 3) == SUCCESS);
        assert(insert_end(p_list, 4) == SUCCESS);

        status = swap_pairs(p_list);

        printf("Expected: [2]->[1]->[4]->[3]\n");
        printf("Actual status: %d\n", status);

        assert(status == SUCCESS);
        assert_list_contents(p_list, expected, 4);
        assert(get_list_length(p_list) == 4);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 6: Odd number of nodes
     *
     * [1]->[2]->[3]->[4]->[5]
     *
     * Expected:
     * [2]->[1]->[4]->[3]->[5]
     *
     * The final node must remain in place.
     */
    printf("\nTest 6: Odd number of nodes\n");

    {
        list_t* p_list = create_list();
        const data_t expected[] = {2, 1, 4, 3, 5};

        assert(insert_end(p_list, 1) == SUCCESS);
        assert(insert_end(p_list, 2) == SUCCESS);
        assert(insert_end(p_list, 3) == SUCCESS);
        assert(insert_end(p_list, 4) == SUCCESS);
        assert(insert_end(p_list, 5) == SUCCESS);

        status = swap_pairs(p_list);

        printf("Expected: [2]->[1]->[4]->[3]->[5]\n");
        printf("Actual status: %d\n", status);

        assert(status == SUCCESS);
        assert_list_contents(p_list, expected, 5);
        assert(get_list_length(p_list) == 5);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 7: Three-element list
     *
     * Specifically verifies that the last unpaired node
     * remains unchanged.
     *
     * [10]->[20]->[30]
     *
     * Expected:
     * [20]->[10]->[30]
     */
    printf("\nTest 7: Three-element list\n");

    {
        list_t* p_list = create_list();
        const data_t expected[] = {20, 10, 30};

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 20) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);

        status = swap_pairs(p_list);

        printf("Expected: [20]->[10]->[30]\n");
        printf("Actual status: %d\n", status);

        assert(status == SUCCESS);
        assert_list_contents(p_list, expected, 3);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 8: Duplicate values
     *
     * Duplicate data must not affect pair swapping.
     *
     * [5]->[5]->[10]->[10]->[5]
     *
     * Expected:
     * [5]->[5]->[10]->[10]->[5]
     *
     * Although the values look unchanged, the operation
     * must still correctly handle duplicate nodes.
     */
    printf("\nTest 8: Duplicate values\n");

    {
        list_t* p_list = create_list();
        const data_t expected[] = {5, 5, 10, 10, 5};

        assert(insert_end(p_list, 5) == SUCCESS);
        assert(insert_end(p_list, 5) == SUCCESS);
        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, 5) == SUCCESS);

        status = swap_pairs(p_list);

        printf("Expected: [5]->[5]->[10]->[10]->[5]\n");
        printf("Actual status: %d\n", status);

        assert(status == SUCCESS);
        assert_list_contents(p_list, expected, 5);
        assert(get_list_length(p_list) == 5);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 9: Positive, negative and zero values
     *
     * [10]->[-20]->[0]->[30]->[-40]->[50]
     *
     * Expected:
     * [-20]->[10]->[30]->[0]->[50]->[-40]
     */
    printf("\nTest 9: Positive, negative and zero values\n");

    {
        list_t* p_list = create_list();
        const data_t expected[] = {
            -20, 10, 30, 0, 50, -40
        };

        assert(insert_end(p_list, 10) == SUCCESS);
        assert(insert_end(p_list, -20) == SUCCESS);
        assert(insert_end(p_list, 0) == SUCCESS);
        assert(insert_end(p_list, 30) == SUCCESS);
        assert(insert_end(p_list, -40) == SUCCESS);
        assert(insert_end(p_list, 50) == SUCCESS);

        status = swap_pairs(p_list);

        printf("Expected: [-20]->[10]->[30]->[0]->[50]->[-40]\n");
        printf("Actual status: %d\n", status);

        assert(status == SUCCESS);
        assert_list_contents(p_list, expected, 6);
        assert(get_list_length(p_list) == 6);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 10: Larger list
     *
     * Verifies that every adjacent pair is swapped,
     * not just the first one.
     *
     * [1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]
     *
     * Expected:
     * [2]->[1]->[4]->[3]->[6]->[5]->[8]->[7]
     */
    printf("\nTest 10: Larger even list\n");

    {
        list_t* p_list = create_list();
        const data_t expected[] = {
            2, 1, 4, 3, 6, 5, 8, 7
        };

        assert(insert_end(p_list, 1) == SUCCESS);
        assert(insert_end(p_list, 2) == SUCCESS);
        assert(insert_end(p_list, 3) == SUCCESS);
        assert(insert_end(p_list, 4) == SUCCESS);
        assert(insert_end(p_list, 5) == SUCCESS);
        assert(insert_end(p_list, 6) == SUCCESS);
        assert(insert_end(p_list, 7) == SUCCESS);
        assert(insert_end(p_list, 8) == SUCCESS);

        status = swap_pairs(p_list);

        printf("Expected: [2]->[1]->[4]->[3]->[6]->[5]->[8]->[7]\n");
        printf("Actual status: %d\n", status);

        assert(status == SUCCESS);
        assert_list_contents(p_list, expected, 8);
        assert(get_list_length(p_list) == 8);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 11: Verify that the operation preserves all elements
     *
     * The number of nodes must remain unchanged after swapping.
     */
    printf("\nTest 11: Verify node count is preserved\n");

    {
        list_t* p_list = create_list();

        assert(insert_end(p_list, 100) == SUCCESS);
        assert(insert_end(p_list, 200) == SUCCESS);
        assert(insert_end(p_list, 300) == SUCCESS);
        assert(insert_end(p_list, 400) == SUCCESS);
        assert(insert_end(p_list, 500) == SUCCESS);

        assert(get_list_length(p_list) == 5);

        status = swap_pairs(p_list);

        assert(status == SUCCESS);

        /*
         * Swapping nodes must not add or remove nodes.
         */
        assert(get_list_length(p_list) == 5);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    /*
     * Test 12: Verify operation can be performed repeatedly
     *
     * Swapping twice should restore the original ordering.
     */
    printf("\nTest 12: Swap twice restores original order\n");

    {
        list_t* p_list = create_list();
        const data_t original[] = {1, 2, 3, 4, 5, 6};

        assert(insert_end(p_list, 1) == SUCCESS);
        assert(insert_end(p_list, 2) == SUCCESS);
        assert(insert_end(p_list, 3) == SUCCESS);
        assert(insert_end(p_list, 4) == SUCCESS);
        assert(insert_end(p_list, 5) == SUCCESS);
        assert(insert_end(p_list, 6) == SUCCESS);

        status = swap_pairs(p_list);
        assert(status == SUCCESS);

        /*
         * First swap:
         * [2]->[1]->[4]->[3]->[6]->[5]
         */

        status = swap_pairs(p_list);
        assert(status == SUCCESS);

        /*
         * Second swap restores:
         * [1]->[2]->[3]->[4]->[5]->[6]
         */
        assert_list_contents(p_list, original, 6);
        assert(get_list_length(p_list) == 6);

        destroy_list(&p_list);
        assert(p_list == NULL);
    }


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
status_t swap_pairs(list_t* p_list)
{
    if(p_list == NULL)
        return INVALID_LIST;
    
    if(get_list_length(p_list) < 2)  
        return SUCCESS;
    node_t* first = p_list->next;
    node_t* second = first->next;
    node_t* prev = p_list;
    while(first != NULL && second != NULL)
    {
        node_t* third = second->next;

        second->next = first;
        first->next = third;

        if(prev == p_list)
            p_list->next = second;
        else 
            prev->next = second;
        
        prev = first;
        first = third;
        if(third != NULL)
            second = third->next;
        else
            second = NULL;
    }
    return SUCCESS;
}