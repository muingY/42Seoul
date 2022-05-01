CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex06

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = main.o Weapon.o HumanA.o HumanB.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all