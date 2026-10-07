#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ARRAY_LENGTH(array) ((int)(sizeof(array) / sizeof((array)[0])))

static int tests_run = 0;
static int tests_failed = 0;
// Exercise 1: Sum of All Elements
int sum_of_all_elements(const int *array, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}
// Exercise 2: Count Even Numbers
int count_even_numbers(const int *array, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            count++;
        }
    }

    return count;
}
// Exercise 3: Find the Largest Element
int find_largest_element(const int *array, int size) {
    int largest = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }

    return largest;
}
// Exercise 4: Find the Smallest Element
int find_smallest_element(const int *array, int size) {
    int smallest = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }

    return smallest;
}
// Exercise 5: Check if Element Exists
bool element_exists(const int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }

    return false;
}
// Exercise 6: Count Occurances Of a Value
int count_occurrences(const int *array, int size, int value) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            count++;
        }
    }

    return count;
}
// Exercise 7: Print Array in Reverse Order
void print_reverse_array(const int *array, int size) {
    for(int i = size - 1; i >= 0; i--){
        printf(" %d ",array[i]);
    }
}
// Exercise 8: Find Index of Element
int find_index_of_element(const int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}
// Exercise 9: Calculate Average
double calculate_average(int* array,int size){
    int sum = 0; 
    for(int i = 0; i < size; i++)
        sum = sum + array[i];
    return (double)( sum / size);
}
// Exercise 10: Copy Array Elements
void copy_array_elements(const int *source, int size, int *destination) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}
// Exercise 11: Reverse Array In-Place
void reverse_array(int *array, int size) {
    for (int left = 0, right = size - 1; left < right; left++, right--) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
}
// Exercise 12: Find Second Largest Element
int find_second_largest(const int *array, int size) {
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for(int i = 0; i < size; i++){
        if(largest < array[i]){
            second_largest = largest;
            largest = array[i];
        }
    }
    return second_largest;
}
// Exercise 13: Remove Duplidates(Keep First Occurrence)
int remove_duplicate_elements(int *array, int size) {
    int unique_count = 0;

    for (int i = 0; i < size; i++) {
        bool seen = false;

        for (int j = 0; j < unique_count; j++) {
            if (array[j] == array[i]) {
                seen = true;
                break;
            }
        }

        if (!seen) {
            array[unique_count] = array[i];
            unique_count++;
        }
    }

    return unique_count;
}
// Exercise 14: Rotate Array Left by K Positions
void rotate_left_by_k(int *array, int size, int k) {
    if (size == 0) {
        return;
    }

    k %= size;

    for (int step = 0; step < k; step++) {
        int first = array[0];

        for (int i = 0; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        array[size - 1] = first;
    }
}
// Exercise 15: Find All pairs with Given Sum
int find_all_pairs_with_sum(int* array, int size, int target){
    int count = 0;
    for(int i = 0; i < size; i++ )
    {
        for(int j = i+1; j < size; j++){
            if(array[i] + array[j] == target)
            {
                printf("( %d, %d),", array[i], array[j]);
                count++;
            }
        }
    }
    return count;
}
// Exercise 16: Merge Two Sorted Arrays
void merge_two_sorted_arrays(const int *first, int first_size, const int *second, int second_size, int *output) {
    int i = 0;
    int j = 0;
    int index = 0;

    while (i < first_size && j < second_size) {
        if (first[i] <= second[j]) {
            output[index++] = first[i++];
        } else {
            output[index++] = second[j++];
        }
    }

    while (i < first_size) {
        output[index++] = first[i++];
    }

    while (j < second_size) {
        output[index++] = second[j++];
    }
}
// Exercise 17: Find Missing Number in Sequence
int find_missing_number_in_sequence(const int *array, int size) {
    int expected_sum = (size + 1) * (size + 2) / 2;
    int actual_sum = sum_of_all_elements(array, size);

    return expected_sum - actual_sum;
}
// Exercise 18: Separate Odd and Even Numbers
void separate_even_and_odd(int* array, int size)
{
    int temp = 0;
    for(int i = 0, j = size - 1; (i < size && j >= 0) && i <= j;){
        if((array[i] % 2) != 0 && (array[j]%2) == 0)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        if((array[i] % 2) == 0)
            i++;
        if((array[j] % 2) != 0)
            j--;
    }
}
// Exercise 19: Check if Array is Sorted
bool is_array_sorted(const int *array, int size) {
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }

    return true;
}
// Exercise 20: Find Intersection of Two Arrays
int find_intersection_of_two_arrays(const int *first, int first_size, const int *second, int second_size, int *output) {
    int count = 0;

    for (int i = 0; i < first_size; i++) {
        bool exists_in_second = false;
        bool already_added = false;

        for (int j = 0; j < second_size; j++) {
            if (first[i] == second[j]) {
                exists_in_second = true;
                break;
            }
        }

        for (int j = 0; j < count; j++) {
            if (output[j] == first[i]) {
                already_added = true;
                break;
            }
        }

        if (exists_in_second && !already_added) {
            output[count++] = first[i];
        }
    }

    return count;
}
// Exercise 21: Move All Zeros to End
void move_all_zeros_to_end(int *array, int size) {
    int insert_index = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] != 0) {
            array[insert_index++] = array[i];
        }
    }

    while (insert_index < size) {
        array[insert_index++] = 0;
    }
}
// Exercise 22: Find the Majority Element
int find_majority_element(int* array, int size){
    int MaxCount = 0;
    int Count = 0;
    int majority_element = 0;
    for(int i = 0; i < size; i++){
        Count = 0;
        for(int j = 0; j < size; j++){
            if(array[i] == array[j])
                Count++;
        }
        if(Count > MaxCount)
            majority_element = array[i];
    }
    return majority_element;
}
// Exercise 23: Rotate Array Right by K Positions(In-Place, Efficient)
void rotate_right_by_k(int *array, int size, int k) {
    if (size == 0) {
        return;
    }

    k %= size;

    for (int step = 0; step < k; step++) {
        int last = array[size - 1];

        for (int i = size - 1; i > 0; i--) {
            array[i] = array[i - 1];
        }

        array[0] = last;
    }
}
// Exercise 24: Find Maximum Subarray Sum
int find_maximum_subarray_sum(int* array, int size,int *start_index, int* end_index){

    //int start_index = 0, end_index = 0;
    int max_sum = 0;
    int final_sum = 0;
    for(int i = 0; i < size; i++) {
        max_sum = 0;
        for(int j = i+1; j < size; j++) {
            max_sum+=array[j];
            if(max_sum > final_sum) {
                *start_index = i+1;
                *end_index = j;
                final_sum = max_sum;
            }
        }
    }
    return final_sum;
}
// Exercise 25: Rearrange Array in Wave Form
void rearrange_array_in_wave_form(int *array, int size) {
    for (int i = 0; i < size; i += 2) {
        if (i > 0 && array[i] < array[i - 1]) {
            int temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
        }

        if (i < size - 1 && array[i] < array[i + 1]) {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
}
// Exercise 26: Find First Non-Repeating Element
int find_first_non_repeating_element(int* array, int size) {
    bool repeated = false;
    int temp = -1;
    for(int i = 0; i < size; i++)
    {
        temp = array[i];
        repeated = false;
        for(int j = 0; j < size; j++)
        {
            if(temp == array[j] && i != j)
                repeated = true;
        }
        if(!repeated)
            return temp;
    }
    return -1;
}
// Exercise 27: Find Equilibrium index
int find_equilibrium_index(int* array, int size)
{
    int i = 0;
    int j = 0;
    int Sum1 = 0;
    int Sum2 = 0;
    j = size-1;
    while(i < j)
    {   
        Sum1 = Sum1 + array[i];
        Sum2 = Sum2 + array[j];
        if(Sum1 == Sum2)
            return i+1;
        i++;
        j--;
    }
    return -1;
}

int compare_integers(const void *left, const void *right) {
    const int *left_value = (const int *)left;
    const int *right_value = (const int *)right;

    return *left_value - *right_value;
}
// Exercise 28: Find Longest Consecutive Sequence Length
int find_longest_consecutive_sequence_length(int* array, int size)
{
    int temp = 0;
    //Sort the Array
    for(int i = 0;i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp; 
            }
        }
    }
    int max_length = 0;
    int length = 0;
    for(int i = 0; i < size; i++)
    {
        length = 1;
        for(int j = i; j < size-1; j++)
        {
            if(array[j+1] - array[j] == 1)
            {
                length++;
            }
            else
                length;
        }
        if(length > max_length)
            max_length = length;
    }
    return max_length;
}
// Exercise 29: Dutch National Flag Problem
void dutch_national_flag_sort(int *array, int size) {
    int low = 0;
    int mid = 0;
    int high = size - 1;

    while (mid <= high) {
        if (array[mid] == 0) {
            int temp = array[low];
            array[low] = array[mid];
            array[mid] = temp;
            low++;
            mid++;
        } else if (array[mid] == 1) {
            mid++;
        } else {
            int temp = array[mid];
            array[mid] = array[high];
            array[high] = temp;
            high--;
        }
    }
}
// Exercise 30: Find Triplets with Zero Sum
int find_triplets_with_sum(int* array, int size, int target) {
    bool repeated = false;
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            for(int k = j+1; k < size; k++){
                if (array[i] + array[j] + array[k] == target) 
                {
                        printf("[ %d, %d, %d]", array[i], array[j], array[k]);
                        count++;
                }
            }
        }
    }
    return count;
}

