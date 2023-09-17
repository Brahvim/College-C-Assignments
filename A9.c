// Author: Brahvim Bhaktvatsal

#pragma region	// Header declarations.
#include <math.h>
#include "include/IoUtilsByBrahvim.h"

DECLARE_GENERIC_INPUT_FUNCTIONS(double);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(double, "%lf");

int main() {
  puts("Welcome to the base-to-power calculator!");

  const double base = ensure_user_inputs_double("base to give a power to"),
    power = ensure_user_inputs_double("power to give the base"),
    result = pow(base, power);

  {
    const unsigned long long rounded = (unsigned long long)result;
    if (result == rounded) {
      printf("Here's the result!: `%llu`\n", rounded);
      return 0;
    }
  }

  printf("Here's the result!: `%lf`\n", result);
}
