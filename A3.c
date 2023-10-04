// Author: Brahvim Bhaktvatsal

#pragma region	// Header declarations.
#include "include/IoUtilsByBrahvim.h"
#define DAYS_PER_MONTH 30

typedef unsigned long long ull;

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");

int main() {
  const ull number_of_days = ensure_user_inputs_ull("number of days to convert");
  printf("`%llu` days...\n", number_of_days);

  // Special case: Less than a month!:
  if (number_of_days < DAYS_PER_MONTH) {
    printf("That's... `%llu` days, I guess.\n", number_of_days);
    exit(EXIT_SUCCESS);
  }

  const ull months = number_of_days / DAYS_PER_MONTH,
    left_days = number_of_days - (months * DAYS_PER_MONTH);

  // Special case: Exactly in months!:
  if (left_days == 0) {
    printf("That's exactly `%llu` months!\n", months);
    exit(EXIT_SUCCESS);
  }

  printf("That's `%llu` months and `%llu` days.\n", months, left_days);
}
