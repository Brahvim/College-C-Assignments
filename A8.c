// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#pragma region // Macros!
/** Allocates using `malloc()` given a type. */
#define MALLOC_TYPE(type) (type *)malloc(sizeof(type))

/** Allocates using `malloc()`, given a name for the allocated pointer, the type of the data to be allocated,
 * and optionally, a code block (or a single line) to run when it fails.
 */
#define CHECKED_MALLOC(ptr_name, type, on_malloc_fail)          \
    type *ptr_name = MALLOC_TYPE(type);                         \
    if (ptr_name == NULL) on_malloc_fail
; // <-- Placed to fix an issue caused by the VSCode formatter (it places an empty space before the next comment!).

/** Declares a function to use `malloc()` to allocate something of the given type. */
#define DECLARE_MALLOCATOR(type) bool create_##type(const type **storage_addr)

/** Declares a function to use `malloc()` to allocate a `struct` given only its name.
 * Use `DECLARE_MALLOCATOR` instead if your structs were `typedef`d.
 */
#define DECLARE_STRUCT_MALLOCATOR(struct_name)                                  \
bool create_ ## struct_name ## _struct(const struct struct_name **storage_addr)
; // <-- Placed to fix an issue caused by the VSCode formatter (it places an empty space before the next comment!).

#define MALLOCATOR_DEFINITION(type, ptr_name, custom_config) {                  \
    /* Allocate one!: */                                                        \
    CHECKED_MALLOC(ptr_name, type, return false);                               \
    /* Assign to caller's pointer!: */                                          \
    *storage_addr = ptr_name;                                                   \
    custom_config;                                                              \
    return true;                                                                \
}

/** Defines a function to use `malloc()` to allocate for a given:
 * 1. Type,
 * 2. Name of the pointer holding `malloc()`'s return value.
 * 3. A code block / single line to make further changes to said pointer.
 *
 * The function thus defined takes in a double-pointer of the given type so assigning it to the received
 * double-pointer is possible.
 * It returns `true` or `false` from `stdbool.h` to indicate the allocation's status.
 *
 * Example:
 * `DEFINE_MALLOCATOR(int, ptr, { *ptr = 0; })` - defines `create_int()`, a function that does things.
 * `int *a; create_int(&a); `
 *
 */
#define DEFINE_MALLOCATOR(type, ptr_name, custom_config)    \
DECLARE_MALLOCATOR(type)                                    \
MALLOCATOR_DEFINITION(type, ptr_name, custom_config)

#define DEFINE_STRUCT_MALLOCATOR(type, ptr_name, custom_config)                             \
DECLARE_STRUCT_MALLOCATOR(type) MALLOCATOR_DEFINITION(struct type, ptr_name, custom_config)
; // <-- Placed to fix an issue caused by the VSCode formatter (it places an empty space before the next comment!).
#pragma endregion

#pragma region // Functions.
#pragma endregion


// Structures (following the convention for the Linux kernel - without `typedef`s):
struct student;
struct result;
#pragma endregion

#pragma region // Structure definitions.
struct student {
    char *name;
    unsigned long long regno;
} /* __attribute__((packed)) */;

struct result {
    float total;
    struct student *student;
    float language, math, science;
} /* __attribute__((packed)) */;
#pragma endregion

#pragma region // Structure de/-allocation function definitions.
#pragma region // Creation,
DEFINE_STRUCT_MALLOCATOR(student, ptr, {
    ptr->regno = 0L;
    strcpy(ptr->name, "");
});

DEFINE_STRUCT_MALLOCATOR(result, ptr, {
    ptr->total = 0;
    ptr->student = NULL;

    ptr->math = 0;
    ptr->science = 0;
    ptr->language = 0;
});
#pragma endregion

#pragma region // Deletion...
bool delete_student_struct(struct student **p_student_ptr) {
    struct student *actual_object = *p_student_ptr;

    if (p_student_ptr == NULL || actual_object == NULL)
        return false;

    // ...Before it's too LATE:
    free(actual_object);
    *p_student_ptr = NULL;
    return true;
}

bool delete_result_struct(struct result **p_result_ptr) {
    struct result *actual_object = *p_result_ptr;

    if (p_result_ptr == NULL || actual_object == NULL)
        return false;

    // ...Before it's too LATE:
    free(actual_object);
    *p_result_ptr = NULL;
    return true;
}
#pragma endregion
#pragma endregion

#pragma region // Structure manipulation function definitions.
#pragma endregion

#pragma region // Structure-array manipulation functions.
#pragma endregion


int main() {
}
