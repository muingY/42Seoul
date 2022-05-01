CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Polymorphism

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp
OBJS = main.o Animal.o Cat.o Dog.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all