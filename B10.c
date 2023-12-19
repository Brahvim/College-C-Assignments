// Author: Brahvim Bhaktvatsal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/IoUtilsByBrahvim.h"

// Type for strings so we can change encodings later, just like in other programs:
typedef char* strch_t;

DECLARE_GENERIC_INPUT_FUNCTIONS(size_t);
DEFINE_GENERIC_INPUT_FUNCTIONS(size_t, "%lu");

strch_t custom_strncpy(strch_t source_string, strch_t destination_string, const size_t max_chars_copyable);

int main() {
    puts("Welcome to the string allocation-test program!");

    // Ask the user what size they'd like for their string:
    size_t str_size_initial = 0;

    while (str_size_initial == 0) {
        str_size_initial = ensure_user_inputs_size_t("new size for your string");
    }

    strch_t str_data_initial = malloc(str_size_initial);

    puts("Please enter all characters in your string:");

    for (size_t i = 0; i < str_size_initial; i++)
        str_data_initial[i] = getchar();

    // Ask the user what size they'd like for the new string:
    size_t str_size_new = 0;

    clear_stdin();
    while (str_size_new < str_size_initial) {
        str_size_new = ensure_user_inputs_size_t("new size for your string");
    }

    strch_t str_data_new = realloc(str_data_new, str_size_new);

    if (!str_data_new) {
        perror("Out of memory! Could not allocate the new string...");
        exit(EXIT_FAILURE);
    }

    puts("Please enter all characters to be APPENDED to your existing string!:");

    const size_t to_scan = str_size_new - str_size_initial;
    for (size_t i = 0; i < to_scan; i++)
        str_data_new[i + str_size_initial] = getchar();

    free(str_data_initial);
    free(str_data_new);
}

strch_t custom_strncpy(strch_t p_src, strch_t p_dest, const size_t p_max_copyable) {
    const size_t max_iter = p_max_copyable - 1;

    for (size_t i = 0; i < max_iter; i++)
        p_dest[i] = p_src[i];

    p_dest[max_iter] = '\0';
    return p_dest;
}
