#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"

void sort_int_array(int *array, const size_t array_length);

DECLARE_GENERIC_INPUT_SCANNER(int);
#pragma endregion

DEFINE_GENERIC_INPUT_SCANNER(int, "%d");

int main() {
    puts("Welcome to the integer sorting program!");
    printf("Enter some `%lu`-byte integers to sort.\n", sizeof(int));

    size_t array_len = 5;
    int *array = (int *)calloc(array_len, sizeof(int));

    if (!array) {
        perror("Failed to allocate memory!\n");
        return -1;
    }

    for (size_t i = 0; true; i++) {
        int in = 0;
        clear_stdin();
        const int scanf_result = scanf("%d", &in);

        if (scanf_result != 1) {
            // If the user sent `EOF`, stop:
            if (scanf_result == EOF)
                break;
            else { // Otherwise, we tell the user to try again:
                puts("\nInvalid input, try this one again:");
                i -= i == 0 ? 0 : 1;
                continue;
            }
        }

        // if the array is too small, re-allocate!:
        if (i > array_len)
            array = (int *)realloc(array, array_len + sizeof(int) * 5);

        // Assign:
        array[i] = in;
    }

    sort_int_array(array, array_len);
    puts("Sorted, the numbers are: ");

    for (size_t i = 0; i < array_len; i++)
        printf("`%d`%c", array[i], i == array_len ? '.' : ',');

    putchar('\n');

    return 0;
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
