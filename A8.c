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
} /* __attribute__((packed)) */;
#pragma endregion

int main() {
}
