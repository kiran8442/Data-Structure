#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* Exercise function declaration */
double get_average(list_t* p_list);

int main(void)
{
    double result;
    const double EPSILON = 1e-9;

    /*
     * Test 1: NULL list
     *
     * There are no elements, so the expected average is 0.0.
     */
    printf("Test 1: NULL list\n");

    result = get_average(NULL);

    printf("Expected: 0.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 0.0) < EPSILON);

    /*
     * Test 2: Empty list
     *
     * create_list() creates the dummy head node but no data nodes.
     */
    printf("\nTest 2: Empty list\n");

    list_t* p_list = create_list();
    assert(p_list != NULL);

    result = get_average(p_list);

    printf("Expected: 0.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 0.0) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 3: Single-element list
     *
     * [25]
     * Average = 25.0
     */
    printf("\nTest 3: Single-element list\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 25) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 25.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 25.0) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 4: Multiple elements - exact average
     *
     * [10] [20] [30] [40]
     * Average = 25.0
     */
    printf("\nTest 4: Multiple elements - exact average\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 25.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 25.0) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 5: Fractional average
     *
     * [10] [20] [30]
     * Sum = 60
     * Average = 20.0
     */
    printf("\nTest 5: Fractional-average calculation\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 31) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 20.3333333333\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - (61.0 / 3.0)) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 6: Negative values
     *
     * [-10] [-20] [-30]
     * Average = -20.0
     */
    printf("\nTest 6: Negative values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, -20) == SUCCESS);
    assert(insert_end(p_list, -30) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: -20.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - (-20.0)) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 7: Mixed positive and negative values
     *
     * [-10] [20] [-30] [40]
     * Sum = 20
     * Average = 5.0
     */
    printf("\nTest 7: Mixed positive and negative values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, -10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, -30) == SUCCESS);
    assert(insert_end(p_list, 40) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 5.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 5.0) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 8: Zero values
     *
     * [0] [0] [0]
     * Average = 0.0
     */
    printf("\nTest 8: Zero values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 0.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 0.0) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 9: Duplicate values
     *
     * [10] [10] [20] [20]
     * Sum = 60
     * Average = 15.0
     */
    printf("\nTest 9: Duplicate values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 15.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 15.0) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 10: All elements have the same value
     *
     * [50] [50] [50] [50]
     * Average = 50.0
     */
    printf("\nTest 10: All elements equal\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);
    assert(insert_end(p_list, 50) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 50.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 50.0) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 11: Fractional average with negative values
     *
     * [-5] [0] [10] [20]
     * Sum = 25
     * Average = 6.25
     */
    printf("\nTest 11: Fractional average with negative values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, -5) == SUCCESS);
    assert(insert_end(p_list, 0) == SUCCESS);
    assert(insert_end(p_list, 10) == SUCCESS);
    assert(insert_end(p_list, 20) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 6.25\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 6.25) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 12: Large/small values
     *
     * The values are deliberately kept within a conservative range
     * so the test does not depend on the exact limits of data_t.
     *
     * [1000000] [2000000] [3000000]
     * Average = 2000000.0
     */
    printf("\nTest 12: Large/small values\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 1000000) == SUCCESS);
    assert(insert_end(p_list, 2000000) == SUCCESS);
    assert(insert_end(p_list, 3000000) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 2000000.0\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 2000000.0) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    /*
     * Test 13: Average is exactly between two values
     *
     * [1] [2]
     * Average = 1.5
     *
     * This specifically checks that integer division is not used.
     */
    printf("\nTest 13: Non-integer average\n");

    p_list = create_list();
    assert(p_list != NULL);

    assert(insert_end(p_list, 1) == SUCCESS);
    assert(insert_end(p_list, 2) == SUCCESS);

    result = get_average(p_list);

    printf("Expected: 1.5\n");
    printf("Actual:   %.10f\n", result);

    assert(fabs(result - 1.5) < EPSILON);

    destroy_list(&p_list);
    assert(p_list == NULL);

    printf("\nAll tests passed successfully!\n");

    return EXIT_SUCCESS;
}
double get_average(list_t* p_list)
{
    if(p_list == NULL || p_list->next == NULL)
        return 0;

    node_t* run = p_list->next;
    double total = 0;
    int count = 0;
    while(run != NULL)
    {
        total = total + run->data;
        count++;
        run = run->next;
    }
    return (double)(total / count);
}