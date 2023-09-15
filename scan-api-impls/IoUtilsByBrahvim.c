// Author: Brahvim Bhaktvatsal

#include "include/IoUtilsByBrahvim.h"

void clear_stdin(void) {
    for (char c; !((c = getchar()) == '\n' || c == EOF);)
        ;
}
