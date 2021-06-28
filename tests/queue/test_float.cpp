#include "../Sources.hpp"

void test_float_q()
{
    std::cout << "Test-float for queue\n";

    std::queue<float> original;
    ft::queue<float> mine;

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
    std::cout << "Pushing into orig...65.89, 56.08, 78.345, 123456.1234: \n";
    
    original.push(65.89);
    original.push(56.08);
    original.push(78.345);
    original.push(123456.1234);

    std::cout << "Original  size: " << original.size() << "!\n";

    std::cout << "Popping...\n";
    while (!original.empty())
    {
        std::cout << ' ' << original.front();
        original.pop();
    }
    std::cout << std::endl;

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Pushing into mine...65.89, 56.08, 78.345, 123456.1234: \n";

    mine.push(65.89);
    mine.push(56.08);
    mine.push(78.345);
    mine.push(123456.1234);

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
    
    float j = 65;
    original.push(j);

    std::cout << "Original  size: " << original.size() << "!\n";

    std::cout << "Popping...\n";
    while (!original.empty() && j <= 70)
    {
        j += 0.96;
        original.push(j);
        std::cout << ' ' << original.back();
        original.pop();
    }
    std::cout << std::endl;

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Pushing into mine...A, B, C: \n";

    float i = 65;
    mine.push(i);
    std::cout << "Mine      size: " << mine.size() << "!\n";

    std::cout << "Popping...\n";
    while (!mine.empty() && i <= 70)
    {
        i += 0.96;
        mine.push(i);
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
    ft::queue<float> mine_2;
    ft::queue<float> mine_3;
    
    mine_3.push(65.003);
    mine_3.push(34.56);
    mine_3.push(45.1234);

    mine_2.push(65.003);
    mine_2.push(34.56);
    mine_2.push(45.1234);
    mine_2.push(78.678);

    mine.push(65.003);
    mine.push(34.56);
    mine.push(45.1234);
    mine.push(78.678);

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
