// Author: Brahvim Bhaktvatsal
#pragma once

#include "Boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define DECLARE_GENERIC_INPUT_SCANNER(type)				\
char get_user_input_as_##type(type *type##_storage_addr);

#define DEFINE_GENERIC_INPUT_SCANNER(type, fmt_string)											\
	char get_user_input_as_##type (type *p_storage_addr) {										\
		if (p_storage_addr == NULL)																\
			return FALSE;																		\
																								\
		const int scan_result = scanf((fmt_string), p_storage_addr);							\
																								\
		if (scan_result == EOF) {																\
			fputs("The program's ability to take input was turned off. Exiting...\n", stderr);	\
			exit(EXIT_FAILURE);																	\
			return FALSE;																		\
		} else if (scan_result != 1) {															\
			for (char c; (c = getchar()) != '\n' && c != EOF;);									\
			return FALSE;																		\
		}																						\
																								\
		return TRUE;																			\
	}

#define DECLARE_GENERIC_INPUT_ENSURER(type)				\
type ensure_user_input_as_##type(const char *prompt);

#define DEFINE_GENERIC_INPUT_ENSURER(type)										\
type ensure_user_input_as_##type(const char *p_prompt) {                       	\
	type user_input = 0;														\
    for (char input_is_valid = FALSE; !input_is_valid;) {                       \
            printf("Please enter the %s: ", p_prompt);                          \
        if (p_prompt == NULL)                                                   \
            printf("Programs expects input: ");                                 \
        else                                                                    \
            puts("That was invalid input.");                          			\
        input_is_valid = get_user_input_as_##type(&user_input);               	\
    }                                                                           \
																				\
	return user_input;															\
}

#define DECLARE_GENERIC_INPUT_FUNCTIONS(type)		\
DECLARE_GENERIC_INPUT_SCANNER(type)					\
DECLARE_GENERIC_INPUT_ENSURER(type)

#define DEFINE_GENERIC_INPUT_FUNCTIONS(type, fmt_string)		\
DEFINE_GENERIC_INPUT_SCANNER(type, fmt_string)					\
DEFINE_GENERIC_INPUT_ENSURER(type)
