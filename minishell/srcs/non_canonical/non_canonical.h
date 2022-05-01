/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_canonical.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:33:29 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/09 14:43:09 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NON_CANONICAL_H
# define NON_CANONICAL_H

# include <termios.h>
# include <termcap.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# include "../../includes/minishell.h"

# ifdef __linux__
#  define TERM	"xterm-256color"
# endif
# ifdef __APPLE__
#  define TERM	"xterm"
# endif

/*
**[input state]
** 0 = enter, just string
** 1 = backspace
*/
typedef struct	s_ncinput
{
	char		*input;
	int			input_state;
}				t_ncinput;

typedef struct	s_termcap
{
	char		*cm;
	char		*ce;
	int			col;
	int			row;
}				t_termcap;

int				nc_strlen(char *str);
char			*nc_stradd(char *str, char c);
char			*nc_strsub(char *str);
int				nc_isstr(int c);
void			nc_get_cursor_pos(t_termcap *termcap);
void			nc_display(t_ncinput *nc, t_termcap *termcap, int c);
t_ncinput		nc_ctrld(t_ncinput *nc);
void			nc_sighelp(t_ncinput *nc, t_termcap *termcap);
void			nc_sub(int input, t_ncinput *ret,
t_termcap *termcap, int *is_continue);
void			nc_input_process(int input, t_ncinput *ret,
int *is_continue, t_termcap *termcap);
void			nc_clear_buf(t_ncinput *nc, t_termcap *termcap);
void			nc_history(int *input, t_ncinput *ret,
t_termcap *termcap);
void			nc_history_sub(t_ncinput *ret);

void			non_canonical_init(int mode);
t_ncinput		non_canonical_input();

#endif
