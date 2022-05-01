/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:09:14 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/13 12:44:33 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_strlen(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	ret = malloc(ft_strlen(str) + 1);
	if (ret == NULL)
		error("ft_strdup malloc fail", -1);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(s1_len + s2_len + 1);
	if (ret == NULL)
		error("ft_strjoin malloc fail", -1);
	i = 0;
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		ret[i] = s2[i - s1_len];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		gnl_sub(char *data, int ret, char **line)
{
	if (ret >= 0)
	{
		*line = ft_strdup(data);
	}
	free(data);
	return (ret);
}

int		get_next_line(char **line)
{
	char	*data;
	char	buf[2];
	char	*tmp;
	int		rret;

	data = ft_strdup("");
	while (1)
	{
		rret = read(0, buf, 1);
		if (rret == -1)
			return (gnl_sub(data, -1, line));
		if (rret == 0)
			return (gnl_sub(data, 0, line));
		if (buf[0] == '\n')
			return (gnl_sub(data, 1, line));
		tmp = ft_strjoin(data, buf);
		free(data);
		data = tmp;
	}
	return (0);
}
