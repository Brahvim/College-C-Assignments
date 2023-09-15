// Author: Brahvim Bhaktvatsal

#include "include/IoUtilsByBrahvim.h"

#pragma region  // Header declarations.
// Declared these as `const char`s earlier to avoid casting to a `char`,
// speeding up compilation by reducing checks, since `0` has the same
// byte sequence regardless of the data type used.
// ...Removed the cast.

// Shorthand!
typedef unsigned char uchar;
typedef unsigned long long ull;

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");

int main() {
  puts("Welcome to the digit manipulation program!\n");

  ull input_number = ensure_user_inputs_ull("digit you want analyzed");

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

  printf("Thus, the total number of digits is: `%d`.\n", num_digits);
  printf("Their sum, is: `%d`.\n", digits_sum);

  return 0;
}
