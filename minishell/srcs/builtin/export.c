/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:24:28 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/08 22:42:59 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		split_set_env(t_env *env, char *str, char *estr)
{
	int		ret;
	char	*keystr;
	char	*valstr;

	ret = 0;
	keystr = ft_substr(str, 0, estr - str);
	valstr = ft_strdup2(estr + 1);
	if (!*keystr)
		ret = 1;
	else if (keystr && valstr)
		ret = set_env_value(env, keystr, valstr);
	return (ret);
}

void	sort_strs(char **strs, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (ft_strcmp(strs[j], strs[j + 1]) > 0)
			{
				tmp = strs[j + 1];
				strs[j + 1] = strs[j];
				strs[j] = tmp;
			}
		}
	}
}

int		print_sorted_env_and_return(t_tag *tag, t_env *env)
{
	char	**envstrs;
	int		len;
	int		i;

	tag->status = 0;
	len = get_num_of_env(env);
	envstrs = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (env)
	{
		envstrs[i] = get_envstr(env);
		env = env->next;
		i++;
	}
	envstrs[i] = NULL;
	sort_strs(envstrs, len);
	i = -1;
	while (++i < len)
		printf("declare -x %s\n", envstrs[i]);
	free_ppchar(envstrs);
	return (tag->status);
}

int		ft_export_sub(t_tag *tag, t_cmd *cmd, t_env *env)
{
	if (cmd->argc == 1)
		return (print_sorted_env_and_return(tag, env));
	if (cmd->argc == 2 && ft_strcmp(cmd->argv[1], "=") == 0)
	{
		tag->status = 1;
		return (tag->status);
	}
	return (0);
}

int		ft_export(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int		i;
	char	*estr;

	tag->status = 0;
	if (cmd->argc == 1 ||
		(cmd->argc == 2 && ft_strcmp(cmd->argv[1], "=") == 0))
		return (ft_export_sub(tag, cmd, env));
	i = 0;
	while (cmd->argv[++i])
	{
		if (!is_valid_env_str(cmd->argv[i], FALSE, TRUE))
		{
			ft_putstr_fd("bash: export: `", 2);
			ft_putstr_fd(cmd->argv[i], 2);
			returnf("'", 1, "not a valid identifier", 1);
			continue;
		}
		estr = ft_strchr(cmd->argv[i], '=');
		if (estr)
			tag->status = tag->status | split_set_env(env, cmd->argv[i], estr);
		else
			tag->status = tag->status |
				set_env_value(env, ft_strdup2(cmd->argv[i]), ft_strdup2(""));
	}
	return (tag->status);
}
