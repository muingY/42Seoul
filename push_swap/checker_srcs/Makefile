CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = checker

SRCS = stack_1.c stack_2.c util_1.c util_2.c util_3.c execute.c checker.c
OBJS = stack_1.o stack_2.o util_1.o util_2.o util_3.o execute.o checker.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
