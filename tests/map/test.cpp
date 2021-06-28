#include "../Sources.hpp"

void test()
{
    std::cout << "Tests for <char, int> map starts: \n";
    
    std::cout << GREEN"**********Construction************\n"RESET;
    
    std::cout << PURPLE"Construct original empty map with size : "RESET;
    std::map<char, int> orig;
    std::cout << orig.size() << "\n";
    std::cout << PURPLE"Construct mine empty map with size : "RESET;
	  ft::map<char, int> mine;
    std::cout << mine.size() << "\n";

    std::cout << YELLOW"*************************************\n"RESET;
    std::cout << PURPLE"Inserting three elements into original: \n"RESET;
    orig.insert(std::pair<char,int>('p',56));
	  orig.insert(std::pair<char,int>('a',34));
	  orig.insert(std::pair<char,int>('w',12));

    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Orig size: " << orig.size() << "\n";

    std::cout << PURPLE"Inserting three elements into mine: \n"RESET;
    mine.insert(std::pair<char,int>('p',56));
	  mine.insert(std::pair<char,int>('a',34));
	  mine.insert(std::pair<char,int>('w',12));
    for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
		  std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine size: " << mine.size() << "\n";
    
    std::cout << GREEN"******Construction by iterator********\n"RESET;
    
    std::cout << PURPLE"Constructing orig_2 map from orig: \n"RESET;
    std::map<char, int> orig_2(orig.begin(), orig.end());
    std::cout << "New orig_2 map constructed: \n";
    for (std::map<char, int>::iterator it = orig_2.begin(); it != orig_2.end(); it++)
		  std::cout << "orig_2: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Orig_2 size: " << orig_2.size() << "\n";

    std::cout << PURPLE"Constructing mine_2 map from mine: \n"RESET;
	  ft::map<char, int> mine_2(mine.begin(), mine.end());
    std::cout << "New mine_2 map constructed: \n";
    for (ft::map<char, int>::iterator it = mine_2.begin(); it != mine_2.end(); it++)
		  std::cout << "mine_2: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine_2 size: " << mine_2.size() << "\n";

    std::cout << GREEN"*********Copy Constructor***********\n"RESET;
    
    std::cout << PURPLE"Constructing copy map of orig_2: \n"RESET;
    std::map<char, int> orig_3(orig_2);
    std::cout << "New orig_3 map constructed: \n";
    for (std::map<char, int>::iterator it = orig_3.begin(); it != orig_3.end(); it++)
		  std::cout << "orig_3: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Orig_3 size: " << orig_3.size() << "\n";

    std::cout << PURPLE"Constructing copy map of mine_2: \n"RESET;
    ft::map<char, int> mine_3(mine_2);
    std::cout << "New mine_3 map constructed: \n";
    for (ft::map<char, int>::iterator it = mine_3.begin(); it != mine_3.end(); it++)
		  std::cout << "mine_3: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine_3 size: " << mine_3.size() << "\n";

      std::cout << GREEN"************Operator=*************\n"RESET;
      std::cout << PURPLE"First make orig_2 and orig_3 different -> insert new el to orig_3: \n"RESET;
      orig_3.insert(std::pair<char,int>('u',12));
      orig_3.insert(std::pair<char,int>('r',10));
      std::cout << YELLOW"New orig_3: \n"RESET;
      for (std::map<char, int>::iterator it = orig_3.begin(); it != orig_3.end(); it++)
        std::cout << "orig_2: " << it->first << " with value: " << it->second << "\n";
      std::cout << YELLOW"Orig_2: \n"RESET;
      for (std::map<char, int>::iterator it = orig_2.begin(); it != orig_2.end(); it++)
        std::cout << "orig_2: " << it->first << " with value: " << it->second << "\n";
      
      std::cout << PURPLE"Now make orig_2 = orig_3: \n"RESET;
      orig_2 = orig_3;
      std::cout << YELLOW"New orig_2: \n"RESET;
      for (std::map<char, int>::iterator it = orig_2.begin(); it != orig_2.end(); it++)
        std::cout << "orig_2: " << it->first << " with value: " << it->second << "\n";
      std::cout << "Orig_2 size: " << orig_2.size() << "\n";

      std::cout << PURPLE"First make mine_2 and mine_3 different -> insert new el to mine_3: \n"RESET;
      mine_3.insert(std::pair<char,int>('u',12));
      mine_3.insert(std::pair<char,int>('r',10));
      std::cout << YELLOW"New mine_3: \n"RESET;
      for (ft::map<char, int>::iterator it = mine_3.begin(); it != mine_3.end(); it++)
        std::cout << "mine_2: " << it->first << " with value: " << it->second << "\n";
      std::cout << YELLOW"Mine_2: \n"RESET;
      for (ft::map<char, int>::iterator it = mine_2.begin(); it != mine_2.end(); it++)
        std::cout << "mine_2: " << it->first << " with value: " << it->second << "\n";

    std::cout << PURPLE"Now make mine_2 = mine_3: \n"RESET;
    mine_2 = mine_3;
    std::cout << YELLOW"New mine_2: \n"RESET;
    for (ft::map<char, int>::iterator it = mine_2.begin(); it != mine_2.end(); it++)
      std::cout << "mine_2: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine_2 size: " << mine_2.size() << "\n";

    std::cout << GREEN"************Iterators*************\n"RESET;
    
    std::cout << PURPLE"Check simple iterators: \n"RESET;
    std::cout << "Original: \n";
    for (std::map<char, int>::iterator it = orig_2.begin(); it != orig_2.end(); it++)
		  std::cout << "orig_2: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine: \n";
    for (ft::map<char, int>::iterator it = mine_2.begin(); it != mine_2.end(); it++)
		  std::cout << "mine_2: " << it->first << " with value: " << it->second << "\n";

    std::cout << PURPLE"Check const iterators: \n"RESET;
    std::cout << "Original: \n";
    for (std::map<char, int>::const_iterator it = orig_2.begin(); it != orig_2.end(); it++)
    std::cout << "orig_2: " << it->first << " with value: " << it->second << "\n";
    
    std::cout << "Mine: \n";
    for (ft::map<char, int>::const_iterator it = mine_2.begin(); it != mine_2.end(); it++)
    std::cout << "mine_2: " << it->first << " with value: " << it->second << "\n";
    
    std::cout << PURPLE"Check reverse iterators: \n"RESET;
    std::cout << "Original: \n";
    for (std::map<char, int>::reverse_iterator it = orig.rbegin(); it != orig.rend(); it++)
		std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine: \n";
    for (ft::map<char, int>::reverse_iterator it = mine.rbegin(); it != mine.rend(); it++)
		std::cout << "mine: " << it->first << " with value: " << it->second << "\n";

    std::cout << GREEN"************Capacity*************\n"RESET;

    std::cout << PURPLE"***************Empty**************\n"RESET;
    if (orig.empty())
        std::cout << "Original is empty!\n";
    else
        std::cout << "Original is not empty!\n";
    if (mine.empty())
        std::cout << "Mine is empty!\n";
    else    
        std::cout << "Mine is not empty!\n";
    
    std::cout << PURPLE"***************Size***************\n"RESET;
    std::cout << "Size of original: " << orig.size() << "\n";
    std::cout << "Size of mine: " << mine.size() << "\n";

    std::map<char, int> orig_max_size;
    ft::map<char, int> mine_max_size;


    std::cout << PURPLE"************Max-size**************\n"RESET;
	  std::cout << "Max size of original: " << orig_max_size.max_size() << "\n";
	  std::cout << "Max size of mine: " << mine_max_size.max_size() << "\n";

    std::cout << "====================================\n";

    std::map<int, int> orig_max_size_2;
    ft::map<int, int> mine_max_size_2;

    std::cout << "Max size of original: " << orig_max_size_2.max_size() << "\n";
	  std::cout << "Max size of mine: " << mine_max_size_2.max_size() << "\n";

    std::cout << "====================================\n";

    std::map<double, std::string> orig_max_size_4;
    ft::map<double, std::string> mine_max_size_4;

    std::cout << "Max size of original: " << orig_max_size_4.max_size() << "\n";
	  std::cout << "Max size of mine: " << mine_max_size_4.max_size() << "\n";

      std::cout << GREEN"************Element access*************\n"RESET;

      std::cout << PURPLE"************Operator[]*************\n"RESET;
      std::cout << YELLOW"using operator to insert values into orig: \n"RESET;
      orig['a'] = 13;
      orig['h'] = 43;
      orig['l'] = 33;
      orig['v'] = 113;

      std::cout << "orig['a'] has value " << orig['a'] << "\n";
      std::cout << "orig['h'] has value " << orig['h'] << "\n";
      std::cout << "orig['l'] has value " << orig['l'] << "\n";
      std::cout << "orig['v'] has value " << orig['v'] << "\n";

      for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		    std::cout << "orig: " << it->first << " with value: " << it->second << "\n";

      std::cout << YELLOW"using operator to insert values into mine: \n"RESET;
      
      mine['a'] = 13;
      mine['h'] = 43;
      mine['l'] = 33;
      mine['v'] = 113;

      std::cout << "mine['a'] has value " << mine['a'] << "\n";
      std::cout << "mine['h'] has value " << mine['h'] << "\n";
      std::cout << "mine['l'] has value " << mine['l'] << "\n";
      std::cout << "mine['v'] has value " << mine['v'] << "\n";

      for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
		    std::cout << "mine: " << it->first << " with value: " << it->second << "\n";


    std::cout << GREEN"************Modifiers**************\n"RESET;
    
    std::cout << PURPLE"************Insert-pair*************\n"RESET;
    std::cout << YELLOW"Insert into original: \n"RESET;
    std::cout << "insert: u with 17\n";
    orig.insert(std::pair<char,int>('u',17));
    std::cout << "insert: y with 12\n";
    orig.insert(std::pair<char,int>('y',12));
    std::cout << "insert: c with 10\n";
    orig.insert(std::pair<char,int>('c',10));
    std::cout << "insert: b with 10\n";
    orig.insert(std::pair<char,int>('b',10));

    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Orig size: " << orig.size() << "\n";

    std::cout << YELLOW"Insert into mine: \n"RESET;
    std::cout << "insert: u with 17\n";
    mine.insert(std::pair<char,int>('u',17));
    std::cout << "insert: y with 12\n";
    mine.insert(std::pair<char,int>('y',12));
    std::cout << "insert: c with 10\n";
    mine.insert(std::pair<char,int>('c',10));
    std::cout << "insert: b with 10\n";
    mine.insert(std::pair<char,int>('b',10));

    for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
		  std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine size: " << mine.size() << "\n";

    std::cout << PURPLE"**********Insert-iterator***********\n"RESET;
    std::map<char, int>::iterator or_it = orig.begin();
    or_it++;
    or_it++;
    orig.insert(or_it, std::pair<char,int>('d', 98));
    std::cout << PURPLE"Insert 'a' at specific position\n"RESET;
    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Orig size: " << orig.size() << "\n";

    ft::map<char, int>::iterator mine_it = mine.begin();
    mine_it++;
    mine_it++;
    mine.insert(mine_it, std::pair<char,int>('d', 98));
    std::cout << PURPLE"Insert 'a' at specific position\n"RESET;
    for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
		  std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine size: " << mine.size() << "\n";

    std::cout << PURPLE"**********Insert-range-iterator***********\n"RESET;
    std::cout << YELLOW"Insert orig_new into orig: \n"RESET;
    std::map<char, int> orig_new;
    orig_new.insert(std::pair<char,int>('1',64));
    orig_new.insert(std::pair<char,int>('2',89));
    orig_new.insert(std::pair<char,int>('3',345));
    orig_new.insert(std::pair<char,int>('4',894));
    orig_new.insert(std::pair<char,int>('5',323));
    std::cout << "Orig_new:\n";
    for (std::map<char, int>::iterator it = orig_new.begin(); it != orig_new.end(); it++)
		  std::cout << "orig_new: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Orig:\n";
    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << PURPLE"Insertion...\n"RESET;
    orig.insert(orig_new.begin(), orig_new.end());
    std::cout << "Original: \n";
    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Orig size: " << orig.size() << "\n";

    std::cout << YELLOW"Insert mine_new into mine: \n"RESET;
    ft::map<char, int> mine_new;
    mine_new.insert(std::pair<char,int>('1',64));
    mine_new.insert(std::pair<char,int>('2',89));
    mine_new.insert(std::pair<char,int>('3',345));
    mine_new.insert(std::pair<char,int>('4',894));
    mine_new.insert(std::pair<char,int>('5',323));
    std::cout << "Mine_new:\n";
    for (ft::map<char, int>::iterator it = mine_new.begin(); it != mine_new.end(); it++)
		  std::cout << "mine_new: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine:\n";
    for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
		  std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
    std::cout <<PURPLE "Insertion...\n"RESET;
    mine.insert(mine_new.begin(), mine_new.end());
    std::cout << "Mine: \n";
    for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
		  std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
    std::cout << "Mine size: " << mine.size() << "\n";

    std::cout << PURPLE"*************Erase-iterator***********\n"RESET;
    std::cout << YELLOW"Erase 1st element of original: \n"RESET;
    std::map<char, int>::iterator it_0 = orig.begin();
    orig.erase(it_0);
    std::cout << "Orig:\n";
    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";

    std::cout << YELLOW"Erase 1st element of mine: \n"RESET;
    ft::map<char, int>::iterator it_mine_0 = mine.begin();
    mine.erase(it_mine_0);
    std::cout << "Mine:\n";
    for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
		  std::cout << "mine: " << it->first << " with value: " << it->second << "\n";

    std::cout << PURPLE"*************Erase-total***********\n"RESET;
    std::cout << YELLOW"Erase 1st element of original: \n"RESET;
    std::map<char, int>::iterator it_ = orig_3.begin();
    orig_3.erase(it_, orig_3.end());
    std::cout << "Orig_3:\n";
    for (std::map<char, int>::iterator it = orig_3.begin(); it != orig_3.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
		std::cout << "orig_3 size: " << orig_3.size() << "\n";

    std::cout << YELLOW"Erase 1st element of mine: \n"RESET;
    ft::map<char, int>::iterator it_mine = mine_3.begin();
    
    mine_3.erase(it_mine, mine_3.end());
    std::cout << "Mine:\n";
    // for (ft::map<char, int>::iterator it = mine_3.begin(); it != mine_3.end(); it++)
		//   std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
		std::cout << "mine_3 size: " << mine_3.size() << "\n";

      std::cout << PURPLE"*************Erase-key***********\n"RESET;
      std::cout << YELLOW"Erase element 'w' of original: \n"RESET;
      orig.erase('w');
      std::cout << "Orig:\n";
      for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
        std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
      std::cout << "New orig size: " << orig.size() << std::endl;

      std::cout << YELLOW"Erase element 'w' of mine: \n"RESET;
      mine.erase('w');
      std::cout << "Mine:\n";
      for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
        std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
      std::cout << "New mine size: " << mine.size() << std::endl;

    std::cout << PURPLE"*************SWAP***********\n"RESET;
    std::cout << YELLOW"Swap orig with orig_2: \n"RESET;
    std::cout << YELLOW"Initial original: \n"RESET;
    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << YELLOW"Initial original_2:\n"RESET;
    for (std::map<char, int>::iterator it = orig_2.begin(); it != orig_2.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << PURPLE"initializing swap...\n"RESET;
    orig.swap(orig_2);
    std::cout << YELLOW"New original: \n"RESET;
    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    std::cout << YELLOW"New original_2:\n"RESET;
    for (std::map<char, int>::iterator it = orig_2.begin(); it != orig_2.end(); it++)
		  std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    
      std::cout << PURPLE"*************Mine-swap***********\n"RESET;
      std::cout << YELLOW"Swap mine with mine_2: \n"RESET;
      std::cout << YELLOW"Initial mine: \n"RESET;
      for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
        std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
      std::cout << YELLOW"Initial mine_2:\n"RESET;
      for (ft::map<char, int>::iterator it = mine_2.begin(); it != mine_2.end(); it++)
        std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
      std::cout << PURPLE"initializing swap...\n"RESET;
      mine_2.swap(mine);
      std::cout << YELLOW"New mine: \n"RESET;
      for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
        std::cout << "mine: " << it->first << " with value: " << it->second << "\n";
      std::cout << YELLOW"New mine_2:\n"RESET;
      for (ft::map<char, int>::iterator it = mine_2.begin(); it != mine_2.end(); it++)
        std::cout << "mine: " << it->first << " with value: " << it->second << "\n";

      std::cout << PURPLE"*************Mine-swap***********\n"RESET;
      ft::map<char, int> m;
      m.insert(std::pair<char,int>('u',12));
      m.insert(std::pair<char,int>('r',42));
      m.insert(std::pair<char,int>('t',52));
      m.insert(std::pair<char,int>('h',17));

      for (ft::map<char, int>::iterator it = m.begin(); it != m.end(); it++)
        std::cout << "m: " << it->first << " with value: " << it->second << "\n";

      ft::map<char, int> m_u;
      m_u.insert(std::pair<char,int>('f',62));
      m_u.insert(std::pair<char,int>('g',48));
      m_u.insert(std::pair<char,int>('q',72));
      m_u.insert(std::pair<char,int>('e',47));
      m_u.insert(std::pair<char,int>('4',48));
      m_u.insert(std::pair<char,int>('6',44));

      for (ft::map<char, int>::iterator it = m_u.begin(); it != m_u.end(); it++)
        std::cout << "m_u: " << it->first << " with value: " << it->second << "\n";

      m.swap(m_u);

      for (ft::map<char, int>::iterator it = m.begin(); it != m.end(); it++)
        std::cout << "m: " << it->first << " with value: " << it->second << "\n";
      for (ft::map<char, int>::iterator it = m_u.begin(); it != m_u.end(); it++)
        std::cout << "m_u: " << it->first << " with value: " << it->second << "\n";


    std::cout << PURPLE"*************Mine-find***********\n"RESET;
    std::cout << "Find an element with the value of 'a': \n";
    ft::map<char, int>::iterator it = mine_2.find('a');
    if (it != mine_2.end())
      std::cout << "Element is found and it's key is " << it->second << "!\n";

    for (ft::map<char, int>::iterator it = mine_2.begin(); it != mine_2.end(); it++)
		  std::cout << "mine: " << it->first << " with value: " << it->second << "\n";

    std::cout << PURPLE"**********Lower_bound***********\n"RESET;
    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
        std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    
    std::map<char,int>::iterator itlow,itup;
    itlow = orig.lower_bound ('p');
    itup = orig.upper_bound ('y');

    std::cout << YELLOW"Before erasing lower and upper for orig!\n"RESET;
		for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
        std::cout << "orig: " << it->first << " with value: " << it->second << "\n";
    
		orig.erase(itlow, itup);
    std::cout << YELLOW"After erasing lower and upper for orig!\n"RESET;
    for (std::map<char, int>::iterator it = orig.begin(); it != orig.end(); it++)
        std::cout << "orig: " << it->first << " with value: " << it->second << "\n";

		ft::map<char, int>::iterator it_low = mine.lower_bound('p');
		ft::map<char, int>::iterator it_up = mine.upper_bound('y');

    std::cout << PURPLE"Before erasing lower and upper for mine!\n"RESET;
		for (ft::map<char, int>::iterator it = mine.begin(); it != mine.end(); it++)
			std::cout << "mine: " << it->first << " with value: " << it->second << std::endl;
		
		mine.erase(it_low, it_up);
    std::cout << PURPLE"After erasing lower and upper for mine!\n"RESET;
    ft::map<char, int>::iterator it_ee = mine.end();
		for (ft::map<char, int>::iterator it = mine.begin(); it != it_ee; it++)
			std::cout << "mine: " << it->first << " with value: " << it->second << std::endl;

    std::cout << PURPLE"**********Equal_range***********\n"RESET;
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = orig.equal_range('3');

    std::cout << "lower bound of orig points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';
    std::cout << "upper bound of orig points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';

     std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret_mine = mine.equal_range('3');

    std::cout << "lower bound of mine points to: ";
    std::cout << ret_mine.first->first << " => " << ret_mine.first->second << '\n';
    std::cout << "upper bound of mine points to: ";
    std::cout << ret_mine.second->first << " => " << ret_mine.second->second << '\n';
 
} 
