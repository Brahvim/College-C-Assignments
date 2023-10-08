#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region // Header declarations.
typedef char strch_t; // This is to help switch encodings later if needed.
#define MAX_SIZE_FOR_READ_STRINGS 99
#pragma endregion

int main() {
    const strch_t **names = calloc(MAX_SIZE_FOR_READ_STRINGS, sizeof(strch_t *));
    size_t num_names = 0;

    // Should exit only if `stdin` has been closed:
    for (strch_t buf[MAX_SIZE_FOR_READ_STRINGS] = { 0 };
        fgets(buf, MAX_SIZE_FOR_READ_STRINGS, stdin) != NULL;) {
        if (num_names > MAX_SIZE_FOR_READ_STRINGS)
            if ((names = realloc(names, 2 * num_names * sizeof(strch_t *))) == NULL)
                perror("Allocating more memory for more names failed!");

        const size_t len = strlen(buf), len_minus_1 = len - 1;

        if (len > 0 && buf[len_minus_1] == '\n') {
            buf[len_minus_1] = '\0';

            strch_t *new_name = calloc(len, sizeof(strch_t));
            if (new_name == NULL) {
                perror("Allocating for storing a name failed!");
                exit(EXIT_FAILURE);
            }

            strncpy(new_name, buf, len); // Copy the part of the string we read.
            // memset(buf, 0, MAX_SIZE_FOR_READ_STRINGS); // Clear the temporary buffer.
            // ^^^ Unnecessary! New string's longer? Nice! Else, we'll see `\0` sooner anyway.
            names[num_names++] = new_name; // Assign!
        }
    }

    puts("Sorting using bubble sort...");

    const size_t num_names_minus_1 = num_names - 1;

    for (size_t i = 0; i < num_names_minus_1; i++)
        for (size_t j = 0; j < num_names_minus_1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                const char *temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }


    for (size_t i = 0; i < num_names; i++)
        free((void *)names[i]);

    free(names);

}

void swap(void **p_1, void **p_2) {
    void *temp = *p_1;
    *p_1 = *p_2;
    *p_2 = temp;
}
