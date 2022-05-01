CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = replace

SRCS = main.cpp Replace.cpp
OBJS = main.o Replace.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.replace

re: fclean all