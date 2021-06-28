#include "Test_list.hpp"

int test_list()
{
	int input;

	std::cout << PROMPT_LIST;
	std::cout << TYPE_INT << TYPE_DBL << TYPE_FLT 
			<< TYPE_STR << TYPE_CHR << TYPE_EXT;
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
	case INT_type:
		test_int();
		break;
	case DBL_type:
		test_double();
		break;
	case FLT_type:
		test_float();
		break;
	case STR_type:
		test_string();
		break;
	case CHR_type:
		test_char();
		break;
	case EXT_type:
		std::cout << YELLOW"The end of list's session!\n"RESET;
		break;
	default:
		std::cout << YELLOW"Unknown call!\n"RESET;
		break;
	}
	return 0;
}
