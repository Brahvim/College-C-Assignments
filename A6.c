// Author: Brahvim Bhaktvatsal

#pragma region	// Header declarations.
#include "include/IoUtilsByBrahvim.h"

DECLARE_GENERIC_INPUT_FUNCTIONS(double);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(double, "%lf");

int main() {
	puts("Welcome to the number comparison program!");

	const double first_number = ensure_user_inputs_double("first number"),
		second_number = ensure_user_inputs_double("second number"),
		third_number = ensure_user_inputs_double("third number"),
		largest = first_number > second_number
		? (first_number > third_number ? first_number : third_number)
		: (second_number > third_number ? second_number : third_number);

	{
		unsigned long long rounded = (unsigned long long)largest;
		if (largest == rounded) {
			printf("The largest of the three is: `%llu`.\n", rounded);
			return 0;
		}
	}

	printf("The largest of the three is: `%lf`.\n", largest);
}
