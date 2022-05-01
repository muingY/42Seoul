/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:05:38 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/22 18:34:34 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philohead.h"

int		ft_atoi(const char *nptr)
{
	long long	result;
	int			neg_flag;

	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' ||
			*nptr == '\f' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	result = 0;
	neg_flag = 1;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			neg_flag *= -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (long long)(*nptr - '0');
		nptr++;
	}
	return ((int)(result * (long long)neg_flag));
}

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
	while (i < ft_strlen(s))
	{
		result[i] = s[i];
		i++;
	}
	result[ft_strlen(s)] = '\0';
	return (result);
}

int		error(int ret, char *errmsg)
{
	printf("%s\n", errmsg);
	return (ret);
}

void	error_exit(int ret, char *errmsg)
{
	printf("%s\n", errmsg);
	exit(ret);
}
