#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ReadLine.h"
#include "IoUtilsByBrahvim.h"

DECLARE_GENERIC_INPUT_FUNCTIONS(size_t);
DEFINE_GENERIC_INPUT_FUNCTIONS(size_t, "%llu");

int main() {
    puts("Welcome to the string sorting program!");

    size_t strings_array_available_space = ensure_user_inputs_size_t("Any idea of how many strings we will need?");
    char **strings_array = calloc(strings_array_available_space, sizeof(char*));
    size_t strings_array_size = 0;

    if (!strings_array)
        perror("Too many strings for your computer to handle, sorry.");

    while (getchar() != EOF) {
        if (strings_array_size == strings_array_available_space) {
            strings_array_available_space += 5;

            char **new_strings_array = realloc(strings_array, strings_array_available_space);
            if (!new_strings_array) {
                perror("Out of memory we are! Program exiting...");
                goto cleanup;
            }

            

        }

        strings_array[strings_array_size] = read_line(5);
        strings_array_size++;
    }

cleanup:
    free(strings_array);
}
