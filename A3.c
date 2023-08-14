#include <stdio.h>
#include <string.h>

#pragma region  // Header declarations.

#define TRUE 1
#define FALSE 0

typedef unsigned long long ull;

void ensure_user_input(const char *message);
char get_user_input(int *storage_var);

void clear_stdin(void);

#pragma endregion

int main() { return 0; }

void ensure_user_input(const char *p_message) {
  char input_is_valid = TRUE;
  while (!input_is_valid) {
  }
}

char get_user_input(int *p_storage_var) {
  const int scan_result = scanf("%d", p_storage_var);
  clear_stdin();

  if (scan_result == 0) {
    puts("\nSorry, but that doesn't seem to be valid input! Please try again...");
    return FALSE;
  }

  return TRUE;
}

void clear_stdin(void) {
  for (char c; !(c == EOF || c == '\n'); c = getchar())
    ;
}
