#include "Test_map.hpp"

int test_map()
{
	int input;

	std::cout << PROMPT_MAP;
	std::cout << TYPE_INT_m << TYPE_DBL_m << TYPE_FLT_m 
			<< TYPE_STR_m << TYPE_CHR_m << TYPE_EXT_m;
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
	case INT_type_m:
		test();
		break;
	case DBL_type_m:
		test();
		break;
	case FLT_type_m:
		test();
		break;
	case CHR_type_m:
		test();
		break;
	case STR_type_m:
		test();
		break;
	case EXT_type_m:
		std::cout << YELLOW"The end of map's session!\n"RESET;
		break;
	default:
		std::cout << YELLOW"Unknown call!\n"RESET;
		break;
	}
	return 0;
}
