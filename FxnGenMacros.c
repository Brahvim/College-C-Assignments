#include "GenericScanfFxnGenMacros.h"

typedef unsigned long long ull;

// DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%lld");

int main() {
    puts("Hi!");
    printf("So... `%lld` is that number, huh? Got that!\n",
        ensure_user_input_as_ull("\b\b\b\ba number while you're here?"));


    printf("So... `%lld` is that number, huh? Got that!\n",
        ensure_user_input_as_ull("\b\b\b\banother number, I guess?"));
}
