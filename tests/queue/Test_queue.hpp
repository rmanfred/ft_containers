#pragma once
#include "../Sources.hpp"

# define PROMPT_QUEUE    YELLOW"Welcome to the queue container!\nChoose type to run:\n"RESET

# define TYPE_INT_q			PURPLE"0.int\n"RESET
# define TYPE_DBL_q 		PURPLE"1.double\n"RESET
# define TYPE_FLT_q        	PURPLE"2.float\n"RESET
# define TYPE_STR_q        	PURPLE"3.string\n"RESET
# define TYPE_CHR_q        	PURPLE"4.char\n"RESET
# define TYPE_EXT_q        	PURPLE"5.exit\n"RESET

enum TYPES_q {
	INT_type_q,
	DBL_type_q,
	FLT_type_q,
	STR_type_q,
	CHR_type_q,
    EXT_type_q
};

void test_int_q();
void test_char_q();
void test_double_q();
void test_float_q();
void test_string_q();
int test_queue();
