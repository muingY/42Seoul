/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:27:51 by seongcho          #+#    #+#             */
/*   Updated: 2021/04/29 14:23:36 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*create_env(t_env *prev_env, char *keystr, char *valstr)
{
	t_env	*new;

	if (!(new = malloc(sizeof(t_env))))
		return (NULL);
	new->key = ft_strdup2(keystr);
	new->value = ft_strdup2(valstr);
	new->next = NULL;
	if (prev_env)
		(prev_env)->next = new;
	if (!g_tag.env)
		g_tag.env = new;
	free(keystr);
	free(valstr);
	return (new);
}

int		set_env(char **envp, t_tag *tag)
{
	int			i;
	t_env		*cur;
	char		*keystr;
	char		*valstr;

	cur = tag->env;
	i = -1;
	while (envp[++i])
	{
		if (!envp[i])
			continue;
		valstr = ft_strchr(envp[i], '=');
		if (valstr)
		{
			keystr = ft_substr(envp[i], 0, valstr - envp[i]);
			valstr = ft_strdup2(valstr + 1);
		}
		else
		{
			keystr = ft_strdup2(envp[i]);
			valstr = ft_strdup("");
		}
		cur = create_env(cur, keystr, valstr);
	}
	return (0);
}

void	clear_env(t_env **env_head)
{
	t_env	*env;
	t_env	*nextenv;

	if (!*env_head)
		return ;
	env = *env_head;
	while (env)
	{
		nextenv = env->next;
		free(env->key);
		env->key = NULL;
		free(env->value);
		env->value = NULL;
		free(env);
		env = nextenv;
	}
	*env_head = NULL;
}

void	print_env(t_env *env)
{
	while (env)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}
