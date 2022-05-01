CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = convert

SRCS = main.cpp ConvTool.cpp
OBJS = main.o ConvTool.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all