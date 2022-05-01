/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:24:19 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/08 22:38:33 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_envstr(t_env *env)
{
	char	*ret;
	char	*tmp1;
	char	*tmp2;

	if (ft_strcmp(env->value, "") == 0)
		ret = ft_strdup2(env->key);
	else
	{
		tmp1 = ft_strjoin2(env->key, "=\"");
		tmp2 = ft_strjoin2(env->value, "\"");
		ret = ft_strjoin2(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
	}
	return (ret);
}

int		ft_env(t_tag *tag, t_cmd *cmd, t_env *env)
{
	(void)tag;
	(void)cmd;
	print_env(env);
	return (0);
}

int		get_num_of_env(t_env *env)
{
	int len;

	len = 0;
	while (env)
	{
		len++;
		env = env->next;
	}
	return (len);
}
