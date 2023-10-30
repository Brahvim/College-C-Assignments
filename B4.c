#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
    { BasedOnStyle: Google, IndentWidth: 4, ContinuationIndentWidth: 4, ColumnLimit: 120, AlignAfterOpenBracket:
    AlwaysBreak, AlignConsecutiveAssignments: false, AlignConsecutiveDeclarations: true,
    AllowAllParametersOfDeclarationOnNextLine: false, AllowShortBlocksOnASingleLine: false,
    AllowShortCaseLabelsOnASingleLine: false, AllowShortFunctionsOnASingleLine: None,
    AllowShortIfStatementsOnASingleLine: Never, AllowShortLoopsOnASingleLine: false, IndentCaseLabels: true,
    IndentWrappedFunctionNames: false, KeepEmptyLinesAtTheStartOfBlocks: true, SpaceBeforeParens: ControlStatements,
    TabWidth: 4, UseTab: Always, BreakBeforeTernaryOperators: true, BreakAfterTernaryColon: false,
    BinPackArguments: false, AlignAfterOpenBracket: DontAlign, }
*/

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
    size_t new_name_len = 0;
    strch_t *new_name = { 0 };

    for (strch_t buf[MAX_SIZE_FOR_READ_STRINGS] = { 0 };
        // `fgets()` returns `NULL` when it reads `EOF` from the given `FILE` handle.
        fgets(buf, MAX_SIZE_FOR_READ_STRINGS, stdin) != NULL;) {

        // Add more space to the array if needed:
        if (num_names >= space_for_names) {
            // ...^^^ really just an equality check. 
            // Any overflow would cause a crash.

            space_for_names += 5; // Allocate a bit more in advance.
            // It's for just pointers anyway.

            strch_t **names_array_reallocated = realloc(names, space_for_names);

            if (names_array_reallocated == NULL) {
                perror("Allocating more memory for more names failed!");
                break;
            } else
                names = names_array_reallocated;
        }

        const size_t len = strlen(buf), len_minus_1 = len - 1;

        // We want more memory at this point:
        new_name_len += len;
        new_name = realloc(new_name, new_name_len);

        // Copy the part of the string we read:
        strncpy(new_name + new_name_len, buf, len + 1);

        // This replaces the `\n` with a `\0`:
        if (len > 0 && buf[len_minus_1] == '\n') {
            new_name[len_minus_1] = '\0'; // If we can, we end the string early.

            // No need to clear `buf` like via this line here:
            // memset(buf, 0, MAX_SIZE_FOR_READ_STRINGS);
            // If the new string's longer that the contents in `buf`, good.
            // The new string written into `buf` will have a `\0` before the older data anyway.

            // A new name will be placed there, so we reset the length here:
            new_name_len = 0;

            // Increment and assign!:
            names[num_names++] = new_name;
        }

    }

    puts("\nSorting using bubble sort...\n");

    // Bubble-sorting the array of names:
    for (size_t i = 0; i <= num_names; i++)
        for (size_t j = 0; j <= num_names - i; j++) {
            // .............................. ^^^ the `- i` is an optimization.
            if (names[j] == NULL) {
                perror("One of the strings you gave was `NULL`! Cannot sort this...");
                continue; // exit(EXIT_FAILURE);
            } else if (strcmp(names[j], names[j + 1]) > 0) {
                const char *temp = names[j];
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
