NAME = program
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = obj
SRC_DIR = ./
SRCS = $(wildcard ./*.cpp)
OBJS = $(wildcard ./*.gch)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

setup:
	curl https://raw.githubusercontent.com/musturu/cpp_42/main/setup_classes.py | python3 -

.PHONY: all clean fclean re run setup
