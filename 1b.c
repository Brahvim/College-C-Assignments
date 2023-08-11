#include <math.h>  // Used only for `pow()`.
#include <stdio.h>

// Compilation note: Please compile using `gcc -o out 1b.c -lm` on *nix systems!
// `-lm` links our program with `libm.so` so we can use `math.h`.
// This is not needed when using MSVC or MinGW on Microsoft Windows systems.

#pragma region  // Function declarations.
// Functions declared here are defined below `main()`.

/**
 * Asks the user for a specific piece of information about the loan,
 * in the form of a `double`.
 *
 * The string passed in is formatted using the format string,
 * `"Please enter the %s: "`, then written to `stdout` using `printf()`.
 */
double ask_user_to_enter(const char const *loan_parameter_name);

/** Calculates simple interest given parameters. */
double find_simple_interest(const float principal, const float time, const float rate);

/** Calculates compound interest given parameters. */
double find_compound_interest(const float principal, const float time, const float rate);
#pragma endregion

int main() {
  puts("Welcome to the loan-interest calculator program!\n");

  const double principal = ask_user_to_enter("principal amount");
  const double time = ask_user_to_enter("time of loaning (in years!)");
  const double rate = ask_user_to_enter("interest rate as a percentage");

  putchar('\n');
  printf("Simple interest for given parameters: `%lf`.\n", find_simple_interest(principal, time, rate));
  printf("Compound interest for given parameters: `%lf`.\n", find_compound_interest(principal, time, rate));
  puts("Please note that these results are in the same currency as the principal amount entered.");

  return 0;
}

// Disallowing custom allocations via `p_storage_var` for simplicity:
double ask_user_to_enter(const char const *p_loan_parameter_name /*, double *p_storage_var */) {
  printf("Please enter the %s: ", p_loan_parameter_name);

  double input /* = 0.0*/;                       // Performance gain from not initializing memory.
  const int scan_result = scanf("%lf", &input);  // Obtaining user input.

  if (scan_result == EOF) fputs("An error occurred trying to read your input! Please restart this program...", stderr);

  return input;
}

double find_simple_interest(const float p_principal, const float p_time, const float p_rate) {
  return (p_principal * p_time * p_rate) / 100.0;
}

double find_compound_interest(const float p_principal, const float p_time, const float p_rate) {
  return p_principal * (pow(1 + p_rate / 100.0, p_time) - 1.0);
}
