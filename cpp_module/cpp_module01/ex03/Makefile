CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex03

SRCS = main.cpp Zombie.cpp ZombieHorde.cpp
OBJS = main.o Zombie.o ZombieHorde.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all