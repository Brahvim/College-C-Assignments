#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma region // Header declarations.
typedef char strch_t; // This is to help switch encodings later if needed.
#define MAX_SIZE_FOR_READ_STRINGS 5
#pragma endregion

int main() {
    size_t num_names = 0;
    size_t space_for_names = 5;
    strch_t **names = calloc(space_for_names, sizeof(strch_t *));

    if (names == NULL) {
        perror("Startup error. Cannot continue...");
        return EXIT_FAILURE;
    }

    puts("Welcome to the string-sorting program!");
    puts("Enter some strings (across lines) that you want sorted.");

    // This information is retained across loops 
    // to make sure large strings can be entered:
    strch_t *new_name = { 0 };
    size_t new_name_prev_len = 0;

    for (strch_t buf[MAX_SIZE_FOR_READ_STRINGS] = { 0 };
        // `fgets()` returns `NULL` when it reads `EOF` from the given `FILE` handle.
        fgets(buf, MAX_SIZE_FOR_READ_STRINGS, stdin) != NULL;) {
        if (num_names >= space_for_names) {
            space_for_names += 5;
            names = realloc(names, space_for_names);
            if (names == NULL) {
                perror("Allocating more memory for more names failed!");
                break;
            }
        }

        const size_t len = strlen(buf), len_minus_1 = len - 1;

        new_name_prev_len += len;
        new_name = calloc(len, sizeof(strch_t));

        // This replaces the `\n` with a `\0`:
        if (len > 0 && buf[len_minus_1] == '\n') {
            buf[len_minus_1] = '\0';
            new_name = realloc(new_name, len);

            // Allocating memory for a name:
            if (new_name == NULL) {
                perror("Allocating for storing a name failed!");
                exit(EXIT_FAILURE);
            }

            // Copy the part of the string we read:
            strncpy(new_name, buf, len);

            // No need to clear `buf` like via this line here:
            // memset(buf, 0, MAX_SIZE_FOR_READ_STRINGS);
            // If the new string's longer that the contents in `buf`, good.
            // The new string written into `buf` will have a `\0` before the older data anyway.

            new_name_prev_len = 0;

            // Increment and assign!:
            names[num_names++] = new_name;
        }

    }

    puts("\nSorting 'em using bubble sort...\n");

    const size_t num_names_minus_1 = num_names - 1;

    // Bubble-sorting the array of names:
    for (size_t i = 0; i < num_names_minus_1; i++)
        for (size_t j = 0; j < num_names_minus_1 - i; j++) {
            // .............................. ^^^ the `- i` is an optimization.
            if (names[j] == NULL) {
                perror("One of the strings you gave was `NULL`! Cannot sort this...");
                continue; // exit(EXIT_FAILURE);
            } else if (strcmp(names[j], names[j + 1]) > 0) {
                char *temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }

    // De-allocating space allocate for each name-string:
    for (size_t i = 0; i < num_names; i++) {
        char *name = names[i];
        puts(name);
        free(name);
    }

    // De-allocating space used by the pointers:
    puts("Done. Bye now!");
    free(names);
}
