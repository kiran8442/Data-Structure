#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/*
 * Exercise 1:
 * Sum of All Elements
 *
 * Function to be implemented in list.c:
 *
 * data_t get_sum(list_t* p_list);
 */

data_t get_sum(list_t* p_list);


int main(void)
{
    list_t* p_list = NULL;
    data_t sum = 0;
    status_t status;


    /* =========================================
     * Test 1: NULL list
     *
     * Corner case:
     * p_list == NULL
     *
     * Expected:
     * get_sum(NULL) == 0
     * ========================================= */

    printf("Test 1: NULL list\n");

    sum = get_sum(NULL);

    printf("Expected: 0\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == INVALID_LIST);


    /* =========================================
     * Create an empty list
     * ========================================= */

    p_list = create_list();

    assert(p_list != NULL);


    /* =========================================
     * Test 2: Empty list
     *
     * Expected:
     * get_sum(empty list) == 0
     * ========================================= */

    printf("Test 2: Empty list\n");

    assert(is_list_empty(p_list) == TRUE);

    sum = get_sum(p_list);

    printf("Expected: 0\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == 0);


    /* =========================================
     * Test 3: Single element
     *
     * List:
     * 10
     *
     * Expected:
     * 10
     * ========================================= */

    status = insert_end(p_list, 10);

    assert(status == SUCCESS);

    printf("Test 3: Single element\n");

    show_list(p_list, "List:");

    sum = get_sum(p_list);

    printf("Expected: 10\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == 10);


    /* =========================================
     * Test 4: Multiple positive elements
     *
     * List:
     * 10 -> 20 -> 30 -> 40 -> 50
     *
     * Expected:
     * 150
     * ========================================= */

    status = insert_end(p_list, 20);
    assert(status == SUCCESS);

    status = insert_end(p_list, 30);
    assert(status == SUCCESS);

    status = insert_end(p_list, 40);
    assert(status == SUCCESS);

    status = insert_end(p_list, 50);
    assert(status == SUCCESS);

    printf("Test 4: Multiple positive elements\n");

    show_list(p_list, "List:");

    sum = get_sum(p_list);

    printf("Expected: 150\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == 150);


    /* =========================================
     * Test 5: Positive and negative elements
     *
     * Clear current list and create:
     *
     * 10 -> -20 -> 30 -> -40 -> 50
     *
     * Expected:
     * 30
     * ========================================= */

    destroy_list(&p_list);

    p_list = create_list();

    assert(p_list != NULL);

    insert_end(p_list, 10);
    insert_end(p_list, -20);
    insert_end(p_list, 30);
    insert_end(p_list, -40);
    insert_end(p_list, 50);

    printf("Test 5: Positive and negative elements\n");

    show_list(p_list, "List:");

    sum = get_sum(p_list);

    printf("Expected: 30\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == 30);


    /* =========================================
     * Test 6: All negative elements
     *
     * List:
     * -10 -> -20 -> -30
     *
     * Expected:
     * -60
     * ========================================= */

    destroy_list(&p_list);

    p_list = create_list();

    insert_end(p_list, -10);
    insert_end(p_list, -20);
    insert_end(p_list, -30);

    printf("Test 6: All negative elements\n");

    show_list(p_list, "List:");

    sum = get_sum(p_list);

    printf("Expected: -60\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == -60);


    /* =========================================
     * Test 7: Elements containing zero
     *
     * List:
     * 0 -> 10 -> 0 -> 20 -> 0
     *
     * Expected:
     * 30
     * ========================================= */

    destroy_list(&p_list);

    p_list = create_list();

    insert_end(p_list, 0);
    insert_end(p_list, 10);
    insert_end(p_list, 0);
    insert_end(p_list, 20);
    insert_end(p_list, 0);

    printf("Test 7: Elements containing zero\n");

    show_list(p_list, "List:");

    sum = get_sum(p_list);

    printf("Expected: 30\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == 30);


    /* =========================================
     * Test 8: All zero elements
     *
     * List:
     * 0 -> 0 -> 0
     *
     * Expected:
     * 0
     * ========================================= */

    destroy_list(&p_list);

    p_list = create_list();

    insert_end(p_list, 0);
    insert_end(p_list, 0);
    insert_end(p_list, 0);

    printf("Test 8: All zero elements\n");

    show_list(p_list, "List:");

    sum = get_sum(p_list);

    printf("Expected: 0\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == 0);


    /* =========================================
     * Test 9: Large number of elements
     *
     * 1 -> 2 -> 3 -> ... -> 100
     *
     * Sum = 5050
     * ========================================= */

    destroy_list(&p_list);

    p_list = create_list();

    for (data_t data = 1; data <= 100; data++)
    {
        status = insert_end(p_list, data);

        assert(status == SUCCESS);
    }

    printf("Test 9: 1 to 100\n");

    sum = get_sum(p_list);

    printf("Expected: 5050\n");
    printf("Actual  : %d\n\n", sum);

    assert(sum == 5050);


    /* =========================================
     * Cleanup
     * ========================================= */

    status = destroy_list(&p_list);

    assert(status == SUCCESS);
    assert(p_list == NULL);

    printf("All tests passed successfully!\n");

    return EXIT_SUCCESS;
}
data_t get_sum(list_t* p_list)
{
    data_t total_sum  = 0;
    if(p_list == NULL)
        return INVALID_LIST;
    node_t* run = p_list->next;
    while(run != NULL)
    {
        total_sum = total_sum + run->data;
        run = run->next;
    }
    return total_sum;
}