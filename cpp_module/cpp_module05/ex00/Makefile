CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex00

SRCS = main.cpp Bureaucrat.cpp
OBJS = main.o Bureaucrat.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all