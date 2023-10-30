#include <stdio.h>

int *int_sum(const int a, const int b);

int main(const int p_argc, const char const **p_argv) {
    // Should cause a `SIGSEGV`:

    printf("Sum of `5` and `7` is: `%d`.\n", *(int_sum(5, 7)));
}

int *int_sum(const int a, const int b) {
    int sum = a + b;
    return &sum;
}
