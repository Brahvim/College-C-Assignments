// Author: Brahvim Bhaktvatsal
#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DECLARE_GENERIC_INPUT_SCANNER(type)				\
char parse_user_input_as_##type(type *type##_storage_addr);

#define DEFINE_GENERIC_INPUT_SCANNER(type, fmt_string)											\
	char parse_user_input_as_##type (type *p_storage_addr) {										\
		if (p_storage_addr == NULL)																\
			return false;																		\
																								\
		const int scan_result = scanf((fmt_string), p_storage_addr);							\
																								\
		if (scan_result == EOF) {																\
			fputs("The program's ability to take input was turned off. Exiting...\n", stderr);	\
			exit(EXIT_FAILURE);																	\
			return false;																		\
		} else if (scan_result != 1) {															\
			for (char c; (c = getchar()) != '\n' && c != EOF;);									\
			return false;																		\
		}																						\
																								\
		return true;																			\
	}

#define DECLARE_GENERIC_INPUT_ENSURER(type)				\
type ensure_user_inputs_##type(const char *prompt);

#define DEFINE_GENERIC_INPUT_ENSURER(type)										\
type ensure_user_inputs_##type(const char *p_prompt) {                       	\
    type user_input;                                                            \
    for (char input_is_valid = false; !input_is_valid;) {                       \
        if (p_prompt == NULL)                                                   \
            printf("Programs expects input: ");                                 \
        else                                                                    \
            printf("Please enter the %s: ", p_prompt);                          \
        input_is_valid = parse_user_input_as_##type(&user_input);               	\
    }                                                                           \
	return user_input;															\
                                                                                \
}

#define DECLARE_GENERIC_INPUT_FUNCTIONS(type)		\
DECLARE_GENERIC_INPUT_SCANNER(type)					\
DECLARE_GENERIC_INPUT_ENSURER(type)

#define DEFINE_GENERIC_INPUT_FUNCTIONS(type, fmt_string)		\
DEFINE_GENERIC_INPUT_SCANNER(type, fmt_string)					\
DEFINE_GENERIC_INPUT_ENSURER(type)
