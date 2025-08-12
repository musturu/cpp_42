TARGET = span
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Span.cpp
OBJS = main.o Span.o
RM = rm -f
.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.cpp Span.hpp
Span.o: Span.cpp Span.hpp

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
