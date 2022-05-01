/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:23:35 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/09 15:39:47 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd_sub(t_tag *tag, t_cmd *cmd, char **dir, int *is_oldpwd)
{
	if (cmd->argc == 1)
		*dir = get_env_value(tag->env, "HOME");
	else if (ft_strcmp(cmd->argv[1], "-") == 0)
	{
		*dir = get_env_value(tag->env, "OLDPWD");
		*is_oldpwd = 1;
	}
	else
		*dir = cmd->argv[1];
}

int		is_emptyhome(t_cmd *cmd, char *dir, char *tmp, int is_oldpwd)
{
	if (is_oldpwd == 0 && (!dir || !dir[0]))
	{
		free(tmp);
		return (1);
	}
	if (cmd->argc > 2)
	{
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_cd(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int		chbool;
	char	*tmp;
	char	*dir;
	int		is_oldpwd;

	(void)env;
	is_oldpwd = 0;
	tmp = getcwd(NULL, BUFSIZ);
	ft_cd_sub(tag, cmd, &dir, &is_oldpwd);
	if (is_emptyhome(cmd, dir, tmp, is_oldpwd))
		return (returnf("bash: cd", 1, "Parameter not set", 1));
	else if (is_oldpwd == 1 && ft_strcmp(dir, "") == 0)
	{
		free(tmp);
		return (returnf("bash: cd", 1, "OLDPWD not set", 1));
	}
	chbool = chdir(dir);
	set_env_value(tag->env, ft_strdup("OLDPWD"), tmp);
	if (chbool == -1)
	{
		ft_putstr_fd("bash: cd: ", 2);
		return (returnf(cmd->argv[1], 1, strerror(errno), 1));
	}
	set_env_value(tag->env, ft_strdup("PWD"), getcwd(NULL, BUFSIZ));
	return (returnf("", 0, "", 0));
}
