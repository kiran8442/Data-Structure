#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/*
 * Exercise function to be implemented manually.
 * DO NOT implement this function here.
 */
status_t insert_at_position(list_t* plist, data_t new_data, int position);


int main(void)
{
    list_t* p_list = NULL;
    status_t status;
    data_t data;


    /* ============================================================
     * Test 1: Empty list - position 0
     *
     * Position 0 is valid even when the list is empty.
     * Expected: new node becomes the first element.
     * ============================================================ */
    printf("\nTest 1: Insert into empty list at position 0\n");

    p_list = create_list();
    assert(p_list != NULL);
    assert(is_list_empty(p_list) == TRUE);

    status = insert_at_position(p_list, 10, 0);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    assert(status == SUCCESS);

    assert(get_list_length(p_list) == 1);

    status = get_start(p_list, &data);
    assert(status == SUCCESS);
    assert(data == 10);

    show_list(p_list, "List after insertion: ");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 2: Empty list - invalid position 1
     *
     * Position greater than list length must fail.
     * ============================================================ */
    printf("\nTest 2: Insert into empty list at position 1\n");

    p_list = create_list();
    assert(p_list != NULL);

    status = insert_at_position(p_list, 10, 1);

    printf("Expected status: LIST_DATA_NOT_FOUND\n");
    printf("Actual status:   %d\n", status);
    assert(status == LIST_DATA_NOT_FOUND);

    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 3: Negative position
     *
     * Any negative position must be rejected.
     * ============================================================ */
    printf("\nTest 3: Negative position\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = insert_at_position(p_list, 99, -1);

    printf("Expected status: LIST_DATA_NOT_FOUND\n");
    printf("Actual status:   %d\n", status);
    assert(status == LIST_DATA_NOT_FOUND);

    /* Verify list was not modified. */
    assert(get_list_length(p_list) == 3);

    show_list(p_list, "List after rejected insertion: ");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 4: Insert at position 0
     *
     * Verify insertion at the beginning of a non-empty list.
     * ============================================================ */
    printf("\nTest 4: Insert at position 0\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    status = insert_at_position(p_list, 10, 0);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    assert(status == SUCCESS);

    assert(get_list_length(p_list) == 4);

    status = get_start(p_list, &data);
    assert(status == SUCCESS);
    assert(data == 10);

    show_list(p_list, "Expected: [10]->[20]->[30]->[40]");


    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 5: Insert in the middle
     *
     * [20]->[20]->[30]
     * Insert 25 at position 1.
     *
     * Expected:
     * [20]->[25]->[20]->[30]
     * ============================================================ */
    printf("\nTest 5: Insert in the middle\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = insert_at_position(p_list, 25, 1);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    assert(status == SUCCESS);

    assert(get_list_length(p_list) == 4);

    show_list(p_list, "Expected: [20]->[25]->[20]->[30]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 6: Position equal to list length
     *
     * Position == length should insert at the end.
     *
     * Existing: [10]->[20]->[30]
     * Position: 3
     *
     * Expected: [10]->[20]->[30]->[40]
     * ============================================================ */
    printf("\nTest 6: Insert at position equal to list length\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = insert_at_position(p_list, 40, 3);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    assert(status == SUCCESS);

    assert(get_list_length(p_list) == 4);

    status = get_end(p_list, &data);
    assert(status == SUCCESS);
    assert(data == 40);

    show_list(p_list, "Expected: [10]->[20]->[30]->[40]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 7: Position greater than list length
     *
     * Existing length = 3
     * Position = 4
     *
     * Expected: LIST_DATA_NOT_FOUND
     * ============================================================ */
    printf("\nTest 7: Position greater than list length\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);

    status = insert_at_position(p_list, 40, 4);

    printf("Expected status: LIST_DATA_NOT_FOUND\n");
    printf("Actual status:   %d\n", status);
    assert(status == LIST_DATA_NOT_FOUND);

    /* List must remain unchanged. */
    assert(get_list_length(p_list) == 3);

    show_list(p_list, "List after rejected insertion: ");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 8: Single-element list
     *
     * Test both valid positions:
     *
     * Position 0 -> beginning
     * Position 1 -> end
     * ============================================================ */
    printf("\nTest 8: Single-element list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);

    status = insert_at_position(p_list, 25, 0);

    printf("Insert 25 at position 0: status = %d\n", status);
    assert(status == SUCCESS);

    status = insert_at_position(p_list, 75, 2);

    printf("Insert 75 at position 2: status = %d\n", status);
    assert(status == SUCCESS);

    assert(get_list_length(p_list) == 3);

    show_list(p_list, "Expected: [25]->[50]->[75]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 9: Zero and negative values
     *
     * The data values themselves may be zero or negative.
     * ============================================================ */
    printf("\nTest 9: Zero and negative data values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    status = insert_at_position(p_list, -10, 1);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    assert(status == SUCCESS);

    assert(get_list_length(p_list) == 4);

    show_list(p_list, "Expected: [-20]->[-10]->[0]->[20]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 10: Duplicate values
     *
     * Ensure insertion is based on position, not data value.
     * ============================================================ */
    printf("\nTest 10: Duplicate values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);
    assert(insert_end(p_list, 5) == SUCCESS);

    status = insert_at_position(p_list, 10, 2);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    assert(status == SUCCESS);

    assert(get_list_length(p_list) == 4);

    show_list(p_list, "Expected: [5]->[5]->[10]->[5]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 11: Large and small data values
     *
     * Use the limits of data_t without performing arithmetic on
     * them, avoiding overflow/undefined behavior.
     *
     * Assumes data_t is an integer type compatible with these
     * constants. If data_t has a different definition, replace
     * these values with appropriate valid data_t values.
     * ============================================================ */
    printf("\nTest 11: Large/small data values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, (data_t)-1000000) == SUCCESS);
    assert(insert_end(p_list, (data_t)1000000) == SUCCESS);

    status = insert_at_position(p_list, (data_t)0, 1);

    printf("Expected status: SUCCESS\n");
    printf("Actual status:   %d\n", status);
    assert(status == SUCCESS);

    assert(get_list_length(p_list) == 3);

    show_list(p_list, "Expected: [-1000000]->[0]->[1000000]");

    destroy_list(&p_list);
    assert(p_list == NULL);


    /* ============================================================
     * Test 12: NULL list
     *
     * The exercise does not explicitly define behavior for a NULL
     * list. Therefore, do not assert a specific status here.
     *
     * This test is intentionally omitted because calling the
     * exercise function with NULL could be undefined behavior
     * depending on the expected contract.
     * ============================================================ */


    printf("\n========================================\n");
    printf("All tests passed successfully!\n");
    printf("========================================\n");

    return EXIT_SUCCESS;
}
status_t insert_at_position(list_t* p_list, data_t data, int position)
{
    if(p_list == NULL)
        return INVALID_LIST;

    node_t* run = p_list;
    len_t ipos = 0;
    len_t length = get_list_length(p_list);
    if(position < 0 || position > length)
        return LIST_DATA_NOT_FOUND;
    len_t index = 0;
    while(run->next != NULL)
    {
        if(index == position)
            break;
        index++;
        run = run->next;
    }
    node_t* new_node = get_node(data);
    new_node->next = run->next;
    run->next = new_node;
    return SUCCESS;
}