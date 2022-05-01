/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_canonical_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:33:36 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/05 15:37:49 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_canonical.h"

int			nc_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char		*nc_stradd(char *str, char c)
{
	char	*ret;
	int		len;
	int		i;

	len = nc_strlen(str) + 2;
	ret = (char*)malloc(sizeof(char) * len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len - 2)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i++] = c;
	ret[i] = '\0';
	if (str != NULL)
		free(str);
	return (ret);
}

char		*nc_strsub(char *str)
{
	char	*ret;
	int		len;
	int		i;

	len = nc_strlen(str);
	i = 0;
	if (len == 0)
	{
		free(str);
		return (NULL);
	}
	ret = (char*)malloc(len);
	if (ret == NULL)
		return (NULL);
	while (i < len - 1)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	if (str != NULL)
		free(str);
	return (ret);
}

int			nc_isstr(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	else if (c == 9 || (c <= 13 && c >= 11))
		return (1);
	else if (c == 32)
		return (1);
	return (0);
}

t_ncinput	nc_ctrld(t_ncinput *nc)
{
	if (nc->input != NULL)
	{
		free(nc->input);
		nc->input = NULL;
	}
	nc->input = nc_stradd(nc->input, 'e');
	nc->input = nc_stradd(nc->input, 'x');
	nc->input = nc_stradd(nc->input, 'i');
	nc->input = nc_stradd(nc->input, 't');
	return (*nc);
}
