#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/*
 * Exercise function to be implemented manually.
 * DO NOT implement this function here.
 */
status_t delete_at_position(list_t* plist, int position);


int main(void)
{
    list_t* p_list = NULL;
    status_t status;
    data_t data;


    /* ============================================================
     * Test 1: Empty list
     *
     * Deleting from an empty list must return LIST_EMPTY.
     * ============================================================ */
    printf("\nTest 1: Delete from empty list\n");

    p_list = create_list();
    assert(p_list != NULL);
    assert(is_list_empty(p_list) == TRUE);

    status = delete_at_position(p_list, 0);

    printf("Expected status: LIST_EMPTY\n");
    printf("Actual status:   %d\n", status);

    assert(status == LIST_EMPTY);
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 2: Negative position
     *
     * Negative positions are invalid.
     * ============================================================ */
    printf("\nTest 2: Negative position\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = delete_at_position(p_list, -1);

    printf("Expected status: LIST_DATA_NOT_FOUND\n");
    printf("Actual status:   %d\n", status);

    assert(status == LIST_DATA_NOT_FOUND);

    /* Verify list was not modified. */
    assert(get_list_length(p_list) == 3);

    show_list(p_list, "List after rejected deletion: ");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 3: Position greater than list length
     *
     * Existing length = 3
     * Position = 3
     *
     * Valid positions are 0, 1, 2.
     * ============================================================ */
    printf("\nTest 3: Position equal to list length\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = delete_at_position(p_list, 3);

    printf("Expected status: LIST_DATA_NOT_FOUND\n");
    printf("Actual status:   %d\n", status);

    assert(status == LIST_DATA_NOT_FOUND);
    assert(get_list_length(p_list) == 3);

    show_list(p_list, "List after rejected deletion: ");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 4: Position greater than list length
     *
     * Position is clearly outside the valid range.
     * ============================================================ */
    printf("\nTest 4: Position greater than list length\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = delete_at_position(p_list, 10);

    printf("Expected status: LIST_DATA_NOT_FOUND\n");
    printf("Actual status:   %d\n", status);

    assert(status == LIST_DATA_NOT_FOUND);
    assert(get_list_length(p_list) == 3);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 5: Delete first element
     *
     * [10]->[20]->[30]
     * Delete position 0
     *
     * Expected:
     * [20]->[30]
     * ============================================================ */
    printf("\nTest 5: Delete first element\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = delete_at_position(p_list, 0);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 2);

    status = get_start(p_list, &data);
    assert(status == SUCCESS);
    assert(data == 20);

    show_list(p_list, "Expected: [20]->[30]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 6: Delete middle element
     *
     * [10]->[20]->[30]->[40]
     * Delete position 1
     *
     * Expected:
     * [10]->[30]->[40]
     * ============================================================ */
    printf("\nTest 6: Delete middle element\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    status = delete_at_position(p_list, 1);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 3);

    show_list(p_list, "Expected: [10]->[30]->[40]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 7: Delete last element
     *
     * [10]->[20]->[30]
     * Delete position 2
     *
     * Expected:
     * [10]->[20]
     * ============================================================ */
    printf("\nTest 7: Delete last element\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = delete_at_position(p_list, 2);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 2);

    status = get_end(p_list, &data);
    assert(status == SUCCESS);
    assert(data == 20);

    show_list(p_list, "Expected: [10]->[20]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 8: Single-element list
     *
     * [50]
     * Delete position 0
     *
     * Expected: empty list
     * ============================================================ */
    printf("\nTest 8: Delete only element\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);

    status = delete_at_position(p_list, 0);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);

    assert(status == SUCCESS);
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 9: Duplicate values
     *
     * [5]->[5]->[5]->[10]
     * Delete position 1
     *
     * Expected:
     * [5]->[5]->[10]
     *
     * This confirms deletion is position-based rather than
     * value-based.
     * ============================================================ */
    printf("\nTest 9: Delete with duplicate values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);

    status = delete_at_position(p_list, 1);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 3);

    show_list(p_list, "Expected: [5]->[5]->[10]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 10: Negative and zero data values
     *
     * [10]->[0]->[-10]->[20]
     * Delete position 2
     *
     * Expected:
     * [10]->[0]->[20]
     * ============================================================ */
    printf("\nTest 10: Negative and zero data values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    status = delete_at_position(p_list, 2);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 3);

    show_list(p_list, "Expected: [10]->[0]->[20]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 11: Repeated deletion
     *
     * Delete elements from different positions until the list
     * becomes empty.
     *
     * [10]->[20]->[30]->[40]->[50]
     * ============================================================ */
    printf("\nTest 11: Repeated deletion\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);

    /* Delete first element. */
    status = delete_at_position(p_list, 0);
    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 4);

    /* Delete middle element. */
    status = delete_at_position(p_list, 1);
    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 3);

    /* Delete last element. */
    status = delete_at_position(p_list, 2);
    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 2);

    /* Delete first element. */
    status = delete_at_position(p_list, 0);
    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 1);

    /* Delete the final element. */
    status = delete_at_position(p_list, 0);
    assert(status == SUCCESS);
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);

    show_list(p_list, "Expected: empty list");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 12: Invalid deletion after list becomes empty
     *
     * Once empty, any position should return LIST_EMPTY.
     * ============================================================ */
    printf("\nTest 12: Invalid deletion after list becomes empty\n");

    p_list = create_list();
    assert(p_list != NULL);

    status = delete_at_position(p_list, 5);

    printf("Expected status: LIST_EMPTY\n");
    printf("Actual status:   %d\n", status);

    assert(status == LIST_EMPTY);
    assert(is_list_empty(p_list) == TRUE);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 13: Large/small valid data values
     *
     * Tests the operation with larger magnitude values without
     * performing arithmetic on them.
     * ============================================================ */
    printf("\nTest 13: Large/small data values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, (data_t)-1000000) == SUCCESS);
    assert(insert_end(p_list, (data_t)0) == SUCCESS);
    assert(insert_end(p_list, (data_t)1000000) == SUCCESS);

    status = delete_at_position(p_list, 1);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);

    assert(status == SUCCESS);
    assert(get_list_length(p_list) == 2);

    show_list(p_list, "Expected: [-1000000]->[1000000]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * NULL list
     *
     * The exercise does not specify behavior for plist == NULL,
     * so no NULL-list call is made. This avoids assuming a return
     * value that is not part of the exercise contract.
     * ============================================================ */


    printf("\n========================================\n");
    printf("All tests passed successfully!\n");
    printf("========================================\n");

    return EXIT_SUCCESS;
}
status_t delete_at_position(list_t* p_list, int position)
{
    if(p_list == NULL)
        return INVALID_LIST;
    if(p_list->next == NULL)
        return LIST_EMPTY;
    node_t* run = p_list->next;
    node_t* run_prev = p_list;
    int index = 0;
    while(run != NULL)
    {   
        if(index == position)
            break;
        run_prev = run;
        run = run->next;
        index++;
    }
    if(run == NULL)
        return LIST_DATA_NOT_FOUND;
    run_prev->next = run->next;
    free(run);
    return SUCCESS;
}