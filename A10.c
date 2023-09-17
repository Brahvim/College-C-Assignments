// Author: Brahvim Bhaktvatsal

#include <stdio.h>

int main() {
	puts("Please enter a string to count characters in! (Send `EOF` to exit):");

	unsigned long long string_length = 0;

	while (getchar() != EOF)
		string_length++;

	printf("\nThe length of the string is: `%llu` characters.\n", string_length);
}
