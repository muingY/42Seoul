/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:47:48 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/08 23:07:04 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_bool	isnotsent(char *str, int i)
{
	int f[2];
	int ii;

	f[0] = 0;
	f[1] = 0;
	ii = 0;
	while (ii < i)
	{
		if (str[ii] == '\"')
			f[0]++;
		else if (str[ii] == '\'')
			f[1]++;
		ii++;
	}
	while ((f[0] % 2 == 1 || f[1] % 2 == 1) && str[i])
	{
		if (f[0] % 2 == 1 && str[i] == '\"')
			return (FALSE);
		else if (f[1] % 2 == 1 && str[i] == '\'')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		set_line(char **str, char **line, int *is_pipe)
{
	char *nextstr;
	char *newstr;

	if (!str || !(*str) || !line)
		return (-1);
	nextstr = ft_strchr2(*str, '|', ';', is_pipe);
	if (nextstr)
	{
		*line = ft_substr(*str, 0, nextstr - *str);
		newstr = ft_strdup2(nextstr + 1);
		if (*str)
			free(*str);
		*str = newstr;
		return (1);
	}
	else
		return (0);
}

t_cmd	*create_cmd(t_cmd *prev_cmd, int ac, char **av, int is_pipe)
{
	t_cmd	*new;
	int		i;

	if (!(new = malloc(sizeof(t_cmd))))
		return (NULL);
	if (!(new->argv = malloc(sizeof(char *) * (ac + 1))))
		return (NULL);
	new->argc = ac;
	i = -1;
	while (++i < ac)
		new->argv[i] = ft_strdup2(av[i]);
	new->argv[i] = NULL;
	new->is_pipe = is_pipe;
	new->prev = prev_cmd;
	new->next = NULL;
	if (prev_cmd)
		prev_cmd->next = new;
	if (!g_tag.cmd)
		g_tag.cmd = new;
	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
	av = NULL;
	return (new);
}

char	**do_split(t_tag *tag, char **cmdstr, int *argc)
{
	char	**args;

	get_pars(*cmdstr, 1);
	free(*cmdstr);
	*cmdstr = get_parsed_sub_input(tag, 1);
	args = ft_split3(*cmdstr, " \t\r\n\a", argc);
	return (args);
}

/*
**		//get_pars(cmdstr, 1);
**		//free(cmdstr);
**		//cmdstr = get_parsed_sub_input(tag, 1);
**		//args = ft_split3(cmdstr, " \t\r\n\a", &argc);
**		args = do_split(tag, &cmdstr, &argc);
*/

int		set_cmd(char **inputstr, t_tag *tag)
{
	char	*cmdstr;
	char	**args;
	int		argc;
	int		is_pipe;
	t_cmd	*cur;

	cur = tag->cmd;
	is_pipe = 0;
	while (set_line(inputstr, &cmdstr, &is_pipe) > 0)
	{
		args = do_split(tag, &cmdstr, &argc);
		cur = create_cmd(cur, argc, args, is_pipe);
		free(cmdstr);
		cmdstr = NULL;
	}
	if (inputstr)
	{
		cmdstr = *inputstr;
		is_pipe = 0;
		args = do_split(tag, &cmdstr, &argc);
		cur = create_cmd(cur, argc, args, is_pipe);
		free(cmdstr);
		cmdstr = NULL;
	}
	return (0);
}
