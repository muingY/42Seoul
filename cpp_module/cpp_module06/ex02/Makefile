CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02

SRCS = main.cpp Base.cpp
OBJS = main.o Base.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all