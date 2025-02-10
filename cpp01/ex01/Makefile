NAME = zombies
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = .
OBJ_DIR = obj
SRCS = Zombie.cpp zombieHorde.cpp  main.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

setup:
	curl https://raw.githubusercontent.com/musturu/cpp_42/main/setup_classes.py | python3 -

.PHONY: all clean fclean re run setup
