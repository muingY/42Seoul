CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

NAME = libftprintf.a

SRCS = assistance_char.c assistance_hex.c assistance_mem.c assistance_nbr.c assistance_str.c flag_control.c printf_func1.c printf_func2.c ft_printf.c
OBJS = assistance_char.o assistance_hex.o assistance_mem.o assistance_nbr.o assistance_str.o flag_control.o printf_func1.o printf_func2.o ft_printf.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(AR) cr $@ $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
