// Author: Brahvim Bhaktvatsal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/IoUtilsByBrahvim.h"

// Type for strings so we can change encodings later, just like in other programs:
typedef char strch_t;

DECLARE_GENERIC_INPUT_FUNCTIONS(size_t);
DEFINE_GENERIC_INPUT_FUNCTIONS(size_t, "%lu");

int main() {
    puts("Welcome to the string allocation-test program!");

    // Ask the user what size they'd like for their string:
    size_t str_size_initial = 0;

    while (str_size_initial == 0) {
        str_size_initial = ensure_user_inputs_size_t("size for your string");
    }

    strch_t* str_data = malloc(str_size_initial);

    puts("Please enter all characters in your string:");

    clear_stdin();
    for (size_t i = 0; i < str_size_initial; i++)
        str_data[i] = getchar();

    printf("Your string is: \"%s\"!\n", str_data);

    // Ask the user what size they'd like for the new string:
    size_t str_size_new = 0;

    clear_stdin();
    while (str_size_new < str_size_initial) {
        str_size_new = ensure_user_inputs_size_t("new size for your string");
    }

    str_data = realloc(str_data, str_size_new);

    if (!str_data) {
        perror("Out of memory! Could not allocate the new string...");
        exit(EXIT_FAILURE);
    }

    puts("Please enter all characters to be APPENDED to your existing string!:");

    clear_stdin();
    for (size_t i = str_size_initial; i < str_size_new; i++) {
        str_data[i] = getchar();
    }

    printf("Your string should be: \"%s\"!\n", str_data);
    free(str_data);
}
