// Author: Brahvim Bhaktvatsal.

#include <math.h> // Used only for `pow()`.
#include <stdio.h>

// Compilation note: Please compile using `gcc -o out 1b.c -lm` on *nix
// systems!
// `-lm` links our program with `libm.so` so we can use `math.h`.
// This is not needed when using MSVC or MinGW on Microsoft Windows
// systems.

#pragma region // Header declarations.

#define TRUE 1
#define FALSE 0

// Functions declared here are defined below `main()`.

/** Clears `stdin` for next use. Call this AFTER reading `stdin` using,
 * say, `scanf()`. */
void clear_stdin(void);

/** Gets the user's input and stores into the given address. */
char get_user_input_for(double *p_input_number_storage_addr);

/**
 * Asks the user for a specific piece of information about the loan,
 * in the form of a `double`.
 *
 * The string passed in is formatted using the format string,
 * `"Please enter the %s: "`, then written to `stdout` using `printf()`.
 */
double ask_user_to_enter(const char const *loan_parameter_name);

/** Calculates simple interest given parameters. */
double find_simple_interest(
	const float principal, const float time, const float rate);

/** Calculates compound interest given parameters. */
double find_compound_interest(
	const float principal, const float time, const float rate);
#pragma endregion

int main()
{
	puts("Welcome to the loan-interest calculator program!\n");

	const double principal = ask_user_to_enter("principal amount");
	const double time = ask_user_to_enter("time of loaning (in years!)");
	const double rate = ask_user_to_enter("interest rate as a percentage");

	printf("\nSimple interest for given parameters: `%lf`.\n",
		   find_simple_interest(principal, time, rate));
	printf("Compound interest for given parameters: `%lf`.\n",
		   find_compound_interest(principal, time, rate));
	puts("Please note that these results are in the same currency as the "
		 "principal amount entered.");

	return 0;
}

// Disallowing custom allocations via `p_storage_var` for simplicity:
double ask_user_to_enter(const char const *p_loan_parameter_name /*, double *p_storage_var */)
{
	double input_number;		 // Performance gain from not initializing memory.
	char input_is_valid = FALSE; // Tells us if `get_user_input()` needs to be re-called.

	// Using a `while` loop instead of a `goto` statement (cross-language
	// compatibility).
	while (!input_is_valid)
	{ // If the input is not valid, continue checking.
		printf("Please enter the %s: ", p_loan_parameter_name);
		input_is_valid = get_user_input_for(&input_number);
	}

	return input_number;
}

double find_simple_interest(
	const float p_principal, const float p_time, const float p_rate)

{
	return (p_principal * p_time * p_rate) / 100.0;
}

double find_compound_interest(
	const float p_principal, const float p_time, const float p_rate)
{
	return p_principal * (pow(1 + p_rate / 100.0, p_time) - 1.0);
}

#pragma region // Input utils.
// Could also use a lambda here.
char get_user_input_for(double *p_input_number_storage_addr)
{
	const int scan_result = scanf(
		"%lf", p_input_number_storage_addr); // Obtaining user input.
	clear_stdin();

	if (scan_result == EOF)
	{
		fputs("An error occurred trying to read your input! Please restart "
			  "this program...\n",
			  stderr);
		return FALSE;
	}

	if (scan_result == 0)
	{
		fputs("\nThat doesn't seem to be valid input.\n", stderr);
		return FALSE;
	}

	return TRUE;
}

void clear_stdin(void) {
	for (char c; !(c == '\n' || c == EOF); c = getchar())
		;
}
#pragma endregion