void print_array(const int *array, int size) {
    printf("[");

    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("]");
}

void assert_int_equal(const char *label, int expected, int actual) {
    tests_run++;

    if (expected != actual) {
        tests_failed++;
        printf("FAIL %-40s expected=%d actual=%d\n", label, expected, actual);
        return;
    }

    printf("PASS %-40s value=%d\n", label, actual);
}

void assert_bool_equal(const char *label, bool expected, bool actual) {
    tests_run++;

    if (expected != actual) {
        tests_failed++;
        printf("FAIL %-40s expected=%s actual=%s\n", label, expected ? "true" : "false", actual ? "true" : "false");
        return;
    }

    printf("PASS %-40s value=%s\n", label, actual ? "true" : "false");
}

void assert_double_equal(const char *label, double expected, double actual) {
    double difference = expected - actual;

    if (difference < 0) {
        difference = -difference;
    }

    tests_run++;

    if (difference > 0.0001) {
        tests_failed++;
        printf("FAIL %-40s expected=%.2f actual=%.2f\n", label, expected, actual);
        return;
    }

    printf("PASS %-40s value=%.2f\n", label, actual);
}

void assert_array_equal(const char *label, const int *expected, const int *actual, int size) {
    tests_run++;

    for (int i = 0; i < size; i++) {
        if (expected[i] != actual[i]) {
            tests_failed++;
            printf("FAIL %-40s expected=", label);
            print_array(expected, size);
            printf(" actual=");
            print_array(actual, size);
            printf("\n");
            return;
        }
    }

    printf("PASS %-40s value=", label);
    print_array(actual, size);
    printf("\n");
}

