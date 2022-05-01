/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:16:44 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/06 17:16:07 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include <termios.h>

typedef char			t_bool;
# define TRUE		1
# define FALSE		0
# define ERROR		-1

/*
** BACKSLASH, DOLLAR
*/

enum					e_pars
{
	NORM, SPCE, SINQ, DOUQ, BSLA, DOLR,
	PIPE, DPIP, SEMC, DSEM,
	RIGT, DRGT, LEFT
};

typedef struct s_tag	t_tag;
typedef struct s_cmd	t_cmd;
typedef struct s_env	t_env;

typedef struct			s_builtin
{
	char	*builtin_str[8];
	int		(*builtin_func[8])(t_tag *, t_cmd *, t_env *);
}						t_builtin;

struct					s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
};

/*
**	//int			is_redirection;
**	//t_bool		is_env;
**	//t_bool		is_semi;
*/

struct					s_cmd
{
	char			**argv;
	int				argc;
	t_bool			is_pipe;
	int				fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
};

typedef struct			s_hist
{
	char			**stack;
	int				top;
	int				i;
}						t_hist;

typedef struct			s_pars
{
	char			*str;
	int				type;
	struct s_pars	*prev;
	struct s_pars	*next;
}						t_pars;

struct					s_tag
{
	t_builtin		builtin;
	char			**envp;
	t_pars			*pars;
	t_pars			*pars_sub;
	char			*parsed;
	t_env			*env;
	t_cmd			*cmd;
	t_hist			hist;
	t_hist			*now;
	t_bool			is_sigon;
	char			*input;
	int				redirect0;
	int				redirect1;
	int				status;
	int				is_cmd;
	int				sig_c;
};

t_tag					g_tag;

#endif
