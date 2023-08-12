#include <stdio.h>

#pragma region  // Header declarations.
// Declared these as `const char`s earlier to avoid casting to a `char`,
// speeding up compilation by reducing checks, since `0` has the same
// byte sequence regardless of the data type used.
// ...Removed the cast.

#define TRUE 1
#define FALSE 0

// Shorthand!
typedef unsigned char uchar;
typedef unsigned long long ull;

/** Clears `stdin` for next use. Call this AFTER reading `stdin` using, say, `scanf()`. */
void clear_stdin(void);

/** Ensures getting a valid number as input from the user, for the purposes of this program. */
ull ensure_user_input(void);

/**
 * Takes in the address of the location in which to store the input,
 * returning whether or not the operation was successful.
 */
char get_user_input(ull *input_number_storage_addr);
#pragma endregion

int main() {
  puts("Welcome to the digit manipulation program!\n");

  ull input_number = ensure_user_input();

  uchar num_digits = 1;  // No 64-bit `ull` can have `255` digits or more, so we use a `uchar` for this.
  // We set this to `1` for now, then decrease it after the loop in which we show reversed digits, since it needs to
  // have `1` as the first index.

  // The sum of the digits of `1,84,46,74,40,73,70,95,51,615`, the largest `ull` AKA
  //  `64`-bit number, is `87`. Therefore, I use a `uchar` for storing the sum.
  uchar digits_sum = 0;

  puts("Here are all digits in the number, in reverse order:");

  for (; input_number != 0; num_digits++) {
    uchar digit = input_number % 10;  // Extract a digit.
    digits_sum += digit;              // Add to the sum of digits.
    input_number /= 10;               // Modify the original number!

    printf("Digit `%d`: `%d`.\n", num_digits, digit);  // ...Show it off!
  }

  num_digits -= 1;  // When showing each digit in the loop, we needed to count from `1`. Now we don't!

  printf("Thus, the total number of digits was: `%d`.\n", num_digits);
  printf("Their sum, is: `%d`.\n", digits_sum);

  return 0;
}

ull ensure_user_input(void) {
  ull input_number;             // Performance gain from not initializing memory.
  char input_is_valid = FALSE;  // Tells us if `get_user_input()` needs to be re-called.

  // Using a `while` loop instead of a `goto` statement (cross-language compatibility).
  while (!input_is_valid) {  // If the input is not valid, continue checking.
    input_is_valid = get_user_input(&input_number);
  }

  return input_number;
}

char get_user_input(ull *p_input_number_storage_addr) {
  printf("Please enter the number to analyze: ");
  const int scan_result = scanf("%llu", p_input_number_storage_addr);  // Obtaining user input.

  if (scan_result == EOF) {
    fputs("An error occurred trying to read your input! Please restart this program...\n", stderr);
    clear_stdin();
    return FALSE;
  }

  if (scan_result == 0) {
    fputs("\nThat doesn't seem to be valid input.\n", stderr);
    clear_stdin();
    return FALSE;
  }

  clear_stdin();
  return TRUE;
}

void clear_stdin(void) {
  for (char c; !(c == '\n' || c == EOF); c = getchar())
    ;
}
