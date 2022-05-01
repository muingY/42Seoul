CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c philo.c philocontrol1.c philocontrol2.c util1.c util2.c
OBJS = main.o philo.o philocontrol1.o philocontrol2.o util1.o util2.o

NAME = philo

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -lpthread

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
