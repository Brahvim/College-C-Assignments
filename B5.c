// Author: Brahvim Bhaktvatsal
#include <stdio.h>
#include <stdlib.h>
int main() {
    puts("Welcome to the string letter and number counter!");
    puts("Type something, send `EOF` when done, and see for yourself!");
    size_t num_chars = 0, num_nums = 0, chars_before_eof = 0;

    for (char c = '\0'; (c = getchar()) != EOF;) {
        chars_before_eof++;
        // Numbers in ASCII start at `48`, which is `0`.
        // They end at `57`, which is `9`.

        if (c < 58) { // (...that is, less than `58` and not `58`).
            if (c > 47) // (...that is, less than `47` and not `47`).
                num_nums++;
        } else { // If the character is greater than `58`, it must be a character or invalid to us.
            if (c > 64) { // At this point, it must be a letter!
                if (c < 91 || c > 96 && c < 122)
                    num_chars++;
                // The condition after the `||` is supposed to add functionality from this code:
                // else if (c > 96 && c < 122)
                // num_chars++;
            }
        }
    }
    putchar('\n');
    printf("That had `%lu` letters and `%lu` numbers.\n", num_chars, num_nums);
    printf("Overall, `%lu` characters (that includes newline characters!).\n", chars_before_eof);
}
