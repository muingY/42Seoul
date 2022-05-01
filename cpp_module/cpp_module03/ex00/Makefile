CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ClapTrap

SRCS = main.cpp ClapTrap.cpp
OBJS = main.o ClapTrap.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all