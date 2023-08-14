#pragma region	// Header declarations.
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef char* string;
typedef const char* const_string;
typedef const char const* const_string_reference;

void clear_stdin(void);
const_string ask_user_for_input(const_string message);
char store_valid_user_input_into(string storage_addr);

#pragma endregion

int main() { return 0; }

string ask_user_for_input(const_string p_message) {
  string user_input = calloc(sizeof(char), 99);
  char input_is_valid;

  // Expand `user_input` with `realloc()` as needed.

  while (!input_is_valid) {
    input_is_valid = store_valid_user_input_into(user_input);
  }

  return user_input;
}

char store_valid_user_input_into(string p_storage_addr) {
  const int scan_result = scanf("s", p_storage_addr);

  fgets

      if (scan_result == 0) {
    puts("The doesn't seem to be valid input.");
    return FALSE;
  }

  return TRUE;
}

void clear_stdin(void) {
  for (char c; !(c == EOF || c == '\n'; c = getchar()))
    ;
}
