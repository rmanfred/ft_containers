#include "../Sources.hpp"

void test_int_v()
{
    std::cout << "Test-int for vector\n";

    std::vector<int> original(7, 0);
    ft::vector<int> mine(7, 0);

    std::cout << GREEN"**********Initialization************\n"RESET;

    std::cout << "initialization of original: \n";
    for (std::vector<int>::iterator or1 = original.begin(); or1 != original.end(); or1++)
        std::cout << "original: " << *or1 << "\n";
    std::cout << "size of original: " << original.size() << "\n";
    std::cout << "capacity of original: " << original.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "initialization of mine: \n";
    for (ft::vector<int>::iterator mn1 = mine.begin(); mn1 != mine.end(); mn1++)
        std::cout << "mine: " << *mn1 << "\n";
    std::cout << "size of mine: " << mine.size() << "\n";
    std::cout << "capacity of mine: " << mine.capacity() << "\n";

    std::cout << GREEN"**********Empty constructor**********\n"RESET;
    std::vector<int> orig_empty;
    ft::vector<int> mine_empty;

    std::cout << "size of original empty: " << orig_empty.size() << "\n";
    std::cout << "capacity of original empty: " << orig_empty.capacity() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "size of mine empty: " << mine_empty.size() << "\n";
    std::cout << "capacity of mine empty: " << mine_empty.capacity() << "\n";

    std::cout << GREEN"**********Copy constructor***********\n"RESET;
    std::vector<int> orig_copy(original);
    ft::vector<int> mine_copy(mine);

    std::cout << "copy of original: \n";
    for (std::vector<int>::iterator or2 = orig_copy.begin(); or2 != orig_copy.end(); or2++)
        std::cout << "original: " << *or2 << "\n";
    std::cout << "size of original: " << orig_copy.size() << "\n";
    std::cout << "capacity of original: " << orig_copy.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "copy of mine: \n";
    for (ft::vector<int>::iterator mn2 = mine_copy.begin(); mn2 != mine_copy.end(); mn2++)
        std::cout << "mine: " << *mn2 << "\n";
    std::cout << "size of mine: " << mine_copy.size() << "\n";
    std::cout << "capacity of mine: " << mine_copy.capacity() << "\n";

    std::cout << GREEN"*************Assignation*************\n"RESET;
    std::vector<int> to_use(7, 1);

    std::vector<int> orig_assign(to_use.begin(), to_use.end());
    std::cout << "Assignation of original: \n";
    for (std::vector<int>::iterator or3 = orig_assign.begin(); or3 != orig_assign.end(); or3++)
        std::cout << "original: " << *or3 << "\n";
    std::cout << "size of original: " << orig_assign.size() << "\n";
    std::cout << "capacity of original: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    ft::vector<int> to_use_mine(7, 1);
    ft::vector<int> mine_assign(to_use_mine.begin(), to_use_mine.end());
    for (ft::vector<int>::iterator mn3 = mine_assign.begin(); mn3 != mine_assign.end(); mn3++)
        std::cout << "mine: " << *mn3 << "\n";
    std::cout << "size of mine: " << mine_assign.size() << "\n";
    std::cout << "capacity of mine: " << mine_assign.capacity() << "\n";


    std::cout << GREEN"********Assignation operator=********\n"RESET;
    orig_empty = orig_assign;
    std::cout << "Assign empty to orig_assign vector:\n";
    for (std::vector<int>::iterator or4 = orig_empty.begin(); or4 != orig_empty.end(); or4++)
        std::cout << "original: " << *or4 << "\n";
    std::cout << "size of original: " << orig_empty.size() << "\n";
    std::cout << "capacity of original: " << orig_empty.capacity() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;
    mine_empty = mine_assign;
    for (ft::vector<int>::iterator mn4 = mine_empty.begin(); mn4 != mine_empty.end(); mn4++)
        std::cout << "mine: " << *mn4 << "\n";
    std::cout << "size of mine: " << mine_empty.size() << "\n";
    std::cout << "capacity of mine: " << mine_empty.capacity() << "\n";

    std::cout << GREEN"*************Max_size****************\n"RESET;
    std::cout << "Max size of original: " << original.max_size() << "\n";
    std::cout << GREEN"*************************************\n"RESET;
    std::cout << "Max size of mine: " << mine.max_size() << "\n";

    std::cout << GREEN"***************Resize****************\n"RESET;
    std::cout << "capacity of original: " << original.capacity() << "\n";
    std::cout << "Resize original to 23: \n";
    original.resize(23);
    for (std::vector<int>::iterator or5 = original.begin(); or5 != original.end(); or5++)
        std::cout << "original: " << *or5 << "\n";
    std::cout << "size of original: " << original.size() << "\n";
    std::cout << "capacity of original: " << original.capacity() << "\n";

    original.resize(43);
    std::cout << "capacity of original: " << original.capacity() << "\n";

    original.resize(157);
    std::cout << "capacity of original: " << original.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "capacity of mine: " << mine.capacity() << "\n";
    std::cout << "Resize mine to 23: \n";
    mine.resize(23);
    for (ft::vector<int>::iterator mn5 = mine.begin(); mn5 != mine.end(); mn5++)
        std::cout << "mine: " << *mn5 << "\n";
    std::cout << "size of mine: " << mine.size() << "\n";
    std::cout << "capacity of mine: " << mine.capacity() << "\n";

    mine.resize(43);
    std::cout << "capacity of mine: " << mine.capacity() << "\n";

    mine.resize(157);
    std::cout << "capacity of mine: " << mine.capacity() << "\n";

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
    
    std::cout << GREEN"***************Reserve****************\n"RESET;
    std::cout << "Current capacity for orig_assign: " << orig_assign.capacity() << "\n";
    std::cout << "Reserve 123:\n";
    orig_assign.reserve(123);
    std::cout << "capacity of orig_assign: " << orig_assign.capacity() << "\n";
    std::cout << "size of orig_assign: " << orig_assign.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Current capacity for mine_assign: " << mine_assign.capacity() << "\n";
    std::cout << "Reserve 123:\n";
    mine_assign.reserve(123);
    std::cout << "capacity of mine_assign: " << mine_assign.capacity() << "\n";
    std::cout << "size of mine_assign: " << mine_assign.size() << "\n";

    std::cout << GREEN"************operator[]***************\n"RESET;

    std::cout << "Original assign: \n";
    for (size_t i = 0; i < orig_assign.size(); i++)
        std::cout << orig_assign[i] << "| ";
    std::cout << std::endl;

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Mine assing: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign[j] << "| ";
    std::cout << std::endl;

    std::cout << GREEN"*****************at******************\n"RESET;
    
    std::cout << "Original assign: \n";
    for (size_t i = 0; i < orig_assign.size(); i++)
        std::cout << orig_assign.at(i) << "| ";
    std::cout << std::endl;
    try{
        std::cout << orig_assign.at(orig_assign.size()) << "\n";
    }
    catch (std::exception &exception)
    {
        std::cout << "exception catched!\n";
    }

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Mine assing: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    try{
        std::cout << mine_assign.at(mine_assign.size()) << "\n";
    }
    catch (std::exception &exception)
    {
        std::cout << "exception catched!\n";
    }

    std::cout << GREEN"****************front****************\n"RESET;
    std::cout << "Front of original: " << original.front() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Front of mine: " << mine.front() << "\n";

    std::cout << GREEN"****************back*****************\n"RESET;
    std::cout << "Push back 'c' to orig_assign:  ";
    orig_assign.push_back(3);
    std::cout << "Front of original: " << orig_assign.back() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Push back 'c' to mine_assign:  ";
    mine_assign.push_back(3);
    std::cout << "Front of mine: " << mine_assign.back() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"**************Push_back**************\n"RESET;
    std::cout << "Initial orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;

    std::cout << "Push back form 65 to 69:\n";
    for (size_t j = 65; j < 69; j++)
        orig_assign.push_back(j);
    std::cout << "New orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;
    
    std::cout << "Initial mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    
    std::cout << "Push back form 65 to 69:\n";
    for (size_t j = 65; j < 69; j++)
        mine_assign.push_back(j);
    std::cout << "New mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"**************Pop_back***************\n"RESET;
    std::cout << "Original pop back all pushed_back data: \n";
    for (size_t j = 0; j < 4; j++)
        orig_assign.pop_back();
    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Mine pop back all pushed_back data: \n";
    for (size_t j = 0; j < 4; j++)
        mine_assign.pop_back();
    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"***************Insert*****************\n"RESET;
    std::cout << "Insert one 4 to original at pos 2: \n";
    std::vector<int>::iterator it = orig_assign.begin();
    it++;
    orig_assign.insert(it, 4);
    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Insert one 4 to mine at pos 2: \n";
    ft::vector<int>::iterator it_m = mine_assign.begin();
    it_m++;
    mine_assign.insert(it_m, 4);
    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "original capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"**************Insert_2****************\n"RESET;
    std::cout << "Insert 16 '5' to original at pos 3: \n";
    std::vector<int>::iterator it_2 = orig_assign.begin();
    it_2++;
    it_2++;
    orig_assign.insert(it_2, 20, 5);
    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Insert  16 '5' to mine at pos 3: \n";
    ft::vector<int>::iterator it_m_2 = mine_assign.begin();
    it_m_2++;
    it_m_2++;
    mine_assign.insert(it_m_2, 20, 5);
    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"****************Insert_3**************\n"RESET;
    std::cout << "Check insert one more time:\n";

    std::vector<int> fl_orign(9, 3);
    ft::vector<int> fl_mine(9, 3);
    fl_orign.push_back(4);
    fl_orign.push_back(5);
    fl_orign.push_back(2);
    fl_orign.push_back(14);

    std::cout << "Original vector: \n";
    for (size_t j = 0; j < fl_orign.size(); j++)
        std::cout << fl_orign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << fl_orign.size() << "\n";
    std::cout << "original capacity: " << fl_orign.capacity() << "\n";

    fl_mine.push_back(4);
    fl_mine.push_back(5);
    fl_mine.push_back(2);
    fl_mine.push_back(14);
    std::cout << "Mine vector: \n";
    for (size_t j = 0; j < fl_mine.size(); j++)
        std::cout << fl_mine.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << fl_mine.size() << "\n";
    std::cout << "mine capacity: " << fl_mine.capacity() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "Inserting.....\n";
    std::vector<int>::iterator fl_it = fl_orign.begin();
    ft::vector<int>::iterator fl_it_mine = fl_mine.begin();
    std::vector<int>::iterator fl_ite = fl_orign.end();
    ft::vector<int>::iterator fl_ite_mine = fl_mine.end();
    
    fl_it++;
    fl_it++;
    fl_it++;
    fl_ite--;
    fl_ite--;

    fl_orign.insert(fl_orign.begin(), fl_it, fl_ite);
    std::cout << "Original vector: \n";
    for (size_t j = 0; j < fl_orign.size(); j++)
        std::cout << fl_orign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << fl_orign.size() << "\n";
    std::cout << "original capacity: " << fl_orign.capacity() << "\n";

    fl_it_mine++;
    fl_it_mine++;
    fl_it_mine++;
    fl_ite_mine--;
    fl_ite_mine--;

    fl_mine.insert(fl_mine.begin(), fl_it_mine, fl_ite_mine);
    std::cout << "Mine vector: \n";
    for (size_t j = 0; j < fl_mine.size(); j++)
        std::cout << fl_mine.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << fl_mine.size() << "\n";
    std::cout << "mine capacity: " << fl_mine.capacity() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;

    fl_orign.insert(fl_orign.begin(), 16, 6);
    std::cout << "Original vector: \n";
    for (size_t j = 0; j < fl_orign.size(); j++)
        std::cout << fl_orign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << fl_orign.size() << "\n";
    std::cout << "original capacity: " << fl_orign.capacity() << "\n";

    fl_mine.insert(fl_mine.begin(), 16, 6);
    std::cout << "Mine vector: \n";
    for (size_t j = 0; j < fl_mine.size(); j++)
        std::cout << fl_mine.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << fl_mine.size() << "\n";
    std::cout << "mine capacity: " << fl_mine.capacity() << "\n";

    std::cout << GREEN"****************Erase*****************\n"RESET;
    std::cout << "Erase from original_assign the last element: \n";
    std::vector<int>::iterator er = orig_assign.end();
    er--;
    orig_assign.erase(er);
    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Erase form mine_assign the last element: \n";
    ft::vector<int>::iterator er_m = mine_assign.end();
    er_m--;
    mine_assign.erase(er_m);
    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"***************Erase_2****************\n"RESET;
    std::cout << "Erase from original_assign from 3 pos to pre-last: \n";
    std::vector<int>::iterator er_2 = orig_assign.begin();
    std::vector<int>::iterator ere_2 = orig_assign.end();
    er_2++;
    er_2++;
    ere_2--;
    ere_2--;
    orig_assign.erase(er_2, ere_2);
    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Erase form mine_assign from 3 pos to pre-last: \n";
    ft::vector<int>::iterator er_m_2 = mine_assign.begin();
    ft::vector<int>::iterator ere_m_2 = mine_assign.end();
    er_m_2++;
    er_m_2++;
    ere_m_2--;
    ere_m_2--;
    mine_assign.erase(er_m_2, ere_m_2);
    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"*****************Swap*****************\n"RESET;
    std::cout << "Swap original with new vector: \n";
    std::vector<int> new_or(5, 6);
    new_or.push_back(7);
    new_or.push_back(8);
    new_or.push_back(9);
    std::cout << "New vector:\n";
    for (size_t j = 0; j < new_or.size(); j++)
        std::cout << new_or.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << new_or.size() << "\n";
    std::cout << "original capacity: " << new_or.capacity() << "\n";

    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";
    
    std::cout << PURPLE"*************************************\n"RESET;

    orig_assign.swap(new_or);
    std::cout << "After swap:\n";
    std::cout << "New vector:\n";
    for (size_t j = 0; j < new_or.size(); j++)
        std::cout << new_or.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << new_or.size() << "\n";
    std::cout << "original capacity: " << new_or.capacity() << "\n";

    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Swap mine with new vector: \n";
    ft::vector<int> new_mine(5, 6);
    new_mine.push_back(7);
    new_mine.push_back(8);
    new_mine.push_back(9);
    std::cout << "New mine vector:\n";
    for (size_t j = 0; j < new_mine.size(); j++)
        std::cout << new_mine.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << new_mine.size() << "\n";
    std::cout << "original capacity: " << new_mine.capacity() << "\n";

    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;
    mine_assign.swap(new_mine);

    std::cout << "After swap:\n";
    std::cout << "New vector:\n";
    for (size_t j = 0; j < new_mine.size(); j++)
        std::cout << new_mine.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << new_mine.size() << "\n";
    std::cout << "original capacity: " << new_mine.capacity() << "\n";

    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"*****************Swap*****************\n"RESET;
    std::cout << "Clear original vector: \n";
    orig_assign.clear();
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Clear mine vector: \n";
    mine_assign.clear();
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << PURPLE"************************************\n"RESET;
    std::cout << PURPLE"********Not member functions********\n"RESET;
    std::cout << PURPLE"************************************\n"RESET;

    std::cout << GREEN"*************operator==*************\n"RESET;
    if (mine == mine_assign)
        std::cout << "equal mines vectors!\n";
    else
        std::cout << "not equal vectors!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator!=*************\n"RESET;
    if (mine != mine_assign)
        std::cout << "not equal mines vectors!\n";
    else
        std::cout << "equal vectors!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator<**************\n"RESET;
    if (mine < mine_assign)
        std::cout << "mine assign is greater!\n";
    else
        std::cout << "mine assign is less!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator>**************\n"RESET;
    if (mine > mine_assign)
        std::cout << "mine is greater!\n";
    else
        std::cout << "mine is less!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator<**************\n"RESET;
    if (mine <= mine_assign)
        std::cout << "mine assign is greater or equal!\n";
    else
        std::cout << "mine assign is less!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator>=*************\n"RESET;
    if (mine >= mine_assign)
        std::cout << "mine is equal or greater!\n";
    else
        std::cout << "mine is less!\n";
    std::cout << std::endl;

    std::cout << GREEN"***********Reverse-Iterator*********\n"RESET;
    std::vector<int> butter(3, 12);
    butter.push_back(78);
    butter.push_back(45);
    butter.push_back(4);
    butter.push_back(2);

    for (std::vector<int>::reverse_iterator butt = butter.rbegin(); butt != butter.rend(); butt++)
        std::cout << "print reverse original: " << *butt << "\n";
    
    ft::vector<int> m_butter(3, 12);
    m_butter.push_back(78);
    m_butter.push_back(45);
    m_butter.push_back(4);
    m_butter.push_back(2);

    for (ft::vector<int>::reverse_iterator m_butt = m_butter.rbegin(); m_butt != m_butter.rend(); m_butt++)
        std::cout << "print reverse mine: " << *m_butt << "\n";

    std::cout << GREEN"*********Const_Rev_Iterator*********\n"RESET;
    std::vector<int> butter_2(3, 12);
    butter_2.push_back(78);
    butter_2.push_back(45);
    butter_2.push_back(4);
    butter_2.push_back(2);

    for (std::vector<int>::const_reverse_iterator butt_2 = butter_2.rbegin(); butt_2 != butter_2.rend(); butt_2++)
        std::cout << "print const reverse original: " << *butt_2 << "\n";
    
    ft::vector<int> m_butter_2(3, 12);
    m_butter_2.push_back(78);
    m_butter_2.push_back(45);
    m_butter_2.push_back(4);
    m_butter_2.push_back(2);

    for (ft::vector<int>::const_reverse_iterator m_butt_2 = m_butter_2.rbegin(); m_butt_2 != m_butter_2.rend(); m_butt_2++)
        std::cout << "print reverse mine: " << *m_butt_2 << "\n";

}