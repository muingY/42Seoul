/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:13 by seongcho          #+#    #+#             */
/*   Updated: 2021/04/29 14:22:53 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_cmd_in_path(char *cmd, char *path)
{
	DIR				*dir;
	struct dirent	*d;

	(void)cmd;
	dir = opendir(path);
	if (!dir)
		return (FALSE);
	while (dir && (d = readdir(dir)))
	{
		if (ft_strcmp(cmd, d->d_name) == 0)
		{
			closedir(dir);
			return (TRUE);
		}
	}
	closedir(dir);
	return (FALSE);
}

int		check_cmd_path(t_cmd *cmd, t_env *env)
{
	char	*pathstr;
	char	**path;
	char	*tmp1;
	char	*tmp2;
	int		i;

	pathstr = ft_strdup2(get_env_value(env, "PATH"));
	path = ft_split(pathstr, ':');
	i = -1;
	while (path[++i])
	{
		if (is_cmd_in_path(cmd->argv[0], path[i]))
		{
			tmp1 = ft_strjoin(path[i], "/");
			tmp2 = cmd->argv[0];
			cmd->argv[0] = ft_strjoin(tmp1, tmp2);
			free(tmp1);
			free(tmp2);
			break ;
		}
	}
	free_ppchar(path);
	return (0);
}
