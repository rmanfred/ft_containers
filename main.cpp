#include "tests/Prompt.hpp"

bool get_prompt()
{
    int input;

	std::cout << PROMPT_1 << PROMPT_2;
	std::cout << LIST << VECTOR << MAP << QUEUE << STACK << EXIT; 
	std::cout << GREEN"Your choice: ";
	std::cin >> input;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << RED"Invalid type! Please enter integer from 0 to 5!\n"RESET;
		return true;
	}

    switch(input)
	{
	case CMD_1:
		test_list();
		return true;
	case CMD_2:
		test_vector();
		return true;
	case CMD_3:
		test_map();
		return true;
	case CMD_4:
		test_queue();
		return true;
	case CMD_5:
		test_stack();
		return true;
	case CMD_6:
		std::cout << "The end of session!\n";
		return false;
	default:
		std::cout << YELLOW"Unknown command!\n";
		std::cout << "Try one more time!\n"RESET;
		return true;
	}
}

int main()
{
    while (true)
    {
        if (get_prompt() == false)
            break;
    }
	return 0;
}
