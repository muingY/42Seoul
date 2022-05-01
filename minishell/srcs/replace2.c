/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:47:30 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/04/29 12:59:07 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*replace_dollar(t_tag *tag, char *cmd)
{
	char	*ret;
	int		len;
	int		i;
	int		ii;

	(void)tag;
	len = ft_strlen(cmd) - 1;
	ret = (char*)malloc(len);
	ret[len - 1] = '\0';
	i = 0;
	ii = 0;
	while (i < len - 1 && cmd[i] != '$')
		ret[i++] = cmd[ii++];
	ii += 2;
	while (i < len - 1)
		ret[i++] = cmd[ii++];
	free(cmd);
	return (ret);
}

int		get_envlen(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '$' && ft_isalnum(str[i]) == 1)
		i++;
	return (i);
}

void	replace_env_sub(char *ret, char *cmd, char *env, int len)
{
	int		i;
	int		ii;

	i = 0;
	while (cmd[i] != '$' && i < len - 1)
	{
		ret[i] = cmd[i];
		i++;
	}
	ii = i;
	cmd = cmd + i + 1;
	cmd += get_envlen(cmd);
	while (i < len - 1 && env[i - ii])
	{
		ret[i] = env[i - ii];
		i++;
	}
	while (i < len - 1)
	{
		ret[i] = *(cmd++);
		i++;
	}
}

char	*replace_env(t_tag *tag, char *cmd)
{
	char	*ret;
	char	*env_key;
	char	*env;
	int		len;
	int		i;

	i = 0;
	while (cmd[i] && cmd[i] != '$')
		i++;
	env_key = ft_strndup(cmd + i + 1, get_envlen(cmd + i + 1));
	env = get_env_value(tag->env, env_key);
	free(env_key);
	len = sizeof(char) * (i + 1 + ft_strlen(env) +
	ft_strlen(cmd + i + 1 + get_envlen(cmd + i + 1)));
	ret = (char*)malloc(len);
	ret[len - 1] = '\0';
	replace_env_sub(ret, cmd, env, len);
	free(cmd);
	return (ret);
}

void	replace_null(void)
{
	printf("exit\n");
	exit(0);
}
