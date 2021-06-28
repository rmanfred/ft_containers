#pragma once
#include "iostream"
#include "../Sources.hpp"

# define PROMPT_MAP    YELLOW"Welcome to the map container!\nChoose type to run:\n"RESET

# define TYPE_INT_m       PURPLE"0.int\n"RESET
# define TYPE_DBL_m       PURPLE"1.double\n"RESET
# define TYPE_FLT_m       PURPLE"2.float\n"RESET
# define TYPE_STR_m       PURPLE"3.string\n"RESET
# define TYPE_CHR_m       PURPLE"4.char\n"RESET
# define TYPE_EXT_m       PURPLE"5.exit\n"RESET

enum TYPES_m {
	INT_type_m,
	DBL_type_m,
	FLT_type_m,
	STR_type_m,
	CHR_type_m,
    EXT_type_m
};

void test();
int test_map();
