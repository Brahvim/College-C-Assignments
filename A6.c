#pragma region	// Header declarations.
#include <stdio.h>

#define FALSE 0
#define TRUE 1

// Ensures that the user enters some valid input by
// prompting them recursively, returning what is obtained.
//
// The user is prompted using `printf("Please enter the %s: ", message)`.
double ask_user_to_enter(const char *message);

// Stores user input into the passed buffer,
// returning `TRUE` or `FALSE` to show it's validity as an `int`.
char store_and_validate_user_input(double *storage_addr);

// Clears `stdin`. Call after each call to `scanf()`!
void clear_stdin(void);

#pragma endregion

int main() {
	puts("Welcome to the number comparison program!");

	const double first_number = ask_user_to_enter("first number");
	const double second_number = ask_user_to_enter("second number");
	const double third_number = ask_user_to_enter("third number");

	printf("The largest of the three is: `%lf`.\n",
		first_number > second_number 
		? (first_number > third_number ? first_number : third_number)
		: (second_number > third_number ? second_number : third_number));

	return 0;
}

double ask_user_to_enter(const char *p_message) {
	double user_input;

	for (char input_is_valid = FALSE; !input_is_valid;) {
		printf("Please enter the %s: ", p_message);
		input_is_valid = store_and_validate_user_input(&user_input);
	}

	return user_input;
}

char store_and_validate_user_input(double *p_storage_addr) {
	const int scan_result = scanf("%lf", p_storage_addr);
	clear_stdin();

	if (scan_result == 0) {
		fputs("That's not valid input...\n\n", stderr);
		return FALSE;
	}

	return TRUE;
}

void clear_stdin(void) {
	for (char c; !(c == EOF || c == '\n'); c = getchar())
		;
}
