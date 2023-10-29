#include <limits.h>
#include "./include/IoUtilsByBrahvim.h"

#pragma region // Header declarations.
typedef unsigned long long ull;

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");

int main() {
	const ull uin = ensure_user_inputs_ull(
		"number of elements of the fibonacci series you want printed");

	ull x = 0, y = 1, z, last = 0, sum = 0;

	for (ull i = 0; i < uin; i++) {
		// Check for overflow:
		if (x < last) {
			puts("64-bit limit hit! Stopping...");
			break;
		}

		// We're also storing a sum, apparently!:
		sum += x;

		// Print it:
		printf("%llu\n", x);

		// Store the last value:
		last = x;

		// Add to the current number from the sequence:
		z = x + y;
		x = y;
		y = z;
	}

	printf("\nSum: `%llu`.\n", sum);
}
