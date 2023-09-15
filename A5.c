// Author: Brahvim Bhaktvatsal

#include "include/IoUtilsByBrahvim.h"

#pragma region // Header declarations.
#define CELSIUS_TO_FAHRENHEIT(celsius) (((celsius) / 1.8) + 32)
// ^^^ Could also use `9 / 5` but `1.8` is just as precise and faster.

DECLARE_GENERIC_INPUT_FUNCTIONS(double);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(double, "%lf");

int main() {
    puts("Welcome to the F2C temperature conversion program!");
    printf("In Fahrenheit, that's `%lf` degrees.\n",
        CELSIUS_TO_FAHRENHEIT(ensure_user_inputs_double("temperature in celsius")));
}
