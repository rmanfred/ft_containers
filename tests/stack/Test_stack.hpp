#pragma once
#include "../Sources.hpp"

# define PROMPT_STACK    YELLOW"Welcome to the stack container!\nChoose type to run:\n"RESET

# define TYPE_INT_s       PURPLE"0.int\n"RESET
# define TYPE_DBL_s       PURPLE"1.double\n"RESET
# define TYPE_FLT_s       PURPLE"2.float\n"RESET
# define TYPE_STR_s       PURPLE"3.string\n"RESET
# define TYPE_CHR_s       PURPLE"4.char\n"RESET
# define TYPE_EXT_s       PURPLE"5.exit\n"RESET

enum TYPES {
	INT_type_s,
	DBL_type_s,
	FLT_type_s,
	STR_type_s,
	CHR_type_s,
    EXT_type_s
};

void test_int_s();
void test_char_s();
void test_double_s();
void test_float_s();
void test_string_s();
int test_stack();
