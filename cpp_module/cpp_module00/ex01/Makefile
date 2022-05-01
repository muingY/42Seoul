CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SRCS = main.cpp phonebook.cpp
OBJS = main.o phonebook.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all