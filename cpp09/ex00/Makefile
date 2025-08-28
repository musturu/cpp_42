NAME = btc
SRC = main.cpp BitcoinExchange.cpp
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

.PHONY: all clean fclean re subject
subject:
	@echo "date | value" > input.data
	@echo "2011-01-03 | 3" >> input.data
	@echo "2011-01-03 | 2" >> input.data
	@echo "2011-01-03 | 1" >> input.data
	@echo "2011-01-03 | 1.2" >> input.data
	@echo "2011-01-09 | 1" >> input.data
	@echo "2012-01-11 | -1" >> input.data
	@echo "2001-42-42" >> input.data
	@echo "2012-01-11 | 1" >> input.data
	@echo "2012-01-11 | 2147483648" >> input.data
