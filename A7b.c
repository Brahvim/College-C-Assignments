// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"

typedef unsigned long long ull;

// Functions:
bool is_prime(const ull number);

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");

int main() {
	puts("Welcome to the naive-algorithm, prime number generation program!");
	const ull count = ensure_user_inputs_ull("number of prime numbers to find!");

	for (ull i = 0, found = 0, p; found != count; i++) {
		if (i < p)
			break;

		if (is_prime(i))
			printf("Prime `%llu`: `%llu`.\n", ++found, i);

		// I'm now obsessed with not letting integers overflow now!:
		p = i;
	}
}

bool is_prime(const ull p_number) {
	bool flag = true;
	const ull check_till = p_number / 2 + 1;

	for (ull i = 2; i < check_till; i++)
		flag = p_number % i != 0;

	return flag;
}
