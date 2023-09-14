// Author: Brahvim Bhaktvatsal

#include "IoUtilsByBrahvim.h"


// TODO: Calculator history! By detecting inputs such as `^[[A` and `^[[B`.

typedef unsigned long long ull;

int main() {
    puts("Hello there, and welcome to the simple calculator program!");
    puts("Expressions such as `1234 + 5678` can be used here.");
    puts("However, only the operators `+`, `-`, `*`, `/` are available.");
    puts("Enter your expressions!:");

    // These are not well-named because I later have to write this stuff BY HAND!:
    struct binary_expr {
        char op;
        double n1, n2, res;
    }  /* __attribute__((packed)) */
    uin = {}; // I'd like to call this `user_input_expr` instead.

    while (true) {
        for (char input_is_valid = false; !input_is_valid;) {
            input_is_valid = scanf("%lf %c %lf", &uin.n1, &uin.op, &uin.n2) == 3;

            // I like not having spaces in code-only comments, but VSCode doesn't this with other languages...:
            //if (!input_is_valid)
            //input_is_valid = scanf("%lf%c%lf", &uin.n1, &uin.op, &uin.n2) == 3;

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
            if (uin.n1 == 0 || uin.n2 == 0)
                uin.res = 0;
            else {
                puts("Invalid operation.");
                continue;
            }
            break;

            default:
            puts("Invalid operation! Only `+`, `-`, `*` and `/` are allowed, sorry! Try again:");
        }

        {
            long long rounded = uin.res;

            if (uin.res == rounded) {
                printf("= `%lld`.\n", rounded);
                continue;
            }
        }

        printf("= `%lf`.\n", uin.res);
    }
}
