#pragma region	// Header declarations.
#include <stdio.h>

typedef unsigned long long ull;
#pragma endregion

int main() {
	printf("Please enter a string to count characters in: ");

	ull string_length = -1;
	for (char c; c != '\n'; c = getchar(), string_length++)
		;

	// Unnecessary check:
	// if (string_length == -1)
	// 	string_length = 0;

	printf("The length of the string is: `%lld` characters.\n", string_length);
	return 0;
}
