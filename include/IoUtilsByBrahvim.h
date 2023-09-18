// Author: Brahvim Bhaktvatsal

#pragma once

#include "GenericScanfFxnGenMacros.h"

/** Cleans `stdin` for next use by reading off all `\n` and `EOF` bytes. Must be called after, say, using `scanf()`. */
void clear_stdin(void);
