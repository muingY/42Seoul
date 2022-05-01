CC = g++
CFLAGS = -std=c++98 -Wall -Werror -Wextra

NAME_FT = ftTest
NAME_STD = stdTest

SRCS = mainFT.cpp mainSTD.cpp
OBJS_FT = mainFT.o
OBJS_STD = mainSTD.o

$(NAME_FT):
	$(CC) -c $(SRCS)
	$(CC) -o $(NAME_STD) $(OBJS_STD)
	$(CC) -o $(NAME_FT) $(OBJS_FT)

all: $(NAME_FT)

clean:
	rm -f $(OBJS_FT)
	rm -f $(OBJS_STD)

fclean: clean
	rm -f $(NAME_FT)
	rm -f $(NAME_STD)

re: fclean all