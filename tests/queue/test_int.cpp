#include "../Sources.hpp"

void test_int_q()
{
    std::cout << "Test-int for queue\n";

    std::queue<int> original;
    ft::queue<int> mine;

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

    std::cout << GREEN"***********Push-Pop-Front**************\n"RESET;
    std::cout << "Pushing into orig... 65, 56, 78, 123456: \n";
    
    original.push(65);
    original.push(56);
    original.push(78);
    original.push(123456);

    std::cout << "Original  size: " << original.size() << "!\n";

    std::cout << "Popping...\n";
    while (!original.empty())
    {
        std::cout << ' ' << original.front();
        original.pop();
    }
    std::cout << std::endl;

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Pushing into mine... 65, 56, 78, 123456: \n";

    mine.push(65);
    mine.push(56);
    mine.push(78);
    mine.push(123456);

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

    std::cout << GREEN"****************Size****************\n"RESET;
    std::cout << "Original  size: " << original.size() << "!\n";
    std::cout << "Mine      size: " << mine.size() << "!\n";

    std::cout << PURPLE"************************************\n"RESET;
    std::cout << PURPLE"********Not member functions********\n"RESET;
    std::cout << PURPLE"************************************\n"RESET;
    std::cout << "Create mine: \n";
    std::cout << "Create mine_2 the same as mine: \n";
    std::cout << "Create mine_3 different from mine: \n";
    std::cout << GREEN"*************operator==*************\n"RESET;
    ft::queue<int> mine_2;
    ft::queue<int> mine_3;
    
    mine_3.push(65);
    mine_3.push(34);
    mine_3.push(45);

    mine_2.push(65);
    mine_2.push(34);
    mine_2.push(45);
    mine_2.push(78);

    mine.push(65);
    mine.push(34);
    mine.push(45);
    mine.push(78);

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
