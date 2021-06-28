#include "Test_vector.hpp"

int test_vector()
{
	int input;

	std::cout << PROMPT_VECTOR;
	std::cout << TYPE_INT_v << TYPE_DBL_v << TYPE_FLT_v 
			<< TYPE_STR_v << TYPE_CHR_v << TYPE_EXT_v;
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
	case INT_type_v:
		test_int_v();
		break;
	case DBL_type_v:
		test_double_v();
		break;
	case FLT_type_v:
		test_float_v();
		break;
	case CHR_type_v:
		test_char_v();
		break;
	case STR_type_v:
		test_string_v();
		break;
	case EXT_type_v:
		std::cout << YELLOW"The end of vector's session!\n"RESET;
		break;
	default:
		std::cout << YELLOW"Unknown call!\n"RESET;
		break;
	}
	return 0;
}
