// Author: Brahvim Bhaktvatsal

#include <stdio.h>

int main() {
	printf("Please enter a string to count characters in: ");

	unsigned long long string_length = 0;
	for (char c; c = getchar(); string_length++) {
		if (c == '\n') {
			printf("The length of the string is: `%llu` characters.\n", string_length);
			return 0;
		} else if (c == EOF) {
			printf("\nThe length of the string is: `%llu` characters.\n", string_length);
			return 0;
		}
	}
}
