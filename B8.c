// Author: Brahvim Bhaktvatsal

#include <stdio.h>
#include <stdlib.h>
#include "include/IoUtilsByBrahvim.h"

#define ARRAY_SIZE 10

DECLARE_GENERIC_INPUT_FUNCTIONS(size_t);
DEFINE_GENERIC_INPUT_FUNCTIONS(size_t, "%lu");

// Function to create and print a table of integers:
size_t* make_array(const size_t table_size);

int main() {
    puts("Welcome to the interactive table-of-`10` table-making program!");

    size_t *table = make_array(ARRAY_SIZE);

    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        printf("We're at position `%lu` in the table.\n", i + 1);
        table[i] = ensure_user_inputs_size_t("number to store here");
    }

    // Print the table:
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        printf("%lu\n", table[i]);
    }

    // Free the dynamically allocated memory:
    free(table);
}

size_t* make_array(const size_t p_size) {
    // Dynamically allocate memory for the table:
    size_t *to_ret = (size_t*)calloc(sizeof(size_t), p_size);

    if (to_ret == NULL) {
        perror("Memory allocation failed. Exiting...");
        exit(EXIT_FAILURE);
    }

    return to_ret;
}
