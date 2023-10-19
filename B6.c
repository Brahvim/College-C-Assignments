#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"

void sort_int_array(int *array, const size_t array_length);

DECLARE_GENERIC_INPUT_FUNCTIONS(int);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(int, "%d");

int main() {
    puts("Welcome to the integer sorting program!");
    printf("Enter some `%lu`-byte integers to sort.\n", sizeof(int));

    size_t array_len = 5;
    int *array = (int*)calloc(array_len, sizeof(int));

    if (!array)
        perror("Failed to allocate memory!\n");

    for (size_t i = 0; true; i++) {
        int in = 0;

        if (!parse_user_input_as_int(&in))
            break;

        if (i >= array_len)
            array = (int*)realloc(array, array_len + sizeof(int) * 5);
        
        // TODO: Anything else?
    }

    // sort_int_array(array, array_len);
    puts("Sorted, the numbers are: ");

    for (size_t i = 0; i < array_len; i++)
        printf("`%d`%c", array[i], i == array_len? '.' : ',');

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
