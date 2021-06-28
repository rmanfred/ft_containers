#include "Test_stack.hpp"

int test_stack()
{
	int input;

	std::cout << PROMPT_STACK;
	std::cout << TYPE_INT_s << TYPE_DBL_s << TYPE_FLT_s 
			<< TYPE_STR_s << TYPE_CHR_s << TYPE_EXT_s;
	std::cout << GREEN"Your choice: ";
	std::cin >> input;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << RED"Invalid type! Please enter integer from 0 to 5!\n"RESET;
		return 0;
	}
	switch(input)
	{
	case INT_type_s:
		test_int_s();
		break;
	case DBL_type_s:
		test_double_s();
		break;
	case FLT_type_s:
		test_float_s();
		break;
	case CHR_type_s:
		test_char_s();
		break;
	case STR_type_s:
		test_string_s();
		break;
	case EXT_type_s:
		std::cout << YELLOW"The end of stack's session!\n"RESET;
		break;
	default:
		std::cout << YELLOW"Unknown call!\n"RESET;
		break;
	}
	return 0;
}
