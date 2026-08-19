#include <assert.h>
#include <limits.h>
#include "list.h"

/*
 * Exercise 4:
 * Find Maximum Element
 *
 * The implementation of get_max() must be provided separately.
 */
status_t get_max(list_t* plist, data_t* p_max);

int main(void)
{
    list_t* p_list = NULL;
    data_t max_value;
    status_t status;

    /*
     * Test 1: NULL list
     *
     * A NULL list is a reasonable defensive-input case.
     * Expected: LIST_EMPTY.
     */
    printf("\nTest 1: NULL list\n");

    max_value = 12345;

    status = get_max(NULL, &max_value);

    printf("Expected status: LIST_EMPTY\n");
    printf("Actual status:   %d\n", status);

    assert(status == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * The list contains only the dummy head node.
     * Expected: LIST_EMPTY.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(is_list_empty(p_list) == true);

    max_value = 12345;

    status = get_max(p_list, &max_value);

    printf("Expected status: LIST_EMPTY\n");
    printf("Actual status:   %d\n", status);

    assert(status == LIST_EMPTY);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 3: Single-element list
     *
     * List: [42]
     *
     * Expected:
     * status = SUCCESS
     * max_value = 42
     */
    printf("\nTest 3: Single element\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 42) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    42\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == 42);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Multiple elements
     *
     * List: [45]->[42]->[78]->[34]
     *
     * Expected maximum: 78.
     */
    printf("\nTest 4: Multiple elements\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 45) == SUCCESS);
    assert(insert_end(p_list, 42) == SUCCESS);
    assert(insert_end(p_list, 78) == SUCCESS);
    assert(insert_end(p_list, 34) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    78\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == 78);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Maximum is the first element
     *
     * List: [100]->[20]->[30]->[40]
     *
     * Expected maximum: 100.
     */
    printf("\nTest 5: Maximum at first node\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 100) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    100\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == 100);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Maximum is the last element
     *
     * List: [10]->[20]->[30]->[100]
     *
     * Expected maximum: 100.
     */
    printf("\nTest 6: Maximum at last node\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 100) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    100\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == 100);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Negative values
     *
     * List: [-50]->[-10]->[-100]->[-20]
     *
     * The maximum is -10.
     */
    printf("\nTest 7: Negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -50) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -100) == SUCCESS);
    assert(insert_end(p_list, -20) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    -10\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == -10);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Negative, zero and positive values
     *
     * List: [-20]->[-5]->[0]->[10]->[-1]
     *
     * Expected maximum: 10.
     */
    printf("\nTest 8: Negative, zero and positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    10\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == 10);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: All elements are negative
     *
     * This verifies that the implementation does not incorrectly
     * initialize the maximum to zero.
     *
     * List: [-100]->[-50]->[-200]->[-10]
     *
     * Expected maximum: -10.
     */
    printf("\nTest 9: All negative elements\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -100) == SUCCESS);
    assert(insert_end(p_list, -50) == SUCCESS);
    assert(insert_end(p_list, -200) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    -10\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == -10);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: Duplicate maximum values
     *
     * List: [10]->[50]->[20]->[50]->[30]
     *
     * Maximum occurs more than once.
     * Expected maximum: 50.
     */
    printf("\nTest 10: Duplicate maximum values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    50\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == 50);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: All elements are equal
     *
     * List: [25]->[25]->[25]->[25]
     *
     * Expected maximum: 25.
     */
    printf("\nTest 11: All elements equal\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    25\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == 25);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: Zero values
     *
     * List: [-10]->[0]->[-5]->[0]
     *
     * Expected maximum: 0.
     */
    printf("\nTest 12: Zero values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);

    max_value = -100;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    0\n");
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: INT_MIN and INT_MAX
     *
     * List: [INT_MIN]->[0]->[INT_MAX]
     *
     * Expected maximum: INT_MAX.
     */
    printf("\nTest 13: INT boundary values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    %d\n", INT_MAX);
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == INT_MAX);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: INT_MIN is the maximum
     *
     * Every element has the value INT_MIN.
     *
     * Expected maximum: INT_MIN.
     *
     * This is important because INT_MIN is smaller than every
     * other int value, but it is still the correct maximum when
     * every node contains INT_MIN.
     */
    printf("\nTest 14: INT_MIN as maximum\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, INT_MIN) == SUCCESS);

    max_value = 0;

    status = get_max(p_list, &max_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected max:    %d\n", INT_MIN);
    printf("Actual max:      %d\n", max_value);

    assert(status == SUCCESS);
    assert(max_value == INT_MIN);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
status_t get_max(list_t* p_list, data_t* p_max)
{

    if(p_list == NULL)
        return INVALID_LIST;
    if(p_list->next == NULL)
        return LIST_EMPTY;
    node_t* run = p_list->next;
    int max = INT_MIN;
    while(run != NULL)
    {
        if(run->data > max)
            max = run->data;
        run = run->next;
    }
    *p_max = max;
    return SUCCESS;
}