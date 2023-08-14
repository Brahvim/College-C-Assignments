// Author: Brahvim Bhaktvatsal

#pragma region	// Header declarations.
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define DAYS_PER_MONTH 30

// `__VA_ARGS__` is apparently a standard macro all C compilers define.
#define PRINT_THEN_RETURN_ZERO(format, ...) \
  {                                         \
    printf(format, __VA_ARGS__);            \
    return 0;                               \
  }

typedef unsigned long long ull;

// Is always called after `scanf()` to clear `stdin`, avoiding a buffer overflow.
void clear_stdin(void);

// Displays the prompt in a loop until the user provides valid input.
ull ask_user_to_enter(const char *message);
// ...And to be 'exact':

// Calls `printf("Please enter the %s: ", message)` then
// lets the user enter a number.
// If the input isn't valid, the user is notified,
// then prompted input again.
// Valid input, when obtained, is returned to the caller.

//
char store_validated_user_input_into(ull *input_number_storage_addr);

#pragma endregion

int main(const int p_argc, const char *p_argv[]) {
  const ull number_of_days = ask_user_to_enter("number of days to convert");
  printf("`%lld` days...\n", number_of_days);

  // Special case: Less than a month!:
  if (number_of_days < DAYS_PER_MONTH)
    PRINT_THEN_RETURN_ZERO("That's... `%lld` days, I guess.\n", number_of_days);

  const ull months = number_of_days / DAYS_PER_MONTH;
  const ull left_days = number_of_days - (months * DAYS_PER_MONTH);

  // Special case: Exactly in months!:
  if (left_days == 0)
    PRINT_THEN_RETURN_ZERO("That's exactly `%lld` months!\n", months);

  PRINT_THEN_RETURN_ZERO("That's `%lld` months and `%lld` days.\n", months, left_days);
}

ull ask_user_to_enter(const char *p_message) {
  ull user_input;
  char input_is_valid = FALSE;

  while (!input_is_valid) {
    printf("Please enter the %s: ", p_message);
    input_is_valid = store_validated_user_input_into(&user_input);
  }

  return user_input;
}

#pragma region	// Input utils.
char store_validated_user_input_into(ull *p_addr) {
  const ull scan_result = scanf("%lld", p_addr);
  clear_stdin();

  if (scan_result == 0) {
    // `fputs()` does not insert a new-line like `puts()`!
    fputs("That doesn't seem to be valid input.\n", stderr);
    return FALSE;
  }

  return TRUE;
}

void clear_stdin(void) {
  for (char c; !(c == '\n' || c == EOF); c = getchar())
    ;
}
#pragma endregion
