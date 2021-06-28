#include "../Sources.hpp"

void test_string_v()
{
    std::cout << "Test-string for vector\n";

    std::vector<std::string> original(7, "initial");
    ft::vector<std::string> mine(7, "initial");

    std::cout << GREEN"**********Initialization************\n"RESET;

    std::cout << "initialization of original: \n";
    for (std::vector<std::string>::iterator or1 = original.begin(); or1 != original.end(); or1++)
        std::cout << "original: " << *or1 << "\n";
    std::cout << "size of original: " << original.size() << "\n";
    std::cout << "capacity of original: " << original.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "initialization of mine: \n";
    for (ft::vector<std::string>::iterator mn1 = mine.begin(); mn1 != mine.end(); mn1++)
        std::cout << "mine: " << *mn1 << "\n";
    std::cout << "size of mine: " << mine.size() << "\n";
    std::cout << "capacity of mine: " << mine.capacity() << "\n";

    std::cout << GREEN"**********Empty constructor**********\n"RESET;
    std::vector<std::string> orig_empty;
    ft::vector<std::string> mine_empty;

    std::cout << "size of original empty: " << orig_empty.size() << "\n";
    std::cout << "capacity of original empty: " << orig_empty.capacity() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "size of mine empty: " << mine_empty.size() << "\n";
    std::cout << "capacity of mine empty: " << mine_empty.capacity() << "\n";

    std::cout << GREEN"**********Copy constructor***********\n"RESET;
    std::vector<std::string> orig_copy(original);
    ft::vector<std::string> mine_copy(mine);

    std::cout << "copy of original: \n";
    for (std::vector<std::string>::iterator or2 = orig_copy.begin(); or2 != orig_copy.end(); or2++)
        std::cout << "original: " << *or2 << "\n";
    std::cout << "size of original: " << orig_copy.size() << "\n";
    std::cout << "capacity of original: " << orig_copy.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "copy of mine: \n";
    for (ft::vector<std::string>::iterator mn2 = mine_copy.begin(); mn2 != mine_copy.end(); mn2++)
        std::cout << "mine: " << *mn2 << "\n";
    std::cout << "size of mine: " << mine_copy.size() << "\n";
    std::cout << "capacity of mine: " << mine_copy.capacity() << "\n";

    std::cout << GREEN"*************Assignation*************\n"RESET;
    std::vector<std::string> to_use(7, "second");

    std::vector<std::string> orig_assign(to_use.begin(), to_use.end());
    std::cout << "Assignation of original: \n";
    for (std::vector<std::string>::iterator or3 = orig_assign.begin(); or3 != orig_assign.end(); or3++)
        std::cout << "original: " << *or3 << "\n";
    std::cout << "size of original: " << orig_assign.size() << "\n";
    std::cout << "capacity of original: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    ft::vector<std::string> to_use_mine(7, "second");
    ft::vector<std::string> mine_assign(to_use_mine.begin(), to_use_mine.end());
    for (ft::vector<std::string>::iterator mn3 = mine_assign.begin(); mn3 != mine_assign.end(); mn3++)
        std::cout << "mine: " << *mn3 << "\n";
    std::cout << "size of mine: " << mine_assign.size() << "\n";
    std::cout << "capacity of mine: " << mine_assign.capacity() << "\n";


    std::cout << GREEN"********Assignation operator=********\n"RESET;
    orig_empty = orig_assign;
    std::cout << "Assign empty to orig_assign vector:\n";
    for (std::vector<std::string>::iterator or4 = orig_empty.begin(); or4 != orig_empty.end(); or4++)
        std::cout << "original: " << *or4 << "\n";
    std::cout << "size of original: " << orig_empty.size() << "\n";
    std::cout << "capacity of original: " << orig_empty.capacity() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;
    mine_empty = mine_assign;
    for (ft::vector<std::string>::iterator mn4 = mine_empty.begin(); mn4 != mine_empty.end(); mn4++)
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
    for (std::vector<std::string>::iterator or5 = original.begin(); or5 != original.end(); or5++)
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
    for (ft::vector<std::string>::iterator mn5 = mine.begin(); mn5 != mine.end(); mn5++)
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
    std::cout << "Push back 'push_back' to orig_assign:  ";
    orig_assign.push_back("push_back");
    std::cout << "Front of original: " << orig_assign.back() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Push back 'push_back' to mine_assign:  ";
    mine_assign.push_back("push_back");
    std::cout << "Front of mine: " << mine_assign.back() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"**************Push_back**************\n"RESET;
    std::cout << "Initial orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;

    std::cout << "Push back form A to D:\n";
    for (size_t j = 65; j < 69; j++)
        orig_assign.push_back("push_loop");
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
    
    std::cout << "Push back form A to D:\n";
    for (size_t j = 65; j < 69; j++)
        mine_assign.push_back("push_loop");
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
    std::cout << "Insert one 'insert' to original at pos 2: \n";
    std::vector<std::string>::iterator it = orig_assign.begin();
    it++;
    orig_assign.insert(it, "swap_4");
    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Insert one 'swap_4' to mine at pos 2: \n";
    ft::vector<std::string>::iterator it_m = mine_assign.begin();
    it_m++;
    mine_assign.insert(it_m, "swap_4");
    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "original capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"**************Insert_2****************\n"RESET;
    std::cout << "Insert 20 'insert_2' to original at pos 3: \n";
    std::vector<std::string>::iterator it_2 = orig_assign.begin();
    it_2++;
    it_2++;
    orig_assign.insert(it_2, 20, "insert_2");
    std::cout << "Current orig_assign vector: \n";
    for (size_t j = 0; j < orig_assign.size(); j++)
        std::cout << orig_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << orig_assign.size() << "\n";
    std::cout << "original capacity: " << orig_assign.capacity() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Insert 20 'insert_2' to mine at pos 3: \n";
    ft::vector<std::string>::iterator it_m_2 = mine_assign.begin();
    it_m_2++;
    it_m_2++;
    mine_assign.insert(it_m_2, 20, "insert_2");
    std::cout << "Current mine_assign vector: \n";
    for (size_t j = 0; j < mine_assign.size(); j++)
        std::cout << mine_assign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << mine_assign.size() << "\n";
    std::cout << "mine capacity: " << mine_assign.capacity() << "\n";

    std::cout << GREEN"****************Insert_3**************\n"RESET;
    std::cout << "Check insert one more time:\n";

    std::vector<std::string> fl_orign(9, "three");
    ft::vector<std::string> fl_mine(9, "three");
    fl_orign.push_back("four");
    fl_orign.push_back("five");
    fl_orign.push_back("six");
    fl_orign.push_back("seven");

    std::cout << "Original vector: \n";
    for (size_t j = 0; j < fl_orign.size(); j++)
        std::cout << fl_orign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << fl_orign.size() << "\n";
    std::cout << "original capacity: " << fl_orign.capacity() << "\n";

    fl_mine.push_back("four");
    fl_mine.push_back("five");
    fl_mine.push_back("six");
    fl_mine.push_back("seven");
    std::cout << "Mine vector: \n";
    for (size_t j = 0; j < fl_mine.size(); j++)
        std::cout << fl_mine.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << fl_mine.size() << "\n";
    std::cout << "mine capacity: " << fl_mine.capacity() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "Inserting.....\n";
    std::vector<std::string>::iterator fl_it = fl_orign.begin();
    ft::vector<std::string>::iterator fl_it_mine = fl_mine.begin();
    std::vector<std::string>::iterator fl_ite = fl_orign.end();
    ft::vector<std::string>::iterator fl_ite_mine = fl_mine.end();
    
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

    fl_orign.insert(fl_orign.begin(), 16, "sixty");
    std::cout << "Original vector: \n";
    for (size_t j = 0; j < fl_orign.size(); j++)
        std::cout << fl_orign.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "original size: " << fl_orign.size() << "\n";
    std::cout << "original capacity: " << fl_orign.capacity() << "\n";

    fl_mine.insert(fl_mine.begin(), 16, "sixty");
    std::cout << "Mine vector: \n";
    for (size_t j = 0; j < fl_mine.size(); j++)
        std::cout << fl_mine.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "mine size: " << fl_mine.size() << "\n";
    std::cout << "mine capacity: " << fl_mine.capacity() << "\n";

    std::cout << GREEN"****************Erase*****************\n"RESET;
    std::cout << "Erase from original_assign the last element: \n";
    std::vector<std::string>::iterator er = orig_assign.end();
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
    ft::vector<std::string>::iterator er_m = mine_assign.end();
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
    std::vector<std::string>::iterator er_2 = orig_assign.begin();
    std::vector<std::string>::iterator ere_2 = orig_assign.end();
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
    ft::vector<std::string>::iterator er_m_2 = mine_assign.begin();
    ft::vector<std::string>::iterator ere_m_2 = mine_assign.end();
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
    std::vector<std::string> new_or(5, "swap_1");
    new_or.push_back("swap_2");
    new_or.push_back("swap_3");
    new_or.push_back("swap_4");
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
    ft::vector<std::string> new_mine(5, "swap_1");
    new_mine.push_back("swap_2");
    new_mine.push_back("swap_3");
    new_mine.push_back("swap_4");
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

    std::vector<std::string> str1(1, "Test");
    ft::vector<std::string> str2(1, "Test");

    str1.push_back("test2");
    str1.push_back("test3");
    str1.push_back("test4");
    str1.push_back("test5");
    str1.push_back("test6");
    std::cout << "Capacity of oiginal: " << str1.capacity() << "\n";

    str2.push_back("test2");
    str2.push_back("test3");
    str2.push_back("test4");
    str2.push_back("test5");
    str2.push_back("test6");
    std::cout << "Capacity of mine: " << str2.capacity() << "\n";

    std::vector<std::string>::iterator ret = str1.begin();
    std::vector<std::string>::iterator rete = str1.end();

    std::cout << "Original: \n";
    for (size_t j = 0; j < str1.size(); j++)
        std::cout << str1.at(j) << "| ";
    std::cout << std::endl;
    
    std::cout << "Mine:\n";
    for (size_t j = 0; j < str2.size(); j++)
        std::cout << str2.at(j) << "| ";
    std::cout << std::endl;

    // ret++;
    // ret++;
    // rete--;
    std::cout << "Insert at pos 3 form 1 to three!\n";
    str1.insert(ret, str1.begin(), rete);
    
    std::cout << "Original after: \n";
    for (size_t j = 0; j < str1.size(); j++)
        std::cout << str1.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "Size of oiginal: " << str1.size() << "\n";
    std::cout << "Capacity of oiginal: " << str1.capacity() << "\n";
    
    ft::vector<std::string>::iterator ret_m = str2.begin();
    ft::vector<std::string>::iterator rete_m = str2.end();
    
    // ret_m++;
    // ret_m++;
    // rete_m--;
    std::cout << "Insert at pos 3 form 1 to three!\n";
    str2.insert(ret_m, str2.begin(), rete_m);
    
    std::cout << "Mine after: \n";
    for (size_t j = 0; j < str2.size(); j++)
        std::cout << str2.at(j) << "| ";
    std::cout << std::endl;
    std::cout << "Size of mine: " << str2.size() << "\n";
    std::cout << "Capacity of mine: " << str2.capacity() << "\n";


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
    std::vector<std::string> butter(3, "what");
    butter.push_back("poor");
    butter.push_back("idgf");
    butter.push_back("west");
    butter.push_back("look");

    for (std::vector<std::string>::reverse_iterator butt = butter.rbegin(); butt != butter.rend(); butt++)
        std::cout << "print reverse original: " << *butt << "\n";
    
    ft::vector<std::string> m_butter(3, "what");
    m_butter.push_back("poor");
    m_butter.push_back("idgf");
    m_butter.push_back("west");
    m_butter.push_back("look");

    for (ft::vector<std::string>::reverse_iterator m_butt = m_butter.rbegin(); m_butt != m_butter.rend(); m_butt++)
        std::cout << "print reverse mine: " << *m_butt << "\n";

    std::cout << GREEN"*********Const_Rev_Iterator*********\n"RESET;
    std::vector<std::string> butter_2(3, "what");
    butter_2.push_back("poor");
    butter_2.push_back("idgf");
    butter_2.push_back("west");
    butter_2.push_back("look");

    for (std::vector<std::string>::const_reverse_iterator butt_2 = butter_2.rbegin(); butt_2 != butter_2.rend(); butt_2++)
        std::cout << "print const reverse original: " << *butt_2 << "\n";
    
    ft::vector<std::string> m_butter_2(3, "what");
    m_butter_2.push_back("poor");
    m_butter_2.push_back("idgf");
    m_butter_2.push_back("west");
    m_butter_2.push_back("look");

    for (ft::vector<std::string>::const_reverse_iterator m_butt_2 = m_butter_2.rbegin(); m_butt_2 != m_butter_2.rend(); m_butt_2++)
        std::cout << "print reverse mine: " << *m_butt_2 << "\n";

}