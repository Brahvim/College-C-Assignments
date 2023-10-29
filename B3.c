#include <stdio.h>

int main(const int p_count, char const **p_args) {
    // `p_args` would be in the format, `B3.out [ARGS]`
    // - the name of the program is still in there!

    if (p_count < 2) // Thus, we always need two or more elements in `p_args`.
        puts("This program prints arguments provided to it in reverse.\n"
            "Please consider providing some.");
    else
        for (int i = p_count - 1; i > 0; i--)
            puts(p_args[i]);
}
