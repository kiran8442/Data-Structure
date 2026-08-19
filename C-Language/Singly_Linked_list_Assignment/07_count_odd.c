#include <assert.h>
#include <limits.h>
#include "list.h"

/*
 * Exercise 7:
 * Count Odd Numbers
 *
 * Implement count_odd() separately.
 */
int count_odd(list_t* p_list);

int main(void)
{
    list_t* p_list = NULL;
    int result;

    /*
     * Test 1: NULL list
     *
     * Expected count: 0.
     */
    printf("\nTest 1: NULL list\n");

    result = count_odd(NULL);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);


    /*
     * Test 2: Empty list
     *
     * The list contains only the dummy head node.
     * Expected count: 0.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    result = count_odd(p_list);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single odd element
     *
     * List: [7]
     *
     * Expected count: 1.
     */
    printf("\nTest 3: Single odd element\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 7) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single even element
     *
     * List: [8]
     *
     * Expected count: 0.
     */
    printf("\nTest 4: Single even element\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 8) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Exercise example
     *
     * List: [98]->[23]->[31]->[18]->[100]
     *
     * Odd values:
     * 23, 31
     *
     * Expected count: 2.
     */
    printf("\nTest 5: Exercise example\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 98) == SUCCESS);
    assert(insert_end(p_list, 23) == SUCCESS);
    assert(insert_end(p_list, 31) == SUCCESS);
    assert(insert_end(p_list, 18) == SUCCESS);
    assert(insert_end(p_list, 100) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: All odd values
     *
     * List: [1]->[3]->[5]->[7]->[9]
     *
     * Expected count: 5.
     */
    printf("\nTest 6: All odd values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 9) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 5\n");
    printf("Actual:   %d\n", result);

    assert(result == 5);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: All even values
     *
     * List: [2]->[4]->[6]->[8]->[10]
     *
     * Expected count: 0.
     */
    printf("\nTest 7: All even values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);
    assert(insert_end(p_list, 6) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Mixed positive odd/even values
     *
     * List: [10]->[15]->[22]->[31]->[44]->[51]
     *
     * Odd values:
     * 15, 31, 51
     *
     * Expected count: 3.
     */
    printf("\nTest 8: Mixed positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 15) == SUCCESS);
    assert(insert_end(p_list, 22) == SUCCESS);
    assert(insert_end(p_list, 31) == SUCCESS);
    assert(insert_end(p_list, 44) == SUCCESS);
    assert(insert_end(p_list, 51) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: Negative values
     *
     * List: [-10]->[-9]->[-8]->[-7]->[-6]
     *
     * Odd values:
     * -9, -7
     *
     * Expected count: 2.
     */
    printf("\nTest 9: Negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -9) == SUCCESS);
    assert(insert_end(p_list, -8) == SUCCESS);
    assert(insert_end(p_list, -7) == SUCCESS);
    assert(insert_end(p_list, -6) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: Zero values
     *
     * Zero is EVEN and therefore must NOT be counted.
     *
     * List: [0]->[1]->[0]->[3]->[2]
     *
     * Odd values:
     * 1, 3
     *
     * Expected count: 2.
     */
    printf("\nTest 10: Zero values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: Duplicate odd values
     *
     * List: [5]->[5]->[8]->[5]->[8]
     *
     * Three occurrences of 5 must all be counted.
     *
     * Expected count: 3.
     */
    printf("\nTest 11: Duplicate odd values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: Duplicate even and odd values
     *
     * List: [10]->[10]->[11]->[11]->[11]
     *
     * Three occurrences of 11 must be counted.
     *
     * Expected count: 3.
     */
    printf("\nTest 12: Duplicate even and odd values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 11) == SUCCESS);
    assert(insert_end(p_list, 11) == SUCCESS);
    assert(insert_end(p_list, 11) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: Mixed negative, zero and positive values
     *
     * List: [-5]->[-4]->[-3]->[-2]->[-1]->[0]->[1]->[2]->[3]
     *
     * Odd values:
     * -5, -3, -1, 1, 3
     *
     * Expected count: 5.
     */
    printf("\nTest 13: Negative, zero and positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, -4) == SUCCESS);
    assert(insert_end(p_list, -3) == SUCCESS);
    assert(insert_end(p_list, -2) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 5\n");
    printf("Actual:   %d\n", result);

    assert(result == 5);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: INT boundary values
     *
     * INT_MIN is even.
     * INT_MAX is odd on the standard two's-complement systems
     * targeted by this exercise.
     *
     * List: [INT_MIN]->[INT_MAX]->[0]
     *
     * Expected count: 1.
     */
    printf("\nTest 14: INT boundary values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 15: Boundary-adjacent values
     *
     * INT_MIN       -> even
     * INT_MIN + 1   -> odd
     * INT_MAX - 1   -> even
     * INT_MAX       -> odd
     *
     * Expected count: 2.
     */
    printf("\nTest 15: Boundary-adjacent values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, INT_MIN + 1) == SUCCESS);
    assert(insert_end(p_list, INT_MAX - 1) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    result = count_odd(p_list);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
len_t count_odd(list_t* p_list)
{
    len_t count = 0;
    if(p_list == NULL || p_list->next == NULL)
        return 0;
    
    node_t* run = p_list->next;
    while(run != NULL)
    {
        if(run->data % 2 != 0)
            count++;
        run = run->next;
    }
    return count;
}