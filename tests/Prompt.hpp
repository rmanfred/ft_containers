#pragma once

#include "list/Test_list.hpp"
#include "map/Test_map.hpp"
#include "vector/Test_vector.hpp"
#include "queue/Test_queue.hpp"
#include "stack/Test_stack.hpp"
#include "Sources.hpp"

# define PROMPT_1 	GREEN"Tests for ft_containers generated! \n"RESET
# define PROMPT_2 	YELLOW"Please, choose the container to run: \n"RESET

# define LIST 		PURPLE"0.List\n"RESET
# define VECTOR 	PURPLE"1.Vector\n"RESET
# define MAP 		PURPLE"2.Map\n"RESET
# define QUEUE 		PURPLE"3.Queue\n"RESET
# define STACK 		PURPLE"4.Stack\n"RESET
# define EXIT 		PURPLE"5.Exit\n"RESET

enum CMDS {
	CMD_1,
	CMD_2,
	CMD_3,
	CMD_4,
	CMD_5,
	CMD_6
};

