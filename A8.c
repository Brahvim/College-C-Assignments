// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_TYPE(type) (type *)malloc(sizeof(type))

#define CHECKED_MALLOC(ptr_name, type, on_malloc_fail)          \
type *ptr_name = MALLOC_TYPE(type);                             \
    if (ptr_name == NULL) on_malloc_fail // Macro functions generally receive a semi-colon anyway.

#define DECLARE_MALLOCATOR(type) bool create_##type(const type **storage_addr)

#define DECLARE_STRUCT_MALLOCATOR(struct_name)                                  \
bool create_ ## struct_name ## _struct(const struct struct_name **storage_addr)

#define DEFINE_MALLOCATOR(type, custom_config)                      \
DECLARE_MALLOCATOR(type) {                                          \
    CHECKED_MALLOC(to_fill, type, return false);                    \
    *storage_addr = to_fill;                                        \
    custom_config;                                                  \
    return true;                                                    \
}

#define DEFINE_STRUCT_MALLOCATOR(type, custom_config)                       \
DECLARE_STRUCT_MALLOCATOR(type) {                                           \
    CHECKED_MALLOC(to_fill, type, return false);                            \
    custom_config;                                                          \
    return true;                                                            \
}


// Structures (following the convention for the Linux kernel - without `typedef`s):
struct student;
struct result;
#pragma endregion

DECLARE_STRUCT_MALLOCATOR(student);

#pragma region // Structure definitions.
struct student {
    char *name;
    unsigned long long regno;
} /* __attribute__((packed)) */;

struct result {
    float total;
    struct student *student;
    float language, math, science;
}/* __attribute__((packed)) */;
#pragma endregion

#pragma region // Structure de/-allocation function definitions.
#pragma region // Creation,
// bool create_student_struct(const struct student **p_storage_addr) {
//     // Allocate one!:
//     CHECKED_MALLOC(to_fill, struct student, return false);

//     // Assign to caller's pointer:
//     *p_storage_addr = to_fill;

DEFINE_MALLOCATOR(int, printf("LOL"));

DEFINE_STRUCT_MALLOCATOR(student, {
    to_fill->regno = 0L;
    strcpy(to_fill->name, "");
    });

//     // ...And now, return it:
//     return true;
// }

bool create_result_struct(const struct result **p_to_fill) {
    // Allocate one!:
    struct result *to_fill = (struct result *)malloc(sizeof(struct result));

    if (to_fill == NULL)
        return false;

    *p_to_fill = to_fill;

    to_fill->total = 0;
    // to_ret->student = p_student_ptr;

    to_fill->math = 0;
    to_fill->science = 0;
    to_fill->language = 0;

    // ...And now, return it:
    return true;
}
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
