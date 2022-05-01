/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:53:01 by hyungyyo          #+#    #+#             */
/*   Updated: 2020/12/28 19:26:06 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t result;

	result = 0;
	while (*s != '\0')
	{
		result++;
		s++;
	}
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(ft_strlen(s) + 1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(result = (char*)malloc(s1_len + s2_len + 1)))
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	free(s1);
	ft_strlcat(result + s1_len, s2, s2_len + 1);
	return (result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t srclen;
	size_t i;

	srclen = (int)ft_strlen(src);
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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t srclen;
	size_t destlen;
	size_t i;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
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
