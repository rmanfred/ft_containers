#include "../Sources.hpp"

void test_char_q()
{
    std::cout << "Test-char for queue\n";

    std::queue<char> original;
    ft::queue<char> mine;

    std::cout << GREEN"***************Empty*****************\n"RESET;
    if (original.empty())
        std::cout << "Original is empty!\n";
    else
        std::cout << "Original is not empty!\n";
    
    std::cout << YELLOW"*************************************\n"RESET;
    
    if (mine.empty())
        std::cout << "Mine is empty!\n";
    else
        std::cout << "Mine is not empty!\n";

    std::cout << GREEN"************Push-Pop-Front************\n"RESET;
    std::cout << "Pushing into orig... a, b, c, d: \n";
    
    original.push('a');
    original.push('b');
    original.push('c');
    original.push('d');

    std::cout << "Original  size: " << original.size() << "!\n";

    std::cout << "Popping...\n";
    while (!original.empty())
    {
        std::cout << ' ' << original.front();
        original.pop();
    }
    std::cout << std::endl;

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Pushing into mine... a, b, c, d: \n";

    mine.push('a');
    mine.push('b');
    mine.push('c');
    mine.push('d');

    std::cout << "Mine      size: " << mine.size() << "!\n";

    std::cout << "Popping...\n";
    while (!mine.empty())
    {
        std::cout << ' ' << mine.front();
        mine.pop();
    }
    std::cout << std::endl;

    std::cout << GREEN"************Push-Pop-Back*************\n"RESET;
    std::cout << "Pushing into orig...A, B, C: \n";
    
    int j = 65;
    original.push(j);

    std::cout << "Original  size: " << original.size() << "!\n";

    std::cout << "Popping...\n";
    while (!original.empty() && j != 68)
    {
        original.push(j++);
        std::cout << ' ' << original.back();
        original.pop();
    }
    std::cout << std::endl;

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Pushing into mine...A, B, C: \n";

    int i = 65;
    mine.push(i);
    std::cout << "Mine      size: " << mine.size() << "!\n";

    std::cout << "Popping...\n";
    while (!mine.empty() && i != 68)
    {
        mine.push(i++);
        std::cout << ' ' << mine.back();
        mine.pop();
    }
    std::cout << std::endl;

    std::cout << GREEN"****************Size*****************\n"RESET;
    std::cout << "Original  size: " << original.size() << "!\n";
    std::cout << "Mine      size: " << mine.size() << "!\n";

    std::cout << PURPLE"************************************\n"RESET;
    std::cout << PURPLE"********Not member functions********\n"RESET;
    std::cout << PURPLE"************************************\n"RESET;
    std::cout << "Create mine: \n";
    std::cout << "Create mine_2 the same as mine: \n";
    std::cout << "Create mine_3 different from mine: \n";
    std::cout << GREEN"*************operator==*************\n"RESET;
    ft::queue<char> mine_2;
    ft::queue<char> mine_3;
    
    mine_3.push('a');
    mine_3.push('b');
    mine_3.push('r');

    mine_2.push('a');
    mine_2.push('b');
    mine_2.push('c');
    mine_2.push('d');

    mine.push('a');
    mine.push('b');
    mine.push('c');
    mine.push('d');

    std::cout << "Mine 2 and mine are ";
    if (mine == mine_2)
        std::cout << "equal!\n";
    else
        std::cout << "not equal!\n";
    
    std::cout << GREEN"*************operator!=*************\n"RESET;

    std::cout << "Mine 3 and mine are ";
    if (mine != mine_3)
        std::cout << "not equal!\n";
    else
        std::cout << "equal!\n";
    
    std::cout << GREEN"*************operator<**************\n"RESET;
    if (mine < mine_3)
        std::cout << "Mine is less than mine_3!\n";
    else
        std::cout << "Mine 3 is less than mine!\n";

    std::cout << GREEN"*************operator>**************\n"RESET;
    if (mine > mine_3)
        std::cout << "Mine is greater than mine_3!\n";
    else
        std::cout << "Mine 3 is greater than mine!\n";
    
    std::cout << GREEN"*************operator<=*************\n"RESET;
    if (mine <= mine_2)
        std::cout << "Mine is less or equal than mine_2!\n";
    else
        std::cout << "Mine 3 is greater than mine!\n";
    
    std::cout << GREEN"*************operator>=*************\n"RESET;
    if (mine >= mine_2)
        std::cout << "Mine is greater or equal than mine_2!\n";
    else
        std::cout << "Mine 2 is less than mine!\n";
    
}
