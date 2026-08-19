#include <assert.h>
#include <limits.h>
#include "list.h"

/*
 * Exercise 6:
 * Count Even Numbers
 *
 * The implementation of count_even() must be provided separately.
 */
int count_even(list_t* p_list);

int main(void)
{
    list_t* p_list = NULL;
    int result;

    /*
     * Test 1: NULL list
     *
     * No nodes exist, so the expected count is 0.
     */
    printf("\nTest 1: NULL list\n");

    result = count_even(NULL);

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

    result = count_even(p_list);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single even element
     *
     * List: [8]
     *
     * Expected count: 1.
     */
    printf("\nTest 3: Single even element\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 8) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 1\n");
    printf("Actual:   %d\n", result);

    assert(result == 1);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Single odd element
     *
     * List: [7]
     *
     * Expected count: 0.
     */
    printf("\nTest 4: Single odd element\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 7) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Exercise example
     *
     * List: [98]->[28]->[3]->[18]->[100]
     *
     * Even values:
     * 98, 28, 18, 100
     *
     * Expected count: 4.
     */
    printf("\nTest 5: Exercise example\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 98) == SUCCESS);
    assert(insert_end(p_list, 28) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 18) == SUCCESS);
    assert(insert_end(p_list, 100) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: All even values
     *
     * List: [2]->[4]->[6]->[8]->[10]
     *
     * Expected count: 5.
     */
    printf("\nTest 6: All even values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);
    assert(insert_end(p_list, 6) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 5\n");
    printf("Actual:   %d\n", result);

    assert(result == 5);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: All odd values
     *
     * List: [1]->[3]->[5]->[7]->[9]
     *
     * Expected count: 0.
     */
    printf("\nTest 7: All odd values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);
    assert(insert_end(p_list, 9) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 0\n");
    printf("Actual:   %d\n", result);

    assert(result == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Mixed positive even and odd values
     *
     * List: [10]->[15]->[22]->[31]->[44]->[51]
     *
     * Even values:
     * 10, 22, 44
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

    result = count_even(p_list);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: Negative even and odd values
     *
     * List: [-10]->[-9]->[-8]->[-7]->[-6]
     *
     * Even values:
     * -10, -8, -6
     *
     * Expected count: 3.
     */
    printf("\nTest 9: Negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -9) == SUCCESS);
    assert(insert_end(p_list, -8) == SUCCESS);
    assert(insert_end(p_list, -7) == SUCCESS);
    assert(insert_end(p_list, -6) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: Zero values
     *
     * Zero is an even number.
     *
     * List: [0]->[1]->[0]->[2]
     *
     * Even values:
     * 0, 0, 2
     *
     * Expected count: 3.
     */
    printf("\nTest 10: Zero values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: Duplicate even values
     *
     * List: [10]->[10]->[5]->[10]->[7]
     *
     * All three occurrences of 10 must be counted.
     *
     * Expected count: 3.
     */
    printf("\nTest 11: Duplicate even values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 7) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 3\n");
    printf("Actual:   %d\n", result);

    assert(result == 3);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: Duplicate odd values
     *
     * List: [5]->[5]->[8]->[5]->[8]
     *
     * Only the two 8 values are even.
     *
     * Expected count: 2.
     */
    printf("\nTest 12: Duplicate odd and even values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 8) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: Mixed negative, zero and positive values
     *
     * List: [-5]->[-4]->[-3]->[-2]->[-1]->[0]->[1]->[2]->[3]
     *
     * Even values:
     * -4, -2, 0, 2
     *
     * Expected count: 4.
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

    result = count_even(p_list);

    printf("Expected: 4\n");
    printf("Actual:   %d\n", result);

    assert(result == 4);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: INT boundary values
     *
     * INT_MIN is even.
     * INT_MAX is odd on normal two's-complement integer systems.
     *
     * List: [INT_MIN]->[INT_MAX]->[0]
     *
     * Expected count: 2.
     */
    printf("\nTest 14: INT boundary values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);

    result = count_even(p_list);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 15: Small negative and positive boundary values
     *
     * List: [INT_MIN]->[INT_MIN + 1]->[INT_MAX - 1]->[INT_MAX]
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

    result = count_even(p_list);

    printf("Expected: 2\n");
    printf("Actual:   %d\n", result);

    assert(result == 2);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
len_t count_even(list_t* p_list)
{
    len_t count = 0;
    if(p_list == NULL)
        return 0;
    
    node_t* run = p_list->next;
    while(run != NULL)
    {
        if(run->data % 2 == 0)
            count++;
        run = run->next;
    }
    return count;
}