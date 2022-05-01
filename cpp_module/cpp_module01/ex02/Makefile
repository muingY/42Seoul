CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = zombie

SRCS = main.cpp Zombie.cpp ZombieEvent.cpp
OBJS = main.o Zombie.o ZombieEvent.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all