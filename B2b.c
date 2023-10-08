#include "include/IoUtilsByBrahvim.h"

#pragma region // Header declarations.

typedef unsigned long long ull;

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");

#pragma endregion

int main() {

    ull year = ensure_user_inputs_ull("year you want checked");

    puts(year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)
        ? "This year is a leap year!"
        : "This year is not a leap year...");

}
