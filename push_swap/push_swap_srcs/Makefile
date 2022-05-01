CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = push_swap.c sort1.c sort2.c sort3.c sort4.c sort5.c sort6.c stack_1.c stack_2.c util_1.c util_2.c util_3.c
OBJS = push_swap.o sort1.o sort2.o sort3.o sort4.o sort5.o sort6.o stack_1.o stack_2.o util_1.o util_2.o util_3.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
