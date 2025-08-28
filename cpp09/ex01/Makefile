NAME = RPN
SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
test: $(NAME)
	@echo 'Test 1: ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"'
	-@./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo 'Test 2: ./RPN "7 7 * 7 -"'
	-@./RPN "7 7 * 7 -"
	@echo 'Test 3: ./RPN "1 2 * 2 / 2 * 2 4 - +"'
	-@./RPN "1 2 * 2 / 2 * 2 4 - +"
	@echo 'Test 4: ./RPN "(1 + 1)"'
	-@ ./RPN "(1 + 1)" || true
