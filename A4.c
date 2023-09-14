#include "IoUtilsByBrahvim.h"

typedef unsigned long long ull;

enum binary_expr_op {
    ADD = '+',
    SUB = '-',
    DIV = '/',
    MULT = '*',
};

struct binary_expr {
    enum binary_expr_op op;
    ull n1, n2;
};

int main() {
    puts("Hello there, and welcome to the simple calculator program!");
    puts("Expressions such as `1234 + 5678` can be used here.");
    puts("However, only the operators `+`, `-`, `*`, `/` are available.");

    printf("Please enter your expression: ");

    for (char input_is_valid = FALSE; !input_is_valid;) {

    }
}

char get_user_input_for_struct(const char *p_format_string, ...) {
    va_list args;
    va_start(args, p_format_string);
    const int scan_result = vscanf(p_format_string, args);
    va_end(args);

    return FALSE;
}
