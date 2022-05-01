CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = fixed

SRCS = main.cpp Fixed.cpp
OBJS = main.o Fixed.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all