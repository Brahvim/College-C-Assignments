#include "./include/IoUtilsByBrahvim.h"
typedef unsigned long long ull;

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%lld");

int main() {
	const ull uin = ensure_user_inputs_ull(
		"number of elements of the fibonacci series you want printed");

	ull x = 0, y = 1, z;

	for (ull i = 0; i < uin; i++) {
		// Print it:
		printf("`%lld`\n", x);

		// Add to the current number from the sequence:
		z = x + y;
		x = y;
		y = z;
	}
}
