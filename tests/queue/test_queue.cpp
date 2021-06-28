#include "Test_queue.hpp"

int test_queue()
{
	int input;

	std::cout << PROMPT_QUEUE;
	std::cout << TYPE_INT_q << TYPE_DBL_q << TYPE_FLT_q 
			<< TYPE_STR_q << TYPE_CHR_q << TYPE_EXT_q;
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
	case INT_type_q:
		test_int_q();
		break;
	case DBL_type_q:
		test_double_q();
		break;
	case FLT_type_q:
		test_float_q();
		break;
	case CHR_type_q:
		test_char_q();
		break;
	case STR_type_q:
		test_string_q();
		break;
	case EXT_type_q:
		std::cout << YELLOW"The end of queue's session!\n"RESET;
		break;
	default:
		std::cout << YELLOW"Unknown call!\n"RESET;
		break;
	}
	return 0;
}
