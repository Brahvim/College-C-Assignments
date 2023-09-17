// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"
#include <math.h>
#include <string.h>

// Structures:
struct complete_result;
struct student;
#pragma endregion

#pragma region // Structure definitions.
struct student {
    char *name;
    unsigned long long regno;
} /* __attribute__((packed)) */;

struct complete_result {
    float total;
    float language, math, science;
}/* __attribute__((packed)) */;
#pragma endregion

#pragma region // Structure manipulation functions.
#pragma endregion

#pragma region // Structure-array manipulation functions.
#pragma endregion

int main() {
}
