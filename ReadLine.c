#include <stdio.h>
#include <stdlib.h>

#include "ReadLine.h"
#include "IoUtilsByBrahvim.h"

// [ https://stackoverflow.com/questions/52984551/using-fgets-with-realloc ]
char* read_line(const size_t p_factor) {
    size_t size = 5; // ...Buffer's current size?
    size_t read_size = 0; // How filled is the buffer?!
    char *line = malloc(size);

    clear_stdin();

    if (!line) {
        perror("`read_line()` failed to allocate memory.");
        return NULL;
    }

    for (int c = fgetc(stdin); !(c == EOF || c == '\n'); c = fgetc(stdin)) {
        line[read_size] = c;
        ++read_size;

        if (read_size == size) {
            size += p_factor;
            char *reallocated = realloc(line, size);

            if (!reallocated) {
                perror("`read_line()` failed to re-allocate memory.");
                return line;
            }

            line = reallocated;
        }
    }

    // We re-allocate to make sure we have a string of the perfect size:
    line = realloc(line, read_size + 1);
    line[read_size] = '\0';

    return line;
}
