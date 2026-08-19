#include <assert.h>
#include <limits.h>
#include "list.h"

/*
 * Exercise 5:
 * Find Minimum Element
 *
 * The implementation of get_min() must be provided separately.
 */
status_t get_min(list_t* plist, data_t* p_min);

int main(void)
{
    list_t* p_list = NULL;
    data_t min_value;
    status_t status;

    /*
     * Test 1: NULL list
     *
     * Expected: LIST_EMPTY.
     */
    printf("\nTest 1: NULL list\n");

    min_value = 12345;

    status = get_min(NULL, &min_value);

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

    min_value = 12345;

    status = get_min(p_list, &min_value);

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
     * Expected minimum: 42.
     */
    printf("\nTest 3: Single element\n");

    p_list = create_list();

    assert(p_list != NULL);
    assert(insert_end(p_list, 42) == SUCCESS);

    min_value = 0;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    42\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == 42);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 4: Multiple elements
     *
     * List: [45]->[42]->[78]->[34]
     *
     * Expected minimum: 34.
     *
     * Note:
     * The PDF sample output says 12, but that is inconsistent
     * with the supplied input. The correct minimum is 34.
     */
    printf("\nTest 4: Multiple elements / exercise example\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 45) == SUCCESS);
    assert(insert_end(p_list, 42) == SUCCESS);
    assert(insert_end(p_list, 78) == SUCCESS);
    assert(insert_end(p_list, 34) == SUCCESS);

    min_value = 0;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    34\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == 34);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 5: Minimum at the first node
     *
     * List: [10]->[20]->[30]->[40]
     *
     * Expected minimum: 10.
     */
    printf("\nTest 5: Minimum at first node\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    min_value = 999;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    10\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == 10);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 6: Minimum at the last node
     *
     * List: [40]->[30]->[20]->[10]
     *
     * Expected minimum: 10.
     */
    printf("\nTest 6: Minimum at last node\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    min_value = 999;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    10\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == 10);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 7: Negative values
     *
     * List: [-50]->[-10]->[-100]->[-20]
     *
     * Expected minimum: -100.
     */
    printf("\nTest 7: Negative values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -50) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -100) == SUCCESS);
    assert(insert_end(p_list, -20) == SUCCESS);

    min_value = 0;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    -100\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == -100);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 8: Negative, zero and positive values
     *
     * List: [-20]->[-5]->[0]->[10]->[-1]
     *
     * Expected minimum: -20.
     */
    printf("\nTest 8: Negative, zero and positive values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, -1) == SUCCESS);

    min_value = 100;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    -20\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == -20);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 9: All elements are positive
     *
     * List: [100]->[50]->[200]->[10]
     *
     * Expected minimum: 10.
     */
    printf("\nTest 9: All positive elements\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 100) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 200) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    min_value = -1;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    10\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == 10);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 10: All elements are negative
     *
     * Important because initializing the minimum to zero would
     * produce an incorrect result.
     *
     * List: [-100]->[-50]->[-200]->[-10]
     *
     * Expected minimum: -200.
     */
    printf("\nTest 10: All negative elements\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, -100) == SUCCESS);
    assert(insert_end(p_list, -50) == SUCCESS);
    assert(insert_end(p_list, -200) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);

    min_value = 0;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    -200\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == -200);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 11: Duplicate minimum values
     *
     * List: [50]->[10]->[30]->[10]->[40]
     *
     * Minimum occurs more than once.
     * Expected minimum: 10.
     */
    printf("\nTest 11: Duplicate minimum values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    min_value = 0;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    10\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == 10);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 12: All elements are equal
     *
     * List: [25]->[25]->[25]->[25]
     *
     * Expected minimum: 25.
     */
    printf("\nTest 12: All elements equal\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);
    assert(insert_end(p_list, 25) == SUCCESS);

    min_value = -100;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    25\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == 25);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 13: Zero values
     *
     * List: [10]->[0]->[5]->[0]
     *
     * Expected minimum: 0.
     */
    printf("\nTest 13: Zero values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);

    min_value = 100;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    0\n");
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == 0);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 14: INT boundary values
     *
     * List: [INT_MAX]->[0]->[INT_MIN]
     *
     * Expected minimum: INT_MIN.
     */
    printf("\nTest 14: INT boundary values\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MAX) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, INT_MIN) == SUCCESS);

    min_value = 0;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    %d\n", INT_MIN);
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == INT_MIN);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 15: INT_MAX is the minimum
     *
     * Every node contains INT_MAX.
     *
     * Expected minimum: INT_MAX.
     */
    printf("\nTest 15: INT_MAX as minimum\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MAX) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);
    assert(insert_end(p_list, INT_MAX) == SUCCESS);

    min_value = 0;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    %d\n", INT_MAX);
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == INT_MAX);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    /*
     * Test 16: INT_MIN is the minimum
     *
     * Every node contains INT_MIN.
     *
     * Expected minimum: INT_MIN.
     */
    printf("\nTest 16: INT_MIN as minimum\n");

    p_list = create_list();

    assert(p_list != NULL);

    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, INT_MIN) == SUCCESS);
    assert(insert_end(p_list, INT_MIN) == SUCCESS);

    min_value = 0;

    status = get_min(p_list, &min_value);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    printf("Expected min:    %d\n", INT_MIN);
    printf("Actual min:      %d\n", min_value);

    assert(status == SUCCESS);
    assert(min_value == INT_MIN);

    assert(destroy_list(&p_list) == SUCCESS);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
status_t get_min(list_t* p_list, data_t* p_max)
{
    len_t count  = 0;

    if(p_list == NULL)
        return INVALID_LIST;
    if(p_list->next == NULL)
        return LIST_EMPTY;
    node_t* run = p_list->next;
    int max = INT_MAX;
    while(run != NULL)
    {
        if(run->data < max)
            max = run->data;
        run = run->next;
    }
    *p_max = max;
    return SUCCESS;
}