CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = pony

SRCS = ex01.cpp
OBJS = ex01.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all