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

    const size_t num_str_estimate = ensure_user_inputs_size_t("Any idea of how many strings we will need?");
    char **strings_array = calloc(num_str_estimate, sizeof(char*));

    if (!strings_array)
        perror("Too many strings for your computer to handle, sorry.");

    while (getchar() != EOF) {
        
    }

    free(strings_array);
}
