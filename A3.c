// Author: Brahvim Bhaktvatsal

#pragma region	// Header declarations.
#include "include/IoUtilsByBrahvim.h"
#define DAYS_PER_MONTH 30

// `__VA_ARGS__` is apparently a standard macro all C compilers define.
#define PRINT_THEN_RETURN_ZERO(format, ...) \
  {                                         \
    printf(format, __VA_ARGS__);            \
    return 0;                               \
  }

typedef unsigned long long ull;

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");

int main() {
  const ull number_of_days = ensure_user_inputs_double("number of days to convert");
  printf("`%llu` days...\n", number_of_days);

  // Special case: Less than a month!:
  if (number_of_days < DAYS_PER_MONTH)
    PRINT_THEN_RETURN_ZERO("That's... `%llu` days, I guess.\n", number_of_days);

  const ull months = number_of_days / DAYS_PER_MONTH;
  const ull left_days = number_of_days - (months * DAYS_PER_MONTH);

  // Special case: Exactly in months!:
  if (left_days == 0)
    PRINT_THEN_RETURN_ZERO("That's exactly `%llu` months!\n", months);

  PRINT_THEN_RETURN_ZERO("That's `%llu` months and `%llu` days.\n", months, left_days);
}
