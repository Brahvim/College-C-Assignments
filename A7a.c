// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"

typedef unsigned long long ull;

// Functions:
ull calculate_factorial(const ull number);

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");

int main() {
	puts("Welcome to the factorial calculation program!");
	const ull num = ensure_user_inputs_ull("whole number to find the factorial of"),
		factorial = calculate_factorial(num);

	if (factorial == 0)
		puts("The factorial is too large to be computed!");
	else
		printf("The factorial of this number is: `%llu`.\n", factorial);
}

ull calculate_factorial(const ull p_number) {
	ull factorial = p_number, previous_factorial = 0;

	if (factorial < 1)
		return 0;

	for (ull i = factorial - 1; i > 0; i--) {
		factorial *= i;

		if (previous_factorial > factorial)
			return 0;

		previous_factorial = factorial;
	}

	return factorial;
}
