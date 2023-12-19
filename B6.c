// Author: Brahvim Bhaktvatsal.

// Header declarations:
#include "include/IoUtilsByBrahvim.h"

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
        const int scanf_result = scanf("%d", &in);
        clear_stdin();

        if (scanf_result != 1) {
            // If the user sent `EOF`, stop:
            if (scanf_result == EOF) {
                puts("Alright! Sorting those...");
                break;
            } else { // Otherwise, we tell the user to try again:
                puts("\nInvalid input, try this one again:");
                i -= i == 0 ? 0 : 1;
                continue;
            }
        }

        array_len++;

        // if the array is too small, re-allocate!:
        if (i > array_space) {
            array_space += sizeof(int) * 5;
            array = realloc(array, array_space);
        }

        // Assign:
        array[i] = in;
    }

    qsort(array, array_len, sizeof(int), compare_ints);
    const size_t array_len_minus_one = array_len - 1;
    puts("Sorted, the numbers are: ");

    for (size_t i = 0; i < array_len; i++)
        printf("`%d`%s", array[i], i == array_len_minus_one ? ".\n" : ",");

    free(array);
}

int compare_ints(const void *p_first, const void *p_second) {
    return (*(int*)p_first - *(int*)p_second);
}
