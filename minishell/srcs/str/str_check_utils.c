/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:44:16 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/08 22:52:12 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strchr2(char *str, char c1, char c2, int *is_pipe)
{
	int i;

	i = 0;
	*is_pipe = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c1 && isnotsent(str, i))
		{
			*is_pipe = 1;
			return (char *)(str + i);
		}
		else if (str[i] == c2 && isnotsent(str, i))
			return (char *)(str + i);
		i++;
	}
	if (c1 == '\0' && c2 == '\0')
		return (char *)(str + i);
	return (NULL);
}

t_bool	is_numeric_argument(char *arg)
{
	int i;

	if (!(arg[0] == '-' || arg[0] == '+' || ft_isdigit(arg[0])))
		return (FALSE);
	i = 0;
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (FALSE);
	return (TRUE);
}

t_bool	is_valid_env_str(char *str, t_bool num_start, t_bool key_only)
{
	int		i;

	if (!str)
		return (FALSE);
	if (!num_start && ft_isdigit(str[0]))
		return (FALSE);
	i = -1;
	while (str[++i])
	{
		if (key_only && str[i] == '=')
			break ;
		if (!(str[i] == '_' || ft_isalnum(str[i])))
			return (FALSE);
	}
	return (TRUE);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (const unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;
	while ((*tmp_s1 != '\0' || *tmp_s2 != '\0'))
	{
		if (*tmp_s1 != *tmp_s2)
			return (*tmp_s1 - *tmp_s2);
		tmp_s1++;
		tmp_s2++;
		i++;
	}
	return (0);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup2(s2));
	else if (!s2)
		return (ft_strdup2(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
