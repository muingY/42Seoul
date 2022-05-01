/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:55:29 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/08 15:04:55 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**-1 = none
**0  = ~
**1  = $... (env)
**2  = $(num)
**3  = $?
*/

int		cmd_is_replace(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '~' && str[i + 1] != '~' &&
			(i > 0 ? (str[i - 1] != '~') : 1))
			return (0);
		else if (str[i] == '$' &&
				(ft_isalpha(str[i + 1]) == 1 || str[i + 1] == '_'))
			return (1);
		else if (str[i] == '$' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (2);
		else if (str[i] == '$' && str[i + 1] == '?')
			return (3);
		i++;
	}
	return (-1);
}

char	*replace_wavedash(t_tag *tag, char *cmd)
{
	char	*ret;
	char	*home_dir;
	int		n[3];

	home_dir = get_env_value(tag->env, "HOME");
	n[0] = sizeof(char) * (ft_strlen(cmd) + ft_strlen(home_dir));
	ret = (char*)malloc(n[0]);
	ret[n[0] - 1] = '\0';
	n[1] = 0;
	while (n[1] < n[0] - 1 && cmd[n[1]] != '~')
	{
		ret[n[1]] = cmd[n[1]];
		n[1]++;
	}
	n[2] = n[1];
	while (n[2] < n[0] - 1 && home_dir[n[2] - n[1]])
	{
		ret[n[2]] = home_dir[n[2] - n[1]];
		n[2]++;
	}
	n[1]++;
	while (n[2] < n[0] - 1 && cmd[n[1]])
		ret[n[2]++] = cmd[n[1]++];
	free(cmd);
	return (ret);
}

char	*replace_question(t_tag *tag, char *cmd)
{
	char	*ret;
	char	*qstr;
	char	*before;
	char	*after;
	char	*tmp;

	qstr = ft_strchr(cmd, '$');
	if (!qstr)
		return (cmd);
	before = ft_substr(cmd, 0, qstr - cmd);
	after = ft_strdup2(qstr + 2);
	qstr = ft_itoa(update_status(tag->status));
	tmp = ft_strjoin2(before, qstr);
	free(before);
	free(qstr);
	ret = ft_strjoin2(tmp, after);
	free(tmp);
	free(after);
	free(cmd);
	return (ret);
}

/*
**	t_cmd	*cmd_lst;
**	int		i;
**	int		replace_type;
**
**	cmd_lst = tag->cmd;
**	while (cmd_lst != NULL)
**	{
**		i = 0;
**		while (i < cmd_lst->argc)
**		{
**			while ((replace_type = cmd_is_replace(cmd_lst->argv[i])) > -1)
**			{
**				if (replace_type == 0)
**					cmd_lst->argv[i] = replace_wavedash(tag, cmd_lst->argv[i]);
**				else if (replace_type == 1)
**					cmd_lst->argv[i] = replace_env(tag, cmd_lst->argv[i]);
**				else if (replace_type == 2)
**					cmd_lst->argv[i] = replace_dollar(tag, cmd_lst->argv[i]);
**				else if (replace_type == 3)
**					cmd_lst->argv[i] = replace_question(tag, cmd_lst->argv[i]);
**			}
**			i++;
**		}
**		cmd_lst = cmd_lst->next;
**	}
*/

void	cmd_replace(t_tag *tag)
{
	(void)tag;
}