bool is_wave_form(const int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (i > 0 && i % 2 == 0 && array[i] < array[i - 1]) {
            return false;
        }

        if (i < size - 1 && i % 2 == 0 && array[i] < array[i + 1]) {
            return false;
        }
    }

    return true;
}

int main(void) 
{
    int copied[5] = {0};
    int reversed[5] = {0};
    int separated[6] = {0};
    int merged[7] = {0};
    int intersection[4] = {0};
    int pairs[4][2] = {{0}};
    int triplets[4][3] = {{0}};
    int majority = 0;
    int first_non_repeating = 0;

    int values1[] = {1, 2, 3, 4, 5};
    int values2[] = {2, 7, 4, 9, 12};
    int values3[] = {1, 2, 3, 2, 4, 2};
    int values4[] = {1, 2, 3, 4, 5};
    int values5[] = {1, 2, 3, 4, 5};
    int values6[] = {10, 20, 20, 30, 10, 40};
    int left_rotation[] = {1, 2, 3, 4, 5};
    int reverse_values[] = {1, 2, 3, 4, 5};
    int duplicates[] = {1, 2, 2, 3, 4, 4, 5};
    int first_sorted[] = {1, 3, 5, 7};
    int second_sorted[] = {2, 4, 6};
    int missing_number[] = {1, 2, 4, 5};
    int odd_even[] = {1, 2, 3, 4, 5, 6};
    int sorted_values[] = {1, 2, 3, 4};
    int unsorted_values[] = {3, 1, 2, 4};
    int first_intersection[] = {1, 2, 2, 3, 4};
    int second_intersection[] = {2, 2, 4, 6};
    int zeros[] = {0, 1, 0, 3, 12};
    int majority_values[] = {2, 2, 1, 2, 3, 2, 2};
    int right_rotation[] = {1, 2, 3, 4, 5};
    int max_sum_values[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int wave_values[] = {10, 90, 49, 2, 1, 5, 23};
    int non_repeating_values[] = {9, 4, 9, 6, 7, 4};
    int equilibrium_values[] = {1, 3, 5, 2, 2};
    int consecutive_values[] = {100, 4, 200, 1, 3, 2};
    int dutch_values[] = {2, 0, 2, 1, 1, 0};
    int triplet_values[] = {-1, 0, 1, 2, -1, -4};

    printf("Array assignment test scenarios\n\n");

    assert_int_equal("01 sum of all elements", 15, sum_of_all_elements(values1, ARRAY_LENGTH(values1)));
    assert_int_equal("02 count even numbers", 2, count_even_numbers(values1, ARRAY_LENGTH(values1)));
    assert_int_equal("03 find largest element", 12, find_largest_element(values2, ARRAY_LENGTH(values2)));
    assert_int_equal("04 find smallest element", 2, find_smallest_element(values2, ARRAY_LENGTH(values2)));
    assert_bool_equal("05 check if element exists", true, element_exists(values2, ARRAY_LENGTH(values2), 9));
    assert_int_equal("06 count occurrences", 3, count_occurrences(values3, ARRAY_LENGTH(values3), 2));

    build_reverse_array(values4, ARRAY_LENGTH(values4), reversed);
    assert_array_equal("07 print reverse scenario", (int[]){5, 4, 3, 2, 1}, reversed, ARRAY_LENGTH(values4));

    assert_int_equal("08 find index of element", 3, find_index_of_element(values5, ARRAY_LENGTH(values5), 4));
    assert_double_equal("09 calculate average", 130.0 / 6.0, calculate_average(values6, ARRAY_LENGTH(values6)));

    copy_array_elements(values1, ARRAY_LENGTH(values1), copied);
    assert_array_equal("10 copy array elements", values1, copied, ARRAY_LENGTH(values1));

    reverse_array(reverse_values, ARRAY_LENGTH(reverse_values));
    assert_array_equal("11 reverse array", (int[]){5, 4, 3, 2, 1}, reverse_values, ARRAY_LENGTH(reverse_values));
    assert_int_equal("12 find second largest", 30, find_second_largest(values6, ARRAY_LENGTH(values6)));

    assert_int_equal("13 remove duplicate count", 5, remove_duplicate_elements(duplicates, ARRAY_LENGTH(duplicates)));
    assert_array_equal("13 remove duplicate values", (int[]){1, 2, 3, 4, 5}, duplicates, 5);

    rotate_left_by_k(left_rotation, ARRAY_LENGTH(left_rotation), 2);
    assert_array_equal("14 rotate array left by k", (int[]){3, 4, 5, 1, 2}, left_rotation, ARRAY_LENGTH(left_rotation));

    assert_int_equal("15 find all pairs of given sum", 2, find_all_pairs_with_sum(values1, ARRAY_LENGTH(values1), 5, pairs, 4));
    assert_array_equal("15 first pair", (int[]){1, 4}, pairs[0], 2);
    assert_array_equal("15 second pair", (int[]){2, 3}, pairs[1], 2);

    merge_two_sorted_arrays(first_sorted, ARRAY_LENGTH(first_sorted), second_sorted, ARRAY_LENGTH(second_sorted), merged);
    assert_array_equal("16 merge two sorted arrays", (int[]){1, 2, 3, 4, 5, 6, 7}, merged, ARRAY_LENGTH(merged));
    assert_int_equal("17 find missing number", 3, find_missing_number_in_sequence(missing_number, ARRAY_LENGTH(missing_number)));

    separate_even_and_odd(odd_even, ARRAY_LENGTH(odd_even), separated);
    assert_array_equal("18 separate even and odd", (int[]){2, 4, 6, 1, 3, 5}, separated, ARRAY_LENGTH(odd_even));

    assert_bool_equal("19 array is sorted", true, is_array_sorted(sorted_values, ARRAY_LENGTH(sorted_values)));
    assert_bool_equal("19 array is not sorted", false, is_array_sorted(unsorted_values, ARRAY_LENGTH(unsorted_values)));

    assert_int_equal("20 intersection count", 2, find_intersection_of_two_arrays(first_intersection, ARRAY_LENGTH(first_intersection), second_intersection, ARRAY_LENGTH(second_intersection), intersection));
    assert_array_equal("20 intersection values", (int[]){2, 4}, intersection, 2);

    move_all_zeros_to_end(zeros, ARRAY_LENGTH(zeros));
    assert_array_equal("21 move all zeros to end", (int[]){1, 3, 12, 0, 0}, zeros, ARRAY_LENGTH(zeros));

    assert_bool_equal("22 majority element exists", true, find_majority_element(majority_values, ARRAY_LENGTH(majority_values), &majority));
    assert_int_equal("22 majority element value", 2, majority);

    rotate_right_by_k(right_rotation, ARRAY_LENGTH(right_rotation), 2);
    assert_array_equal("23 rotate array right by k", (int[]){4, 5, 1, 2, 3}, right_rotation, ARRAY_LENGTH(right_rotation));
    assert_int_equal("24 maximum subarray sum", 6, find_maximum_subarray_sum(max_sum_values, ARRAY_LENGTH(max_sum_values)));

    rearrange_array_in_wave_form(wave_values, ARRAY_LENGTH(wave_values));
    assert_bool_equal("25 rearrange array in wave form", true, is_wave_form(wave_values, ARRAY_LENGTH(wave_values)));

    assert_bool_equal("26 first non repeating exists", true, find_first_non_repeating_element(non_repeating_values, ARRAY_LENGTH(non_repeating_values), &first_non_repeating));
    assert_int_equal("26 first non repeating value", 6, first_non_repeating);
    assert_int_equal("27 equilibrium index", 2, find_equilibrium_index(equilibrium_values, ARRAY_LENGTH(equilibrium_values)));
    assert_int_equal("28 longest consecutive sequence", 4, find_longest_consecutive_sequence_length(consecutive_values, ARRAY_LENGTH(consecutive_values)));

    dutch_national_flag_sort(dutch_values, ARRAY_LENGTH(dutch_values));
    assert_array_equal("29 dutch national flag", (int[]){0, 0, 1, 1, 2, 2}, dutch_values, ARRAY_LENGTH(dutch_values));

    assert_int_equal("30 find triplet with zero sum", 3, find_triplets_with_sum(triplet_values, ARRAY_LENGTH(triplet_values), 0, triplets, 4));
    assert_array_equal("30 first triplet", (int[]){-1, 0, 1}, triplets[0], 3);
    assert_array_equal("30 second triplet", (int[]){-1, 2, -1}, triplets[1], 3);
    assert_array_equal("30 third triplet", (int[]){0, 1, -1}, triplets[2], 3);

    printf("\nSummary: %d tests run, %d failed\n", tests_run, tests_failed);

    return tests_failed == 0 ? 0 : 1;
}