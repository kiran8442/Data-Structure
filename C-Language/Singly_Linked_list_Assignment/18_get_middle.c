#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/* Exercise function declaration */
status_t get_middle(list_t* p_list, data_t* p_middle);

int main(void)
{
    list_t* p_list = NULL;
    data_t middle;
    status_t result;

    /*
     * Test 1: NULL list
     *
     * There is no list to search, so expect LIST_EMPTY.
     */
    printf("Test 1: NULL list\n");

    middle = 999;

    result = get_middle(NULL, &middle);

    printf("Expected: %d\n", INVALID_LIST);
    printf("Actual:   %s\n",
           result == LIST_EMPTY ? "LIST_EMPTY" : "OTHER");

    assert(result == INVALID_LIST);


    /*
     * Test 2: Empty list
     *
     * Explicit requirement: return LIST_EMPTY.
     */
    printf("\nTest 2: Empty list\n");

    p_list = create_list();
    assert(p_list != NULL);

    middle = 999;

    result = get_middle(p_list, &middle);

    printf("Expected: LIST_EMPTY\n");
    printf("Actual:   %s\n",
           result == LIST_EMPTY ? "LIST_EMPTY" : "OTHER");

    assert(result == LIST_EMPTY);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 3: Single-element list
     *
     * [42]
     *
     * The only element is the middle element.
     */
    printf("\nTest 3: Single-element list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 42) == SUCCESS);

    middle = 0;

    result = get_middle(p_list, &middle);

    printf("List: [42]\n");
    printf("Expected: SUCCESS, middle = 42\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 42);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 4: Odd number of elements
     *
     * [1]->[2]->[3]->[4]->[5]
     *
     * Middle element = 3.
     */
    printf("\nTest 4: Odd number of elements\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);

    middle = 0;

    result = get_middle(p_list, &middle);

    printf("List: [1]->[2]->[3]->[4]->[5]\n");
    printf("Expected: SUCCESS, middle = 3\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 3);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 5: Even number of elements
     *
     * [1]->[2]->[3]->[4]
     *
     * The two middle elements are 2 and 3.
     * Requirement: return the FIRST middle element.
     *
     * Expected middle = 2.
     */
    printf("\nTest 5: Even number of elements\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);
    assert(insert_end(p_list, 3) == SUCCESS);
    assert(insert_end(p_list, 4) == SUCCESS);

    middle = 0;

    result = get_middle(p_list, &middle);

    printf("List: [1]->[2]->[3]->[4]\n");
    printf("Expected: SUCCESS, first middle = 2\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 2);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 6: Two elements
     *
     * [10]->[20]
     *
     * Both 10 and 20 are middle candidates.
     * Requirement says return the FIRST one.
     */
    printf("\nTest 6: Two elements\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    middle = 0;

    result = get_middle(p_list, &middle);

    printf("List: [10]->[20]\n");
    printf("Expected: SUCCESS, middle = 10\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 10);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 7: Six elements
     *
     * [10]->[20]->[30]->[40]->[50]->[60]
     *
     * Middle candidates are 30 and 40.
     * Expected = 30.
     */
    printf("\nTest 7: Six-element list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 60) == SUCCESS);

    middle = 0;

    result = get_middle(p_list, &middle);

    printf("List: [10]->[20]->[30]->[40]->[50]->[60]\n");
    printf("Expected: SUCCESS, first middle = 30\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 30);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 8: Negative and zero values
     *
     * [-10]->[-5]->[0]->[5]->[10]
     *
     * Expected middle = 0.
     */
    printf("\nTest 8: Negative and zero values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    middle = 999;

    result = get_middle(p_list, &middle);

    printf("List: [-10]->[-5]->[0]->[5]->[10]\n");
    printf("Expected: SUCCESS, middle = 0\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 9: Duplicate values
     *
     * [5]->[5]->[10]->[10]->[10]
     *
     * Expected middle = 10.
     */
    printf("\nTest 9: Duplicate values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    middle = 0;

    result = get_middle(p_list, &middle);

    printf("List: [5]->[5]->[10]->[10]->[10]\n");
    printf("Expected: SUCCESS, middle = 10\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 10);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 10: Even number with clearly different middle values
     *
     * [100]->[200]->[300]->[400]->[500]->[600]
     *
     * Middle candidates are 300 and 400.
     * This specifically verifies that the FIRST middle is returned.
     */
    printf("\nTest 10: Verify first middle for even-sized list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 100) == SUCCESS);
    assert(insert_end(p_list, 200) == SUCCESS);
    assert(insert_end(p_list, 300) == SUCCESS);
    assert(insert_end(p_list, 400) == SUCCESS);
    assert(insert_end(p_list, 500) == SUCCESS);
    assert(insert_end(p_list, 600) == SUCCESS);

    middle = 0;

    result = get_middle(p_list, &middle);

    printf("List: [100]->[200]->[300]->[400]->[500]->[600]\n");
    printf("Expected: SUCCESS, first middle = 300\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 300);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /*
     * Test 11: Large list
     *
     * 9 elements -> middle is the 5th element.
     */
    printf("\nTest 11: Larger odd-sized list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 60) == SUCCESS);
    assert(insert_end(p_list, 70) == SUCCESS);
    assert(insert_end(p_list, 80) == SUCCESS);
    assert(insert_end(p_list, 90) == SUCCESS);

    middle = 0;

    result = get_middle(p_list, &middle);

    printf("List: [10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]\n");
    printf("Expected: SUCCESS, middle = 50\n");
    printf("Actual:   %s, middle = %d\n",
           result == SUCCESS ? "SUCCESS" : "OTHER",
           middle);

    assert(result == SUCCESS);
    assert(middle == 50);

    destroy_list(&p_list);
    assert(p_list == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
status_t get_middle(list_t* p_list, data_t* p_middle)
{
    if(p_list == NULL)
        return INVALID_LIST;
    if(p_list->next == NULL)
        return LIST_EMPTY;
    node_t* run = p_list;
    node_t* run_fast = p_list;
    while(run_fast != NULL)
    {
        if(run_fast->next == NULL)
            break;
        run_fast = run_fast->next;
        run_fast = run_fast->next;
        run = run->next;
    }
    *p_middle =  run->data;
    return TRUE;
}