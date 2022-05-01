CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex05

SRCS = main.cpp Brain.cpp Human.cpp
OBJS = main.o Brain.o Human.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all