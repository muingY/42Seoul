CC = gcc
CFLAG = -Wall -Wextra -Werror

AS = nasm
AFLAG = -f macho64

AR = ar rcs

NAME = libasm.a

OBJS = ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o

$(NAME):
	$(AS) $(AFLAG) ft_strlen.s
	$(AS) $(AFLAG) ft_strcpy.s
	$(AS) $(AFLAG) ft_strcmp.s
	$(AS) $(AFLAG) ft_write.s
	$(AS) $(AFLAG) ft_read.s
	$(AS) $(AFLAG) ft_strdup.s
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: fclean all
	$(CC) -L. -lasm -o test test.c

testclean:
	rm -rf test

testre: testclean test
