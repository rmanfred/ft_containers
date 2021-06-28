#include "../Sources.hpp"
#include "Test_list.hpp"

bool single_digit_s (const std::string& value) { return (value != "privet"); }
bool Compare_str (std::string first, std::string second) { return ( (first)<(second) ); }

void test_string()
{
    std::cout << "Tests for list_string starts: \n";

    ft::list<std::string> first(7, "adelina");
    std::list<std::string> first_orig(7, "adelina");
    ft::list<std::string> second(3, "tree");
    std::list<std::string> second_orig(3, "tree");

    std::cout << GREEN"**********Initialization************\n"RESET;
    
    std::cout << "Original: \n";
    std::cout << "initialized first: \n";
    for (std::list<std::string>::iterator frt_or = first_orig.begin(); frt_or != first_orig.end(); frt_or++)
        std::cout << "first: " << *frt_or << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";
    
    std::cout << "initialized second: \n";
    for (std::list<std::string>::iterator snd_or = second_orig.begin(); snd_or != second_orig.end(); snd_or++)
        std::cout << "second: " << *snd_or << "\n";
    std::cout << "size of second: " << second_orig.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "initialized first: \n";
    for (ft::list<std::string>::iterator frt = first.begin(); frt != first.end(); frt++)
        std::cout << "first: " << *frt << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << "Mine: \n";
    std::cout << "initialized second: \n";
    for (ft::list<std::string>::iterator snd = second.begin(); snd != second.end(); snd++)
        std::cout << "second: " << *snd << "\n";
    std::cout << "size of second: " << second.size() << "\n";
    
    std::cout << GREEN"**********Empty constructor**********\n"RESET;
    
    std::list<std::string> empty_list_orig;
    std::cout << "Create empty original list.\n";
    std::cout << "size of empty list: " << empty_list_orig.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    
    ft::list<std::string> empty_lst;
    std::cout << "Create empty list.\n";
    std::cout << "size of empty list: " << empty_lst.size() << "\n";

    std::cout << GREEN"**********Copy constructor***********\n"RESET;
    
    std::list<std::string> copy_lst_orig(second_orig);
    std::cout << "Create copy list of the second:\n";
    for (std::list<std::string>::iterator cpy_or = copy_lst_orig.begin(); cpy_or != copy_lst_orig.end(); cpy_or++)
        std::cout << "copy: " << *cpy_or << "\n";
    std::cout << "size of copy: " << copy_lst_orig.size() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;

    ft::list<std::string> copy_lst(second);
    std::cout << "Create copy list of the second:\n";
    for (ft::list<std::string>::iterator cpy = copy_lst.begin(); cpy != copy_lst.end(); cpy++)
        std::cout << "copy: " << *cpy << "\n";
    std::cout << "size of copy: " << copy_lst.size() << "\n";

    std::cout << GREEN"*************Assignation*************\n"RESET;
    std::list<std::string> third_orig(0, "token");
    third_orig.assign(first_orig.begin(), first_orig.end());
    std::cout << "Create third list with to the first:\n";
    for (std::list<std::string>::iterator trd_or = third_orig.begin(); trd_or != third_orig.end(); trd_or++)
        std::cout << "third: " << *trd_or << "\n";
    std::cout << "size of third: " << third_orig.size() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;
    
    ft::list<std::string> third(0, "token");
    third.assign(first.begin(), first.end());
    std::cout << "Create third list with to the first:\n";
    for (ft::list<std::string>::iterator trd = third.begin(); trd != third.end(); trd++)
        std::cout << "third: " << *trd << "\n";
    std::cout << "size of third: " << third.size() << "\n";

    std::cout << GREEN"**********Push_front(+3)*************\n"RESET;

    first_orig.push_front("'g'");
    first_orig.push_front("'d'");
    first_orig.push_front("'f'");
    std::cout << "New size and values: \n";
    for (std::list<std::string>::iterator f_or = first_orig.begin(); f_or != first_orig.end(); f_or++)
        std::cout << "first: " << *f_or << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    first.push_front("'g'");
    first.push_front("'d'");
    first.push_front("'f'");
    std::cout << "New size and values: \n";
    for (ft::list<std::string>::iterator f = first.begin(); f != first.end(); f++)
        std::cout << "first: " << *f << "\n";
    std::cout << "size of first: " << first.size() << "\n";


    std::cout << GREEN"**********Push_back(+3)**************\n"RESET;

    second_orig.push_back("privet");
    second_orig.push_back("privet2");
    second_orig.push_back("privet3");

    std::cout << "New size and values: \n";
    for (std::list<std::string>::iterator s_or = second_orig.begin(); s_or != second_orig.end(); s_or++)
        std::cout << "first: " << *s_or << "\n";
    std::cout << "size of second: " << second_orig.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    second.push_back("privet");
    second.push_back("privet2");
    second.push_back("privet3");

    std::cout << "New size and values: \n";
    for (ft::list<std::string>::iterator s = second.begin(); s != second.end(); s++)
        std::cout << "first: " << *s << "\n";
    std::cout << "size of second: " << second.size() << "\n";

    std::cout << GREEN"**********Pop_back(-3)***************\n"RESET;

    first_orig.pop_back();
    first_orig.pop_back();
    first_orig.pop_back();
    std::cout << "New size and values: \n";
    for (std::list<std::string>::iterator fi_or = first_orig.begin(); fi_or != first_orig.end(); fi_or++)
        std::cout << "first: " << *fi_or << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    first.pop_back();
    first.pop_back();
    first.pop_back();
    std::cout << "New size and values: \n";
    for (ft::list<std::string>::iterator fi = first.begin(); fi != first.end(); fi++)
        std::cout << "first: " << *fi << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << GREEN"**********Pop_front(-3)**************\n"RESET;

    second_orig.pop_front();
    second_orig.pop_front();
    second_orig.pop_front();
    std::cout << "New size and values: \n";
    for (std::list<std::string>::iterator si_or = second_orig.begin(); si_or != second_orig.end(); si_or++)
        std::cout << "second: " << *si_or << "\n";
    std::cout << "size of second: " << second_orig.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    second.pop_front();
    second.pop_front();
    second.pop_front();
    std::cout << "New size and values: \n";
    for (ft::list<std::string>::iterator si = second.begin(); si != second.end(); si++)
        std::cout << "second: " << *si << "\n";
    std::cout << "size of second: " << second.size() << "\n";

    std::cout << GREEN"*************Max_size****************\n"RESET;
    std::cout << "Original max size:\n";
    std::cout << second_orig.max_size() << "\n";
    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Mine max size:\n";
    std::cout << second.max_size() << "\n";

    std::cout << GREEN"***************Front*****************\n"RESET;

    std::cout << "first front: " << first_orig.front() << "\n";
    std::cout << "second front: " << second_orig.front() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "first front: " << first.front() << "\n";
    std::cout << "second front: " << second.front() << "\n";

    std::cout << GREEN"***************Back******************\n"RESET;
    std::cout << "first front: " << first_orig.back() << "\n";
    std::cout << "second front: " << second_orig.back() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "first front: " << first.back() << "\n";
    std::cout << "second front: " << second.back() << "\n";

    std::cout << GREEN"***************Empty*****************\n"RESET;
    
    if (first_orig.empty())
        std::cout << "first is empty!\n";
    else
        std::cout << "first is not empty!\n";
    std::cout << YELLOW"*************************************\n"RESET;
   
    if (second_orig.empty())
        std::cout << "second is empty!\n";
    else
        std::cout << "second is not empty!\n";
    std::cout << YELLOW"*************************************\n"RESET;
    
    if (empty_list_orig.empty())
        std::cout << "empty list is empty!\n";
    else
        std::cout << "empty list is not empty!\n";

    std::cout << YELLOW"*************************************\n"RESET;
    
    if (first.empty())
        std::cout << "first is empty!\n";
    else
        std::cout << "first is not empty!\n";
    std::cout << YELLOW"*************************************\n"RESET;
   
    if (second.empty())
        std::cout << "second is empty!\n";
    else
        std::cout << "second is not empty!\n";
    std::cout << YELLOW"*************************************\n"RESET;
    
    if (empty_lst.empty())
        std::cout << "empty list is empty!\n";
    else
        std::cout << "empty list is not empty!\n";

    std::cout << GREEN"***************Insert****************\n"RESET;
    std::cout << "Insert std::stringo first val of 4 at position 2: \n";
    std::list<std::string>::iterator insert_it_orig = first_orig.begin();
    insert_it_orig++;
    first_orig.insert(insert_it_orig, "';' word");
    for (std::list<std::string>::iterator t_or = first_orig.begin(); t_or != first_orig.end(); t_or++)
        std::cout << "first: " << *t_or << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";
    
    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "Insert std::stringo first val of 4 at position 2: \n";
    ft::list<std::string>::iterator insert_it = first.begin();
    insert_it++;
    first.insert(insert_it, "';' word");
    for (ft::list<std::string>::iterator t = first.begin(); t != first.end(); t++)
        std::cout << "first: " << *t << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Insert std::stringo second val of 7 at position 2 5 times: \n";
    std::list<std::string>::iterator insert_ite_orig = second_orig.begin();
    insert_ite_orig++;
    size_t n_or = 5;
    second_orig.insert(insert_ite_orig, n_or, "'pret'");
    for (std::list<std::string>::iterator i_orig = second_orig.begin(); i_orig != second_orig.end(); i_orig++)
        std::cout << "second: " << *i_orig << "\n";
    std::cout << "size of second: " << second_orig.size() << "\n";
    
    std::cout << PURPLE"*************************************\n"RESET;
    
    std::cout << "Insert std::stringo second val of 7 at position 2 5 times: \n";
    ft::list<std::string>::iterator insert_ite = second.begin();
    insert_ite++;
    size_t n = 5;
    second.insert(insert_ite, n, "'pret'");
    for (ft::list<std::string>::iterator i = second.begin(); i != second.end(); i++)
        std::cout << "second: " << *i << "\n";
    std::cout << "size of second: " << second.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Insert std::stringo first from pos 2 to 4: \n";
    std::list<std::string>::iterator ins_orig = first_orig.begin();
    std::list<std::string>::iterator ins_2_orig = first_orig.begin();
    ins_orig++;
    ins_2_orig++;
    ins_2_orig++;
    ins_2_orig++;
    first_orig.insert(ins_orig, ins_orig, ins_2_orig);
    for (std::list<std::string>::iterator to_orig = first_orig.begin(); to_orig != first_orig.end(); to_orig++)
        std::cout << "first: " << *to_orig << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";    
    
    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "Insert std::stringo first from pos 2 to 4: \n";
    ft::list<std::string>::iterator ins = first.begin();
    ft::list<std::string>::iterator ins_2 = first.begin();
    ins++;
    ins_2++;
    ins_2++;
    ins_2++;
    first.insert(ins, ins, ins_2);
    for (ft::list<std::string>::iterator to = first.begin(); to != first.end(); to++)
        std::cout << "first: " << *to << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << GREEN"***************Erase*****************\n"RESET;

    std::cout << "Erase 1 fiiled list: \n";
    std::list<std::string> one_orig(1, "trio");
    std::cout << "size of one: " << one_orig.size() << "\n";
    one_orig.erase(one_orig.begin());
    std::cout << "size of one: " << one_orig.size() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "Erase 1 fiiled list: \n";
    ft::list<std::string> one(1, "trio");
    std::cout << "size of one: " << one.size() << "\n";
    one.erase(one.begin());
    std::cout << "size of one: " << one.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Erase from first at pos 2: \n";
    std::list<std::string>::iterator er_orig = first_orig.begin();
    er_orig++;
    first_orig.erase(er_orig);
    for (std::list<std::string>::iterator top_orig = first_orig.begin(); top_orig != first_orig.end(); top_orig++)
        std::cout << "first: " << *top_orig << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;
    
    std::cout << "Erase from first at pos 2: \n";
    ft::list<std::string>::iterator er = first.begin();
    er++;
    first.erase(er);
    for (ft::list<std::string>::iterator top = first.begin(); top != first.end(); top++)
        std::cout << "first: " << *top << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Erase from first from pos 2 to 4: \n";
    std::list<std::string>::iterator ee_orig = first_orig.begin();
    std::list<std::string>::iterator et_orig = first_orig.begin();
    ee_orig++;
    et_orig++;
    et_orig++;
    et_orig++;
    first_orig.erase(ee_orig, et_orig);
    for (std::list<std::string>::iterator top2_orig = first_orig.begin(); top2_orig != first_orig.end(); top2_orig++)
        std::cout << "first: " << *top2_orig << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";
    
    std::cout << PURPLE"*************************************\n"RESET;
    
    std::cout << "Erase from first from pos 2 to 4: \n";
    ft::list<std::string>::iterator ee = first.begin();
    ft::list<std::string>::iterator et = first.begin();
    ee++;
    et++;
    et++;
    et++;
    first.erase(ee, et);
    for (ft::list<std::string>::iterator top2 = first.begin(); top2 != first.end(); top2++)
        std::cout << "first: " << *top2 << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << GREEN"****************Swap*****************\n"RESET;
    std::list<std::string> swap1_orig(6, "'1'");
    std::list<std::string> swap2_orig(4, "'2room'");
    std::cout << "Before: \n";
    for (std::list<std::string>::iterator sp_orig = swap1_orig.begin(); sp_orig != swap1_orig.end(); sp_orig++)
        std::cout << "swap_first: " << *sp_orig << "\n";
    for (std::list<std::string>::iterator sp_2_orig = swap2_orig.begin(); sp_2_orig != swap2_orig.end(); sp_2_orig++)
        std::cout << "swap_second: " << *sp_2_orig << "\n";
    swap1_orig.swap(swap2_orig);
    std::cout << "After: \n";
    for (std::list<std::string>::iterator w_orig = swap1_orig.begin(); w_orig != swap1_orig.end(); w_orig++)
        std::cout << "swap_first: " << *w_orig << "\n";
    for (std::list<std::string>::iterator w_2_orig = swap2_orig.begin(); w_2_orig != swap2_orig.end(); w_2_orig++)
        std::cout << "swap_second: " << *w_2_orig << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;
    
    ft::list<std::string> swap1(6, "'1'");
    ft::list<std::string> swap2(4, "'2room'");
    std::cout << "Before: \n";
    for (ft::list<std::string>::iterator sp = swap1.begin(); sp != swap1.end(); sp++)
        std::cout << "swap_first: " << *sp << "\n";
    for (ft::list<std::string>::iterator sp_2 = swap2.begin(); sp_2 != swap2.end(); sp_2++)
        std::cout << "swap_second: " << *sp_2 << "\n";
    swap1.swap(swap2);
    std::cout << "After: \n";
    for (ft::list<std::string>::iterator w = swap1.begin(); w != swap1.end(); w++)
        std::cout << "swap_first: " << *w << "\n";
    for (ft::list<std::string>::iterator w_2 = swap2.begin(); w_2 != swap2.end(); w_2++)
        std::cout << "swap_second: " << *w_2 << "\n";

    std::cout << GREEN"***************Resize****************\n"RESET;
    std::cout << "Resize second list: \n";
    std::cout << "Current size of second list: " << second_orig.size() << "\n";
    std::cout << "Change to 10 with val 8: \n";
    second_orig.resize(10, "'8'");
    for (std::list<std::string>::iterator sw_orig = second_orig.begin(); sw_orig != second_orig.end(); sw_orig++)
        std::cout << "second: " << *sw_orig << "\n";
    std::cout << "size of second: " << second_orig.size() << "\n";
    
    std::cout << PURPLE"*************************************\n"RESET;
    
    std::cout << "Resize second list: \n";
    std::cout << "Current size of second list: " << second.size() << "\n";
    std::cout << "Change to 10 with val 8: \n";
    second.resize(10, "'8'");
    for (ft::list<std::string>::iterator sw = second.begin(); sw != second.end(); sw++)
        std::cout << "second: " << *sw << "\n";
    std::cout << "size of second: " << second.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Resize second by erasing by 3 to size 6: \n";
    second_orig.resize(6);
    for (std::list<std::string>::iterator se_orig = second_orig.begin(); se_orig != second_orig.end(); se_orig++)
        std::cout << "second: " << *se_orig << "\n";
    std::cout << "size of second: " << second_orig.size() << "\n";
    
    std::cout << PURPLE"*************************************\n"RESET;
    
    std::cout << "Resize second by erasing by 3 to size 6: \n";
    second.resize(6);
    for (ft::list<std::string>::iterator se = second.begin(); se != second.end(); se++)
        std::cout << "second: " << *se << "\n";
    std::cout << "size of second: " << second.size() << "\n";

    std::cout << GREEN"***************Splice****************\n"RESET;
     std::cout << "Transfers all the elements of second to f list at position 2: \n";
    std::list<std::string> f_orig(3, "poor");
    std::list<std::string>::iterator scnd_orig = f_orig.begin();
    f_orig.push_back("69");
    f_orig.push_back("86");
    f_orig.push_back("'look'");
    f_orig.push_back("']'");
    f_orig.push_back("'so?'");
    scnd_orig++;
    f_orig.splice(scnd_orig, second_orig);
    for (std::list<std::string>::iterator spl_orig = f_orig.begin(); spl_orig != f_orig.end(); spl_orig++)
        std::cout << "f: " << *spl_orig << "\n";
    std::cout << "size of f: " << f_orig.size() << "\n";

    std::list<std::string> splice_lst_orig(1, "'f'");
    splice_lst_orig.push_back("'3'");
    splice_lst_orig.push_back("'s'");
    splice_lst_orig.push_back("'x'");
    splice_lst_orig.push_back("'w'");
    
    std::cout << PURPLE"*************************************\n"RESET;
    
    std::cout << "Transfers all the elements of second to f list at position 2: \n";
    ft::list<std::string> f(3, "poor");
    ft::list<std::string>::iterator scnd = f.begin();
    f.push_back("69");
    f.push_back("86");
    f.push_back("'look'");
    f.push_back("']'");
    f.push_back("'so?'");
    scnd++;
    f.splice(scnd, second);
    for (ft::list<std::string>::iterator spl = f.begin(); spl != f.end(); spl++)
        std::cout << "f: " << *spl << "\n";
    std::cout << "size of f: " << f.size() << "\n";

    ft::list<std::string> splice_lst(1, "'f'");
    splice_lst.push_back("'3'");
    splice_lst.push_back("'s'");
    splice_lst.push_back("'x'");
    splice_lst.push_back("'w'");

    std::cout << YELLOW"*************************************\n"RESET;
    
    std::list<std::string>::iterator frt1_orig = splice_lst_orig.begin();
    std::cout << "Creating new list: \n";
    for (std::list<std::string>::iterator s_orig = splice_lst_orig.begin(); s_orig != splice_lst_orig.end(); s_orig++)
        std::cout << "splice_lst: " << *s_orig << "\n";
    std::cout << "size of splice_lst: " << splice_lst_orig.size() << "\n";
    frt1_orig++;
    std::cout << "iterator postd::strings to: " << *frt1_orig << "\n";
    std::cout << "splice it to second list:\n";
    second_orig.push_back("'h'");
    second_orig.splice(second_orig.begin(), splice_lst_orig, frt1_orig);
    for (std::list<std::string>::iterator spl2_orig = second_orig.begin(); spl2_orig != second_orig.end(); spl2_orig++)
        std::cout << "second: " << *spl2_orig << "\n";
    std::cout << "size of second: " << second_orig.size() << "\n";
    
    splice_lst_orig.push_back("'a'");
    splice_lst_orig.push_back("'l'");
    splice_lst_orig.push_back("'g'");
    splice_lst_orig.push_back("'m'");
    splice_lst_orig.push_back("'n'");

    std::cout << PURPLE"*************************************\n"RESET;

    ft::list<std::string>::iterator frt1 = splice_lst.begin();
    std::cout << "Creating new list: \n";
    for (ft::list<std::string>::iterator s = splice_lst.begin(); s != splice_lst.end(); s++)
        std::cout << "splice_lst: " << *s<< "\n";
    std::cout << "size of splice_lst: " << splice_lst.size() << "\n";
    frt1++;
    std::cout << "iterator postd::strings to: " << *frt1 << "\n";
    std::cout << "splice it to second list:\n";
    second.push_back("'h'");
    second.splice(second.begin(), splice_lst, frt1);
    for (ft::list<std::string>::iterator spl2 = second.begin(); spl2 != second.end(); spl2++)
        std::cout << "second: " << *spl2 << "\n";
    std::cout << "size of second: " << second.size() << "\n";

    splice_lst.push_back("'a'");
    splice_lst.push_back("'l'");
    splice_lst.push_back("'g'");
    splice_lst.push_back("'m'");
    splice_lst.push_back("'n'");

    std::cout << YELLOW"*************************************\n"RESET;
    std::list<std::string>::iterator p_or = second_orig.begin();
    p_or++;
    second_orig.splice(p_or, f_orig, f_orig.begin(), f_orig.end());
    for (std::list<std::string>::iterator spl3_orig = second_orig.begin(); spl3_orig != second_orig.end(); spl3_orig++)
        std::cout << "second: " << *spl3_orig << "\n";
    std::cout << "size of second: " << second_orig.size() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;
    ft::list<std::string>::iterator p = second.begin();
    p++;
    second.splice(p, f, f.begin(), f.end());
    for (ft::list<std::string>::iterator spl3 = second.begin(); spl3 != second.end(); spl3++)
        std::cout << "second: " << *spl3 << "\n";
    std::cout << "size of second: " << second.size() << "\n";

    std::cout << GREEN"***************Remove****************\n"RESET;
    std::cout << "Remove form first all values of 11: \n";
    std::cout << "Before remove of first: \n";
    for (std::list<std::string>::iterator rmv_b_orig = first_orig.begin(); rmv_b_orig != first_orig.end(); rmv_b_orig++)
        std::cout << "first: " << *rmv_b_orig << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";
    first_orig.remove("adelina");
    std::cout << "After all adelina removed: \n";
    for (std::list<std::string>::iterator rmv_orig = first_orig.begin(); rmv_orig != first_orig.end(); rmv_orig++)
        std::cout << "first: " << *rmv_orig << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;
    
    std::cout << "Remove form first all values of 11: \n";
    std::cout << "Before remove of first: \n";
    for (ft::list<std::string>::iterator rmv_b = first.begin(); rmv_b != first.end(); rmv_b++)
        std::cout << "first: " << *rmv_b << "\n";
    std::cout << "size of first: " << first.size() << "\n";
    first.remove("adelina");
    std::cout << "After all adelina removed: \n";
    for (ft::list<std::string>::iterator rmv = first.begin(); rmv != first.end(); rmv++)
        std::cout << "first: " << *rmv << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << GREEN"**************Remove_if**************\n"RESET;
    std::cout << "Remove form first all values > 7: \n";
    first_orig.remove_if(single_digit_s);
    for (std::list<std::string>::iterator rmv_orig = first_orig.begin(); rmv_orig != first_orig.end(); rmv_orig++)
        std::cout << "first: " << *rmv_orig << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Remove form first all values > 7: \n";
    first.remove_if(single_digit_s);
    for (ft::list<std::string>::iterator rmv = first.begin(); rmv != first.end(); rmv++)
        std::cout << "first: " << *rmv << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << GREEN"*************Unique-Sort**************\n"RESET;
    std::cout << "Unique function called for first list: \n";
    first_orig.push_back("'2room'");
    first_orig.push_back("'2room'");
    first_orig.push_back("'2room'");
    first_orig.push_back("freak");
    std::cout << "Before sort and unique: \n";
    for (std::list<std::string>::iterator unq_b_orig = first_orig.begin(); unq_b_orig != first_orig.end(); unq_b_orig++)
        std::cout << "first: " << *unq_b_orig << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";
    
    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "Unique function called for first list: \n";
    first.push_back("'2room'");
    first.push_back("'2room'");
    first.push_back("'2room'");
    first.push_back("freak");
    std::cout << "Before sort and unique: \n";
    for (ft::list<std::string>::iterator unq_b = first.begin(); unq_b != first.end(); unq_b++)
        std::cout << "first: " << *unq_b << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    
    std::cout << "After sort and unique: \n";
    first_orig.sort();
    first_orig.unique();
    for (std::list<std::string>::iterator unq_orig = first_orig.begin(); unq_orig != first_orig.end(); unq_orig++)
        std::cout << "first: " << *unq_orig << "\n";
    std::cout << "size of first: " << first_orig.size() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "After sort and unique: \n";
    first.sort();
    first.unique();
    for (ft::list<std::string>::iterator unq = first.begin(); unq != first.end(); unq++)
        std::cout << "first: " << *unq << "\n";
    std::cout << "size of first: " << first.size() << "\n";

    std::cout << GREEN"***************Merge****************\n"RESET;
    std::cout << "Call merge member function for second: \n";
    std::list<std::string> merge_lst_orig(6, "'1'");
    std::list<std::string> merge_lst_2_orig(5, "'4'");
    merge_lst_orig.push_back("'l'");
    merge_lst_orig.push_back("';'");
    merge_lst_orig.push_back("'h'");
    merge_lst_orig.push_back("'d'");
    merge_lst_2_orig.push_back("'c'");
    merge_lst_2_orig.push_back("'s'");
    merge_lst_2_orig.push_back("'a'");
    merge_lst_2_orig.push_back("'c'");

    merge_lst_orig.sort();
    merge_lst_2_orig.sort();

    std::cout << "Merge 1: \n";
    for (std::list<std::string>::iterator mrg_orig = merge_lst_orig.begin(); mrg_orig != merge_lst_orig.end(); mrg_orig++)
        std::cout << "merge 1 before: " << *mrg_orig << "\n";
    std::cout << "Merge 2: \n";
    for (std::list<std::string>::iterator mrg_2_orig = merge_lst_2_orig.begin(); mrg_2_orig != merge_lst_2_orig.end(); mrg_2_orig++)
        std::cout << "merge 2 before: " << *mrg_2_orig << "\n";
    merge_lst_orig.merge(merge_lst_2_orig, Compare_str);

    std::cout << "Merge 1: \n";
    for (std::list<std::string>::iterator mrg_a_orig = merge_lst_orig.begin(); mrg_a_orig != merge_lst_orig.end(); mrg_a_orig++)
        std::cout << "merge 1 after: " << *mrg_a_orig << "\n";
    std::cout << "Merge 2:";
    if (merge_lst_2_orig.empty())
        std::cout << " is empty!\n";
    for (std::list<std::string>::iterator mrg_2_a_orig = merge_lst_2_orig.begin(); mrg_2_a_orig != merge_lst_2_orig.end(); mrg_2_a_orig++)
        std::cout << "merge 2 after: " << *mrg_2_a_orig << "\n";
    
    std::cout << YELLOW"*************************************\n"RESET;

    std::cout << "Call merge member function for second: \n";
    ft::list<std::string> merge_lst(6, "'1'");
    ft::list<std::string> merge_lst_2(5, "'4'");
    merge_lst.push_back("'l'");
    merge_lst.push_back("';'");
    merge_lst.push_back("'h'");
    merge_lst.push_back("'d'");
    merge_lst_2.push_back("'c'");
    merge_lst_2.push_back("'s'");
    merge_lst_2.push_back("'a'");
    merge_lst_2.push_back("'c'");

    merge_lst.sort();
    merge_lst_2.sort();

    std::cout << "Merge 1: \n";
    for (ft::list<std::string>::iterator mrg = merge_lst.begin(); mrg != merge_lst.end(); mrg++)
        std::cout << "merge 1 before: " << *mrg << "\n";
    std::cout << "Merge 2: \n";
    for (ft::list<std::string>::iterator mrg_2 = merge_lst_2.begin(); mrg_2 != merge_lst_2.end(); mrg_2++)
        std::cout << "merge 2 before: " << *mrg_2 << "\n";
    merge_lst.merge(merge_lst_2, Compare_str);

    std::cout << "Merge 1: \n";
    for (ft::list<std::string>::iterator mrg_a = merge_lst.begin(); mrg_a != merge_lst.end(); mrg_a++)
        std::cout << "merge 1 after: " << *mrg_a << "\n";
    std::cout << "Merge 2:";
    if (merge_lst_2.empty())
        std::cout << " is empty!\n";
    for (ft::list<std::string>::iterator mrg_2_a = merge_lst_2.begin(); mrg_2_a != merge_lst_2.end(); mrg_2_a++)
        std::cout << "merge 2 after: " << *mrg_2_a << "\n";

    std::cout << GREEN"***************Sort****************\n"RESET;
    std::cout << "Sort member function called for a new list: \n";
    std::list<std::string> for_sort_orig(1, "'h'");
    for_sort_orig.push_back("'s'");
    for_sort_orig.push_back("'a'");
    for_sort_orig.push_back("'b'");
    for_sort_orig.push_back("'n'");
    std::cout << "Before sorted: \n";
    for (std::list<std::string>::iterator srt_orig = for_sort_orig.begin(); srt_orig != for_sort_orig.end(); srt_orig++)
        std::cout << "first: " << *srt_orig << "\n";
    std::cout << "size of first: " << for_sort_orig.size() << "\n";
    for_sort_orig.sort(Compare_str);
    
    std::cout << PURPLE"*************************************\n"RESET;
    
    std::cout << "Sort member function called for a new list: \n";
    ft::list<std::string> for_sort(1, "'h'");
    for_sort.push_back("'s'");
    for_sort.push_back("'a'");
    for_sort.push_back("'b'");
    for_sort.push_back("'n'");
    std::cout << "Before sorted: \n";
    for (ft::list<std::string>::iterator srt = for_sort.begin(); srt != for_sort.end(); srt++)
        std::cout << "first: " << *srt << "\n";
    std::cout << "size of first: " << for_sort.size() << "\n";
    for_sort.sort(Compare_str);

    std::cout << YELLOW"*************************************\n"RESET;
    
    std::cout << "After sorted: \n";
    for (std::list<std::string>::iterator srt_1_orig = for_sort_orig.begin(); srt_1_orig != for_sort_orig.end(); srt_1_orig++)
        std::cout << "first: " << *srt_1_orig << "\n";
    std::cout << "size of first: " << for_sort_orig.size() << "\n";

    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "After sorted: \n";
    for (ft::list<std::string>::iterator srt_1 = for_sort.begin(); srt_1 != for_sort.end(); srt_1++)
        std::cout << "first: " << *srt_1 << "\n";
    std::cout << "size of first: " << for_sort.size() << "\n";
    
    std::cout << GREEN"***************Reverse****************\n"RESET;
    std::cout << "Reverses the order of the elements in the second: \n";
    std::cout << "Initial order: \n";
    for_sort_orig.push_back("'q'");
    for (std::list<std::string>::iterator rever_orig = for_sort_orig.begin(); rever_orig != for_sort_orig.end(); rever_orig++)
        std::cout << "second: " << *rever_orig << "\n";
    for_sort_orig.reverse();
    
    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "Reverses the order of the elements in the second: \n";
    std::cout << "Initial order: \n";
    for_sort.push_back("'q'");
    for (ft::list<std::string>::iterator rever = for_sort.begin(); rever != for_sort.end(); rever++)
        std::cout << "second: " << *rever << "\n";
    for_sort.reverse();
    
    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << "Reverse order: \n";
    for (std::list<std::string>::iterator rever2_orig = for_sort_orig.begin(); rever2_orig != for_sort_orig.end(); rever2_orig++)
        std::cout << "second: " << *rever2_orig << "\n";

    std::cout << PURPLE"*************************************\n"RESET;

    std::cout << "Reverse order: \n";
    for (ft::list<std::string>::iterator rever2 = for_sort.begin(); rever2 != for_sort.end(); rever2++)
        std::cout << "second: " << *rever2 << "\n";

    std::cout << PURPLE"************************************\n"RESET;
    std::cout << PURPLE"********Not member functions********\n"RESET;
    std::cout << PURPLE"************************************\n"RESET;

    std::cout << GREEN"*************operator==*************\n"RESET;
    if (merge_lst == for_sort)
        std::cout << "equal  lists!\n";
    else
        std::cout << "not equal lists!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator!=*************\n"RESET;
    if (merge_lst != for_sort)
        std::cout << "not equal  lists!\n";
    else
        std::cout << "equal lists!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator<**************\n"RESET;
    if (merge_lst < for_sort)
        std::cout << "is greater!\n";
    else
        std::cout << "is less!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator>**************\n"RESET;
    if (merge_lst > for_sort)
        std::cout << "is greater!\n";
    else
        std::cout << "is less!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator<=**************\n"RESET;
    if (merge_lst <= for_sort)
        std::cout << "is greater or equal!\n";
    else
        std::cout << "is less!\n";
    std::cout << std::endl;

    std::cout << GREEN"*************operator>=*************\n"RESET;
    if (merge_lst >= for_sort)
        std::cout << "is equal or greater!\n";
    else
        std::cout << "is less!\n";
    std::cout << std::endl;

    std::cout << GREEN"***********Reverse-Iterator*********\n"RESET;
    std::list<std::string> butter(3, "hello");
    butter.push_back("so what");
    butter.push_back("idk");
    butter.push_back("imho");
    butter.push_back("tree");

    for (std::list<std::string>::reverse_iterator butt = butter.rbegin(); butt != butter.rend(); butt++)
        std::cout << "prstd::string reverse original: " << *butt << "\n";
    
    ft::list<std::string> m_butter(3, "hello");
    m_butter.push_back("so what");
    m_butter.push_back("idk");
    m_butter.push_back("imho");
    m_butter.push_back("tree");

    for (ft::list<std::string>::reverse_iterator m_butt = m_butter.rbegin(); m_butt != m_butter.rend(); m_butt++)
        std::cout << "prstd::string reverse mine: " << *m_butt << "\n";

    std::cout << GREEN"*********Const_Rev_Iterator*********\n"RESET;
    std::list<std::string> butter_2(3, "hello");
    butter_2.push_back("so what");
    butter_2.push_back("idk");
    butter_2.push_back("imho");
    butter_2.push_back("tree");

    for (std::list<std::string>::const_reverse_iterator butt_2 = butter_2.rbegin(); butt_2 != butter_2.rend(); butt_2++)
        std::cout << "prstd::string const reverse original: " << *butt_2 << "\n";
    
    ft::list<std::string> m_butter_2(3, "hello");
    m_butter_2.push_back("so what");
    m_butter_2.push_back("idk");
    m_butter_2.push_back("imho");
    m_butter_2.push_back("tree");

    for (ft::list<std::string>::const_reverse_iterator m_butt_2 = m_butter_2.rbegin(); m_butt_2 != m_butter_2.rend(); m_butt_2++)
        std::cout << "prstd::string reverse mine: " << *m_butt_2 << "\n";
}
