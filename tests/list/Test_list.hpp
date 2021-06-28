#pragma once
#include "../Sources.hpp"

# define PROMPT_LIST    YELLOW"Welcome to the list container!\nChoose type to run:\n"RESET

# define TYPE_INT       PURPLE"0.int\n"RESET
# define TYPE_DBL       PURPLE"1.double\n"RESET
# define TYPE_FLT       PURPLE"2.float\n"RESET
# define TYPE_STR       PURPLE"3.string\n"RESET
# define TYPE_CHR       PURPLE"4.char\n"RESET
# define TYPE_EXT       PURPLE"5.exit\n"RESET

enum TYPE {
	INT_type,
	DBL_type,
	FLT_type,
	STR_type,
	CHR_type,
    EXT_type
};

void test_int();
void test_char();
void test_double();
void test_float();
void test_string();
int test_list();

