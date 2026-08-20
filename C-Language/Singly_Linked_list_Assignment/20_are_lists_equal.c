#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/* Exercise function declaration */
status_t are_lists_equal(list_t* p_list_a, list_t* p_list_b);

int main(void)
{
    list_t* p_list_a = NULL;
    list_t* p_list_b = NULL;
    status_t result;

    /*
     * Test 1: Both lists are empty.
     *
     * Two empty lists have the same length and no differing data.
     */
    printf("Test 1: Both lists empty\n");

    p_list_a = create_list();
    p_list_b = create_list();

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);

    assert(p_list_a == NULL);
    assert(p_list_b == NULL);


    /*
     * Test 2: Both lists contain the same single element.
     */
    printf("Test 2: Equal single-element lists\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_b, 10) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);

    assert(p_list_a == NULL);
    assert(p_list_b == NULL);


    /*
     * Test 3: Single-element lists with different values.
     */
    printf("Test 3: Different single-element lists\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_b, 20) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: FALSE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == FALSE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 4: Identical multiple-element lists.
     *
     * [10]->[20]->[30]->[40]
     * [10]->[20]->[30]->[40]
     */
    printf("Test 4: Identical multiple-element lists\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_a, 20) == SUCCESS);
    assert(insert_end(p_list_a, 30) == SUCCESS);
    assert(insert_end(p_list_a, 40) == SUCCESS);

    assert(insert_end(p_list_b, 10) == SUCCESS);
    assert(insert_end(p_list_b, 20) == SUCCESS);
    assert(insert_end(p_list_b, 30) == SUCCESS);
    assert(insert_end(p_list_b, 40) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 5: Same values but different order.
     *
     * [10]->[20]->[30]
     * [30]->[20]->[10]
     *
     * Lists are NOT equal because position matters.
     */
    printf("Test 5: Same values in different order\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_a, 20) == SUCCESS);
    assert(insert_end(p_list_a, 30) == SUCCESS);

    assert(insert_end(p_list_b, 30) == SUCCESS);
    assert(insert_end(p_list_b, 20) == SUCCESS);
    assert(insert_end(p_list_b, 10) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: FALSE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == FALSE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 6: Same prefix but different lengths.
     *
     * [10]->[20]->[30]
     * [10]->[20]
     *
     * Same first elements are not enough; lengths must match.
     */
    printf("Test 6: Same prefix but different lengths\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_a, 20) == SUCCESS);
    assert(insert_end(p_list_a, 30) == SUCCESS);

    assert(insert_end(p_list_b, 10) == SUCCESS);
    assert(insert_end(p_list_b, 20) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: FALSE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == FALSE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 7: Duplicate values.
     *
     * Duplicate values at the same positions should be considered equal.
     */
    printf("Test 7: Equal lists containing duplicates\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 5) == SUCCESS);
    assert(insert_end(p_list_a, 5) == SUCCESS);
    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_a, 5) == SUCCESS);

    assert(insert_end(p_list_b, 5) == SUCCESS);
    assert(insert_end(p_list_b, 5) == SUCCESS);
    assert(insert_end(p_list_b, 10) == SUCCESS);
    assert(insert_end(p_list_b, 10) == SUCCESS);
    assert(insert_end(p_list_b, 5) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 8: Duplicate values at different positions.
     */
    printf("Test 8: Different duplicate positions\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 5) == SUCCESS);
    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_a, 5) == SUCCESS);

    assert(insert_end(p_list_b, 5) == SUCCESS);
    assert(insert_end(p_list_b, 5) == SUCCESS);
    assert(insert_end(p_list_b, 10) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: FALSE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == FALSE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 9: Negative values and zero.
     */
    printf("Test 9: Negative values and zero\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, -10) == SUCCESS);
    assert(insert_end(p_list_a, -5) == SUCCESS);
    assert(insert_end(p_list_a, 0) == SUCCESS);
    assert(insert_end(p_list_a, 5) == SUCCESS);
    assert(insert_end(p_list_a, 10) == SUCCESS);

    assert(insert_end(p_list_b, -10) == SUCCESS);
    assert(insert_end(p_list_b, -5) == SUCCESS);
    assert(insert_end(p_list_b, 0) == SUCCESS);
    assert(insert_end(p_list_b, 5) == SUCCESS);
    assert(insert_end(p_list_b, 10) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 10: Same length but one element differs.
     */
    printf("Test 10: One differing element\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 10) == SUCCESS);
    assert(insert_end(p_list_a, 20) == SUCCESS);
    assert(insert_end(p_list_a, 30) == SUCCESS);
    assert(insert_end(p_list_a, 40) == SUCCESS);

    assert(insert_end(p_list_b, 10) == SUCCESS);
    assert(insert_end(p_list_b, 20) == SUCCESS);
    assert(insert_end(p_list_b, 35) == SUCCESS);
    assert(insert_end(p_list_b, 40) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: FALSE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == FALSE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 11: Both lists contain a single zero.
     */
    printf("Test 11: Single zero values\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, 0) == SUCCESS);
    assert(insert_end(p_list_b, 0) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 12: Large/small values.
     *
     * Values remain within a conservative range to avoid
     * assumptions about the exact size of data_t.
     */
    printf("Test 12: Large and small values\n");

    p_list_a = create_list();
    p_list_b = create_list();

    assert(insert_end(p_list_a, -1000000) == SUCCESS);
    assert(insert_end(p_list_a, 0) == SUCCESS);
    assert(insert_end(p_list_a, 1000000) == SUCCESS);

    assert(insert_end(p_list_b, -1000000) == SUCCESS);
    assert(insert_end(p_list_b, 0) == SUCCESS);
    assert(insert_end(p_list_b, 1000000) == SUCCESS);

    result = are_lists_equal(p_list_a, p_list_b);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);

    destroy_list(&p_list_a);
    destroy_list(&p_list_b);


    /*
     * Test 13: NULL and NULL.
     *
     * This assumes NULL is treated as an empty list.
     */
    printf("Test 13: Both lists NULL\n");

    result = are_lists_equal(NULL, NULL);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);


    /*
     * Test 14: NULL versus an empty list.
     *
     * This assumes NULL is treated as an empty list.
     */
    printf("Test 14: NULL versus empty list\n");

    p_list_b = create_list();

    result = are_lists_equal(NULL, p_list_b);

    printf("Expected: TRUE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == TRUE);

    destroy_list(&p_list_b);
    assert(p_list_b == NULL);


    /*
     * Test 15: NULL versus a non-empty list.
     *
     * This assumes NULL represents an empty list.
     */
    printf("Test 15: NULL versus non-empty list\n");

    p_list_b = create_list();
    assert(insert_end(p_list_b, 10) == SUCCESS);

    result = are_lists_equal(NULL, p_list_b);

    printf("Expected: FALSE, Actual: %s\n",
           result == TRUE ? "TRUE" : "FALSE");
    assert(result == FALSE);

    destroy_list(&p_list_b);
    assert(p_list_b == NULL);


    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
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