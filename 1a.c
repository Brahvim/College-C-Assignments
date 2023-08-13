// Author: Brahvim Bhaktvatsal.

#include <stdio.h>	// Used only for `printf()`.

// Parts of my name:
#define FIRST_NAME "Brahvim"
#define SECOND_NAME "Bhaktvatsal"

// My address:
#define ADDRESS "undefined"

int main() {
	// We print everything in quotes!:
	printf("My name: \"%s %s\".\n", FIRST_NAME, SECOND_NAME);
	printf("My address: \"%s\".\n", ADDRESS);

	return 0;
}
