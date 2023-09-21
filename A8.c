// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long ull;

#pragma region // Macros to help me write this on paper quicker!
/** Allocates using `malloc()` given a type. */
#define MALLOC_TYPE(type) (type *)malloc(sizeof(type))

/** Allocates using `malloc()`, given a name for the allocated pointer, the type of the data to be allocated,
 * and optionally, a code block (or a single line) to run when it fails.
 */
#define CHECKED_MALLOC(ptr_name, type, on_malloc_fail)          \
    type *ptr_name = MALLOC_TYPE(type);                         \
    if (ptr_name == NULL) on_malloc_fail
#pragma endregion

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
DECLARE_GENERIC_INPUT_FUNCTIONS(float);

// "Keep it simple, stupid!":
// PS These declarations follow the Linux kernel's naming convention (no `typedef`).
struct student;
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");// Structures (following the convention for the Linux kernel - without `typedef`s):struct student;
DEFINE_GENERIC_INPUT_FUNCTIONS(float, "%f");// Structures (following the convention for the Linux kernel - without `typedef`s):struct student;

struct student {
    char *name;
    ull regno;
    float m1, m2, m3, m4, m5, m6;
} /* __attribute__((packed)) */;

int main() {
    puts("Welcome to the marksheet-generation program!");

    ull num_students = ensure_user_inputs_ull("number of students");

    CHECKED_MALLOC(students_array, struct student, printf("Heap allocation error on line `%d`!\n", __LINE__));

    for (ull i = 1; i <= num_students; i++) {
        puts("For student `%llu`:\n");
        puts("Please enter the name of the student:");
        puts("Please enter the registration number of the student:");
    }

}

/*
ull ensure_user_inputs_string(char **p_address_storage) {
    char *string = NULL;
    ull string_length = 10;

    string = calloc(sizeof(char), string_length);

    ull iterable = 10;
    for (char c; c = getchar(); iterable--) {

        if (iterable == 1) {
            if (string_length == ULLONG_MAX) {
                char *new_string = realloc(string, string_length *= 2);
            }
        }

        if (c == '\n') {
        } else if (c == EOF) {
        }
    }
}
*/
