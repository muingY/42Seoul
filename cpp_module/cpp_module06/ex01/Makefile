CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex01

SRCS = main.cpp Serialize.cpp
OBJS = main.o Serialize.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all