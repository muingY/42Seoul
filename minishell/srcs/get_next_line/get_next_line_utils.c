/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:53:01 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/07 02:19:56 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gstrlen(const char *s)
{
	size_t result;

	result = 0;
	if (!s || !*s)
		return (0);
	while (*s != '\0')
	{
		result++;
		s++;
	}
	return (result);
}

char	*ft_gstrdup(const char *s)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(ft_gstrlen(s) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_gstrjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_gstrdup(s2) : ft_gstrdup(s1));
	s1_len = ft_gstrlen(s1);
	s2_len = ft_gstrlen(s2);
	if (!(result = (char*)malloc(s1_len + s2_len + 1)))
		return (NULL);
	ft_gstrlcpy(result, s1, s1_len + 1);
	free(s1);
	ft_gstrlcat(result + s1_len, s2, s2_len + 1);
	return (result);
}

size_t	ft_gstrlcpy(char *dest, const char *src, size_t size)
{
	size_t srclen;
	size_t i;

	srclen = (int)ft_gstrlen(src);
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}

size_t	ft_gstrlcat(char *dest, const char *src, size_t size)
{
	size_t srclen;
	size_t destlen;
	size_t i;

	srclen = ft_gstrlen(src);
	destlen = ft_gstrlen(dest);
	i = 0;
	while (src[i] != '\0' && destlen + 1 + i < size)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	if (size < destlen)
		return (size + srclen);
	return (destlen + srclen);
}
