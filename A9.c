#pragma region	// Header declarations.
#include <math.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

// Prompts the user for input till valid input is received
// using a `printf("Please enter the `%s`: ", message)` call.
double ask_user_to_enter(const char *message);

// Stores the user's input into `storage_addr` using `scanf()`,
// returning `TRUE` or `FALSE` to state if it was a part of valid input.
char store_valid_user_input_into(double *storage_addr);

void clear_stdin(void);
#pragma endregion

int main() {
  puts("Welcome to the base-to-power calculator!");

  const double base = ask_user_to_enter("base to give a power to");
  const double power = ask_user_to_enter("power to give the base");
  const double result = pow(base, power);
  const int result_as_int = (int)result;

  if (result == result_as_int) {
    printf("Here's the result!: `%d`\n", result_as_int);
    return 0;
  }

  printf("Here's the result!: `%lf`\n", result);
  return 0;
}

double ask_user_to_enter(const char *p_message) {
  double user_input;
  char input_is_valid = FALSE;

  while (!input_is_valid) {
    printf("Please enter the `%s`: ", p_message);
    input_is_valid = store_valid_user_input_into(&user_input);
  }

  return user_input;
}

char store_valid_user_input_into(double *p_storage_addr) {
  const int scan_result = scanf("%lf", p_storage_addr);
  clear_stdin();

  if (scan_result == 0) {
    puts("That doesn't seem to be valid input.");
    return FALSE;
  }

  return TRUE;
}

void clear_stdin(void) {
  for (char c; !(c == EOF || c == '\n'); c = getchar())
    ;
}
