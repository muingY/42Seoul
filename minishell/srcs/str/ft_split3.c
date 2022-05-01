/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:03:23 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/09 12:43:34 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_issep(char c, char *sep)
{
	int		i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(char const *s, char *sep)
{
	int i;
	int count;
	int cflag;

	if (!s || !*s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (ft_issep(s[i], sep) && s[i])
			i++;
		cflag = 1;
		while (!ft_issep(s[i], sep) && s[i])
		{
			if (cflag)
				count++;
			cflag = 0;
			i++;
		}
	}
	return (count);
}

static char	**ft_free(char **result, int idx)
{
	while (idx > 0)
	{
		free(result[idx]);
		--idx;
	}
	free(result);
	return (NULL);
}

static int	ft_get_start_len(char const *s, char *sep, int *i, int *start)
{
	int		len;

	while (ft_issep(s[*i], sep) && s[*i])
		(*i)++;
	*start = -1;
	len = 0;
	while (!ft_issep(s[*i], sep) && s[*i])
	{
		if (*start == -1)
			*start = *i;
		len++;
		(*i)++;
	}
	return (len);
}

char		**ft_split3(char const *s, char *sep, int *ac)
{
	int		i;
	int		idx;
	int		start;
	int		len;
	char	**result;

	*ac = ft_count(s, sep);
	if (!(result = (char **)malloc((*ac + 1) * sizeof(char *))))
		return (NULL);
	idx = 0;
	i = 0;
	while (s && s[i] && *ac > 0)
	{
		len = ft_get_start_len(s, sep, &i, &start);
		if (len > 0)
		{
			result[idx] = ft_substr(s, start, len);
			if (!result[idx])
				return (ft_free(result, idx));
			idx++;
		}
	}
	result[idx] = 0;
	return (result);
}
