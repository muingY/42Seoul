
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

NAME = minishell

LIBFT_DIR = ./libft
LIBFT = ft

SRC_FILES = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			non_canonical/non_canonical_util.c non_canonical/non_canonical_util2.c non_canonical/non_canonical_util3.c non_canonical/non_canonical_util4.c non_canonical/non_canonical_input.c \
			str/str_check_utils.c str/ft_strdup2.c str/ft_split2.c str/ft_split2_sub.c \
			str/ft_split3.c \
			lst/cmd_utils.c lst/cmd_path_utils.c \
			lst/env_utils.c lst/env_keyvalue_utils.c \
			lst/pars_utils.c lst/pars_sub_utils1.c lst/pars_sub_utils2.c\
			builtin/builtin.c builtin/cd.c builtin/exit.c \
			builtin/unset.c builtin/export.c \
			builtin/echo.c builtin/pwd.c builtin/env.c \
			util.c util2.c \
			syntax1.c syntax2.c syntax3.c history.c \
			replace.c replace2.c \
			cmd_control.c signal.c \
			execution.c redirect1.c redirect2.c \
			minishell.c

HEADER_DIR = ./includes/
HEADER_FILES = minishell.h
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_FILES))

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -l$(LIBFT) -lncurses -o $@

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	/bin/rm -f $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	/bin/rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

re2 : re
	$(MAKE) clean
	/bin/ls $(NAME)
	[ -f ./$(NAME) ] && ./$(NAME)

.PHONY: all clean fclean re re2
