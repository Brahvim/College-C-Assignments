// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

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
}/* __attribute__((packed)) */;
#pragma endregion

#pragma region // Structure de/-allocation function definitions.
#pragma region // Creation,
bool create_student_struct(struct student *p_to_fill) {
    // Allocate one!:
    struct student *to_ret = (struct student *)malloc(sizeof(struct student));

    if (to_ret == NULL)
        return false;

    p_to_fill = to_ret;

    to_ret->regno = 0L;
    strcpy(to_ret->name, "");

    // ...And now, return it:
    return true;
}

bool create_result_struct(struct result *p_to_fill) {
    // Allocate one!:
    struct result *to_ret = (struct result *)malloc(sizeof(struct result));

    if (to_ret == NULL)
        return false;

    p_to_fill = to_ret;

    to_ret->total = 0;
    // to_ret->student = p_student_ptr;

    to_ret->math = 0;
    to_ret->science = 0;
    to_ret->language = 0;

    // ...And now, return it:
    return true;
}
#pragma endregion

#pragma region // Deletion...
struct student *delete_student_struct(struct student *p_student_ptr) {
    if (p_student_ptr != NULL)
        // ...Before it's too LATE:
        free(p_student_ptr);
}

struct result *delete_result_struct(struct result *p_result_ptr) {
    if (p_result_ptr != NULL)
        // ...Before it's too LATE:
        free(p_result_ptr);
}
#pragma endregion
#pragma endregion

#pragma region // Structure manipulation function definitions.
#pragma endregion

#pragma region // Structure-array manipulation functions.
#pragma endregion


int main() {
}
