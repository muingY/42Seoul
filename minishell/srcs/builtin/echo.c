/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:24:10 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/04/30 18:01:28 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		update_status(int status)
{
	int		ret;

	ret = status;
	if (status == 248)
	{
		g_tag.status = 258;
		ret = 258;
	}
	return (ret);
}

int		just_enter(void)
{
	printf("\n");
	return (0);
}

void	do_in_while(t_cmd *cmd, int *i)
{
	if (*i > 1 && ft_strcmp(cmd->argv[*i], "-n") == 0)
	{
		(*i)++;
		return ;
	}
	printf("%s", cmd->argv[*i]);
	if (*i + 1 < cmd->argc)
		printf(" ");
	(*i)++;
}

int		ft_echo(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int	i;
	int opt_n;

	(void)tag;
	(void)env;
	if (cmd->argc == 1)
		return (just_enter());
	i = 1;
	opt_n = 0;
	if (ft_strlen(cmd->argv[i]) == 2 && ft_strcmp(cmd->argv[i], "-n") == 0)
	{
		i++;
		opt_n++;
	}
	while (i < cmd->argc)
		do_in_while(cmd, &i);
	if (opt_n == 0)
		printf("\n");
	return (0);
}
