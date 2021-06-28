NAME = tester

OBJ_DIR = obj/
H_DIR = includes/

SRC = 	main.cpp

TESTS = tests/list/*.cpp tests/map/*.cpp tests/queue/*.cpp tests/stack/*.cpp tests/vector/*.cpp


OBJ = $(SRC:.c=.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = -I$(H_DIR)

.PHONY: all clean fclean makeobjdir re bonus leaks

all:$(NAME)

$(OBJ)%.o: $(SRC)%.c
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

-include $(DEP)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(TESTS)

clean:
		/bin/rm -f main.o

fclean: clean
		/bin/rm -f $(NAME)

#leaks -atExit -- ./tester
