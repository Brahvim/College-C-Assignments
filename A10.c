#include <stdio.h>

int main() {
	printf("Please enter a string to count characters in: ");

	unsigned long long string_length = -1;
	for (char c; c != '\n'; c = getchar(), string_length++)
		;

	printf("The length of the string is: `%lld` characters.\n", string_length);
	return 0;
}
