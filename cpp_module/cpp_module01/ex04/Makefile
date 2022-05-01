CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex04

SRCS = ex04.cpp
OBJS = ex04.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all