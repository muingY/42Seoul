/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_keyvalue_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:43:48 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/06 18:57:09 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*get_env_key(t_env *env, char *key)
{
	if (!env || !key)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*get_env_value(t_env *env, char *key)
{
	t_env	*env_key;

	if (!env || !key)
		return ("");
	env_key = get_env_key(env, key);
	if (env_key)
		return (env_key->value);
	return ("");
}

int		set_env_value(t_env *env, char *key, char *value)
{
	t_env	*env_key;
	t_env	*prev_env;

	if (!env || !key || !value)
		return (1);
	env_key = get_env_key(env, key);
	if (env_key)
	{
		free(env_key->value);
		env_key->value = ft_strdup2(value);
		free(key);
		free(value);
		return (0);
	}
	prev_env = env;
	while (prev_env->next)
		prev_env = prev_env->next;
	prev_env = create_env(prev_env, key, value);
	if (prev_env)
		return (0);
	return (1);
}

int		del_env_key(t_env *env, char *key)
{
	t_env	*env_key;
	t_env	*prev_env;

	if (!env || !key)
		return (1);
	env_key = get_env_key(env, key);
	if (!env_key)
		return (1);
	prev_env = NULL;
	while (env)
	{
		if (env->next && ft_strcmp(env->next->key, key) == 0)
			prev_env = env;
		env = env->next;
	}
	if (!prev_env)
		g_tag.env = env_key->next;
	else
		prev_env->next = env_key->next;
	free(env_key->key);
	free(env_key->value);
	free(env_key);
	return (0);
}
