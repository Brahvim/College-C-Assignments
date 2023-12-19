#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>
#include <ctype.h>

#pragma region // Header declarations.
typedef char strch_t; // This is to help switch encodings later if needed.
#define READ_LINE_FACTOR 2
#define MAX_SIZE_FOR_READ_STRINGS 5
#pragma endregion

strch_t* read_line(const size_t read_factor);
int compare_strings(const void *a, const void *b);

int compare_strings(const void *p_first, const void *p_second) {
	return strcmp(*(const char**)p_first, *(const char**)p_second);
}

int main() {
	size_t names_array_len = 0;
	size_t space_for_names = 5;
	strch_t **names_array = calloc(space_for_names, sizeof(strch_t *));

	if (names_array == NULL) {
		perror("Allocation error at startup! Can't continue...");
		exit(EXIT_FAILURE);
	}

	puts("Welcome to the string-sorting program!");
	puts("Enter some strings (across lines) that you want sorted.");

	while (true) {
		if (names_array_len == space_for_names) {
			space_for_names *= 2;
			names_array = realloc(names_array, space_for_names);
		}

		strch_t *name = read_line(READ_LINE_FACTOR);
		names_array[names_array_len] = name;

		if (name == NULL)
			break;

		names_array_len++;
	}

	puts("\nSorting using quick sort...\n");
	qsort(names_array, names_array_len, sizeof(names_array[0]), compare_strings);

	// De-allocating space allocate for each name-string:
	for (size_t i = 0; i < names_array_len; i++) {
		strch_t *name = names_array[i];
		puts(name);
		free(name);
	}

	// De-allocating space used by the pointers:
	puts("Done. Bye now!");
	free(names_array);
}

// [ https://stackoverflow.com/questions/52984551/using-fgets-with-realloc ]
strch_t* read_line(const size_t p_factor) {
	size_t size = 5; // ...Buffer's current size?
	size_t read_size = 0; // How filled is the buffer?!
	strch_t *line = malloc(size);

	if (!line) {
		perror("`read_line()` failed to allocate memory.");
		return NULL;
	}

	char c = '\0';
	for (; !((c = getchar()) == EOF || c == '\n');) {
		line[read_size] = c;
		read_size++;

		if (read_size == size) {
			size += p_factor;
			strch_t *reallocated = realloc(line, size);

			if (!reallocated) {
				perror("`read_line()` failed to re-allocate memory.");
				return line;
			}

			line = reallocated;
		}
	}

	if (c == EOF)
		return NULL;

	// We re-allocate to make sure we have a string of the perfect size:
	line = realloc(line, read_size + 1);
	line[read_size] = '\0';

	return line;
}
