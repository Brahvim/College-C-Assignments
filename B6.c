// Author: Brahvim Bhaktvatsal.

// Header declarations:
#include "include/IoUtilsByBrahvim.h"

void sort_int_array(int *array, const size_t array_length);

int compare_ints(const void *a, const void *b);

int main() {
    puts("Welcome to the integer sorting program!");
    printf("Enter some `%lu`-byte integers to sort.\n", sizeof(int));

    size_t array_len = 0, array_space = 5;
    int *array = calloc(array_space, sizeof(int));

    if (!array) {
        perror("Failed to allocate memory!\n");
        return -1;
    }

    for (size_t i = 0; true; i++) {
        int in = 0;
        printf("On line `%d`.\n", __LINE__);
        const int scanf_result = scanf("%d", &in);
        clear_stdin();

        if (scanf_result != 1) {
            // If the user sent `EOF`, stop:
            if (scanf_result == EOF) {
                printf("On line `%d`.\n", __LINE__);
                puts("Alright! Sorting those...");
                break;
            } else { // Otherwise, we tell the user to try again:
                printf("On line `%d`.\n", __LINE__);
                puts("\nInvalid input, try this one again:");
                i -= i == 0 ? 0 : 1;
                continue;
            }
        }

        printf("On line `%d`.\n", __LINE__);
        array_len++;

        // if the array is too small, re-allocate!:
        if (i > array_space) {
            array_space += sizeof(int) * 5;
            array = realloc(array, array_space);
        }

        // Assign:
        array[i] = in;
    }

    puts("Unsorted, the numbers are: ");

    const size_t array_len_minus_one = array_len - 1;

    for (size_t i = 0; i < array_len; i++)
        printf("`%d`%s", array[i], i == array_len_minus_one ? ".\n" : ",");

    qsort(array, array_len, sizeof(int), compare_ints);
    // sort_int_array(array, array_len);

    puts("Sorted, the numbers are: ");

    for (size_t i = 0; i < array_len; i++)
        printf("`%d`%s", array[i], i == array_len_minus_one ? ".\n" : ",");

    free(array);
}

int compare_ints(const void *p_first, const void *p_second) {
    return (*(int*)p_first - *(int*)p_second);
}

void sort_int_array(int *p_array, const size_t p_len) {
    const size_t check_till = p_len - 1;

    for (size_t i = 0; i < check_till; i++) {
        const int num = p_array[i],
            next_num = p_array[i + 1];

        if (next_num < num) {
            const int temp = num;
            p_array[i] = next_num;
            p_array[i + 1] = temp;
        }
    }
}
