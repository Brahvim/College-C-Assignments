// Author: Brahvim Bhaktvatsal.

#pragma region  // Header declarations.
#include <math.h>  // Used only for `pow()`.
#include "include/IoUtilsByBrahvim.h"

// Compilation note: Please compile using `gcc -o out A1b.c -lm` on *nix
// systems!
// `-lm` links our program with `libm.so` so we can use `math.h`.
// This is not needed when using MSVC or MinGW on Microsoft Windows
// systems.

/** Calculates simple interest given parameters. */
double find_simple_interest(const float principal, const float time, const float rate);

/** Calculates compound interest given parameters. */
double find_compound_interest(const float principal, const float time, const float rate);

DECLARE_GENERIC_INPUT_FUNCTIONS(double);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(double, "%lf");

int main() {
  puts("Welcome to the loan-interest calculator program!\n");

  const double principal = ensure_user_inputs_double("principal amount"),
    time = ensure_user_inputs_double("time of loaning (in years!)"),
    rate = ensure_user_inputs_double("interest rate as a percentage");

  printf("\nSimple interest for given parameters: `%lf`.\n", find_simple_interest(principal, time, rate));
  printf("Compound interest for given parameters: `%lf`.\n", find_compound_interest(principal, time, rate));
  puts("Please note that these results are in the same currency as the principal amount entered.");
}

double find_simple_interest(const float p_principal, const float p_time, const float p_rate) {
  return (p_principal * p_time * p_rate) / 100.0;
}

double find_compound_interest(const float p_principal, const float p_time, const float p_rate) {
  return p_principal * (pow(1 + p_rate / 100.0, p_time) - 1.0);
}
