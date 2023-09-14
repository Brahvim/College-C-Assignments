// Author: Brahvim Bhaktvatsal

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define OPS_LIST "`+`, `-`, `*`, " /* "`%`, `^` " */ "and `/`"

// TODO: Calculator history! By detecting inputs such as `^[[A` and `^[[B`.

int main() {
    puts("Hello there, and welcome to the simple calculator program!");
    puts("Expressions such as `1234 + 5678` will be evaluated.");
    puts("Note that only the operators " OPS_LIST " are available.");
    puts("Use `^C` to exit.");
    puts("Enter your expressions!:");

    // These are not well-named because I later have to write this stuff BY HAND!:
    struct binary_expr {
        char op;
        double n1, n2, res;
    }  /* __attribute__((packed)) */
    uin = {}; // I'd like to call this `user_input_expr` instead.

    while (true) { // We loop forever so user input is always active.
        for (char input_is_valid = false; !input_is_valid;) {
            input_is_valid = scanf("%lf %c %lf", &uin.n1, &uin.op, &uin.n2) == 3;

            for (char c; !(c = getchar() == '\n' || c == EOF);)
                ;

            if (!input_is_valid) {
                puts("Invalid input, try again!:");
                continue;
            }
        }

        switch (uin.op) {
            case '+':
            uin.res = uin.n1 + uin.n2;
            break;

            case '-':
            uin.res = uin.n1 - uin.n2;
            break;

            case '*':
            uin.res = uin.n1 * uin.n2;
            break;

            case '/':
            if (uin.n2 == 0) {
                puts("Invalid operation - cannot divide by `0`.");
                continue;
            } else
                uin.res = uin.n1 / uin.n2;
            break;

            default:
            puts("Invalid operation! Only " OPS_LIST " are allowed, sorry! Try again:");
        }

        {
            long long rounded = uin.res;

            // If it can be printed without `0`s, print the output without `0`s!:
            if (uin.res == rounded) {
                printf("= `%lld`.\n", rounded);
                continue;
            }
        }

        printf("= `%lf`.\n", uin.res);
    }
}
