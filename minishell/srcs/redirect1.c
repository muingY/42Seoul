/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 02:39:59 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/04 21:03:01 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		redirect_loop(t_tag *tag, t_cmd *cmd, int *cnt)
{
	int		k;
	int		flag;
	int		ret;

	flag = 0;
	k = -1;
	(void)flag;
	while (cmd->argv[++k])
	{
		ret = get_redirect_fd(tag, cmd->argv[k], cmd->argv[k + 1]);
		if (ret == 1942)
			(*cnt)++;
		else if (ret != 0)
			return (ret);
	}
	return (0);
}

void	redirect_dub(t_tag *tag, t_cmd *cmd)
{
	(void)cmd;
	if (tag->redirect1 > 0)
		dup2(tag->redirect1, 1);
	if (tag->redirect0 > 0)
		dup2(tag->redirect0, 0);
}

void	reset_args(t_cmd *cmd, int cnt)
{
	char	**newargv;
	int		newargc;
	int		i;
	int		j;

	newargc = cmd->argc - 2 * cnt;
	newargv = (char **)malloc(sizeof(char *) * (newargc + 1));
	i = -1;
	j = -1;
	while (++i < cmd->argc)
	{
		if (get_arg_type(cmd->argv[i]) >= 0 &&
			get_arg_type(cmd->argv[i]) <= 2)
			i++;
		else
			newargv[++j] = ft_strdup2(cmd->argv[i]);
	}
	newargv[++j] = NULL;
	free_ppchar(cmd->argv);
	cmd->argc = newargc;
	cmd->argv = newargv;
}

/*
** ft_putstr_fd(cmd->argv[j], 2);
** ft_putstr_fd(",", 2);
** ft_putstr_fd("[", 2);
** ft_putnbr_fd(j, 2);
** ft_putstr_fd("]\n", 2);
*/

int		redirect_cmd(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int		ret;
	int		cnt;

	(void)env;
	init_redirect(tag);
	cnt = 0;
	ret = redirect_loop(tag, cmd, &cnt);
	if (ret != 0)
		return (ret);
	if (tag->redirect0 == 0 && tag->redirect1 == 0)
		return (0);
	if (tag->redirect0 == -1 || tag->redirect1 == -1)
		return (1);
	redirect_dub(tag, cmd);
	reset_args(cmd, cnt);
	return (0);
}
