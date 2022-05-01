/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:31:04 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/06 15:56:47 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_exit(t_tag *tag, t_cmd *cmd, t_env *env)
{
	(void)tag;
	(void)env;
	if (cmd->prev && cmd->prev->is_pipe == TRUE)
		return (returnf("", 0, "", 0));
	if (cmd->argc == 1)
		exitf("exit", 0, "", 0);
	else if (cmd->argc == 2)
	{
		if (ft_strcmp(cmd->argv[1], "-") == 0)
			exitf("exit", 0, "", 255);
		else if (is_numeric_argument(cmd->argv[1]) == TRUE)
			exitf("exit", 0, "", ft_atoi(cmd->argv[1]));
		else
		{
			ft_putstr_fd("exit\nbash: exit: ", 2);
			exitf(cmd->argv[1], 1, "numeric argument required", 255);
		}
	}
	else
		return (returnf("bash: exit", 1, "too many arguments", 1));
	history_destory(&tag->hist);
	exit(EXIT_SUCCESS);
}

/*
**	putcolon == 1, : e
**	putcolon == 2, 'e'
**	putcolont == 3 : 'e'
*/

int		exitf(char *s, int putcolon, char *e, int status)
{
	if (s && *s)
		ft_putstr_fd(s, 2);
	if (putcolon == 1 || putcolon == 3)
		ft_putstr_fd(": ", 2);
	if (putcolon == 2 || putcolon == 3)
		ft_putstr_fd("'", 2);
	if (e && *e)
		ft_putstr_fd(e, 2);
	if (putcolon == 2 || putcolon == 3)
		ft_putstr_fd("'", 2);
	if (s && *s)
		ft_putstr_fd("\n", 2);
	g_tag.status = status;
	exit(status);
}

int		exitf_exec(char *cmd, char *e, int errnum)
{
	int status;

	status = 0;
	if (errnum == 2)
		status = 127;
	else if (errnum == 13)
		status = 126;
	ft_putstr_fd("bash: ", 2);
	return (exitf(cmd, 1, e, status));
}

/*
**	putcolon == 1, : e
**	putcolon == 2, 'e'
**	putcolon == 3, : 'e'
*/

int		returnf(char *s, int putcolon, char *e, int status)
{
	if (s && *s)
		ft_putstr_fd(s, 2);
	if (putcolon == 1 || putcolon == 3)
		ft_putstr_fd(": ", 2);
	if (putcolon == 2 || putcolon == 3)
		ft_putstr_fd("'", 2);
	if (e && *e)
		ft_putstr_fd(e, 2);
	if (putcolon == 2 || putcolon == 3)
		ft_putstr_fd("'", 2);
	if (s && *s)
		ft_putstr_fd("\n", 2);
	g_tag.status = status;
	return (status);
}

/*
** char *e = strerror(errno)
*/

int		returnf2(int status, char *str)
{
	if (status == 248)
	{
		if (!*str)
			str = "new line";
		return (returnf("bash: syntax error near unexpected token ",
			2, str, status));
	}
	return (1);
}
