// Author: Brahvim Bhaktvatsal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IoUtilsByBrahvim.h"

// Type definition for character string.
typedef char *strch_t;

// Function to create and modify a string in dynamically allocated memory.
strch_t alloc_string(const strch_t initial_string);

int main() {
    puts("Welcome to the string modification program!");

    // Prompt the user for an initial string.
    strch_t user_string;
    printf("Please enter a string: ");
    scanf(" %m[^\n]", &user_string);

    // Check if the string is too small.
    if (user_string == NULL || strlen(user_string) == 0) {
        puts("Invalid input. Please enter a non-empty string.");
        return 1; // Return an error code.
    }

    // Call the function to create and modify the string.
    strch_t modified_string = alloc_string(user_string);

    // Print the modified string.
    printf("Modified string: %s\n", modified_string);

    // Free the dynamically allocated memory.
    free(user_string);
    free(modified_string);

    return 0;
}

strch_t alloc_string(const strch_t p_initial_string) {
    // Dynamically allocate memory for the initial string.
    strch_t modified_string = (strch_t)malloc((strlen(p_initial_string) + 1) * sizeof(char));

    if (modified_string == NULL) {
        puts("Memory allocation failed. Exiting...");
        exit(1); // Exit with an error code.
    }

    // Copy the initial string to the dynamically allocated memory.
    strcpy(modified_string, p_initial_string);

    // Prompt the user for a modified string.
    printf("Enter a larger string: ");
    scanf(" %m[^\n]", &modified_string);

    // Check if the modified string is too small.
    if (modified_string == NULL || strlen(modified_string) == 0) {
        puts("Invalid input. Modified string must be non-empty.");
        exit(1); // Exit with an error code.
    }

    return modified_string;
}