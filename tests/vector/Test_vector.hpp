#pragma once
#include "../Sources.hpp"

# define PROMPT_VECTOR    YELLOW"Welcome to the vector container!\nChoose type to run:\n"RESET

# define TYPE_INT_v       PURPLE"0.int\n"RESET
# define TYPE_DBL_v       PURPLE"1.double\n"RESET
# define TYPE_FLT_v       PURPLE"2.float\n"RESET
# define TYPE_STR_v       PURPLE"3.string\n"RESET
# define TYPE_CHR_v       PURPLE"4.char\n"RESET
# define TYPE_EXT_v       PURPLE"5.exit\n"RESET

enum TYPES_V {
	INT_type_v,
	DBL_type_v,
	FLT_type_v,
	STR_type_v,
	CHR_type_v,
    EXT_type_v
};

void test_int_v();
void test_char_v();
void test_double_v();
void test_float_v();
void test_string_v();
int test_vector();
