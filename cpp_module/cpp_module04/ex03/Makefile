CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex03

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MaterialSource.cpp main.cpp
OBJS = AMateria.o Character.o Cure.o Ice.o MaterialSource.o main.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

