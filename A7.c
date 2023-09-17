// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"

typedef unsigned long long ull;

// Functions:
ull factorial(ull number);

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");


int main() {
	puts("Welcome to the factorial calculation program!");
	const ull num = ensure_user_inputs_ull("whole number to find the factorial of");
	printf("The factorial of this number is: `%lld`.\n", factorial(num));
}

ull factorial(ull p_number) {
	ull factorial = p_number;

	if (factorial < 1)
		return 0;

	for (ull i = factorial - 1; i > 0; i--)
		factorial *= i;

	return factorial;
}
