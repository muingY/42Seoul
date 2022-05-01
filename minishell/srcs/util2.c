/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:30:55 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/04/30 12:23:41 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
	|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	split_cmdraw_n(char *str)
{
	int n;

	n = 0;
	if (basic_split_istoken(str) == TRUE)
		return (1);
	while (*str != '\0')
	{
		if (ft_isspace(*str) == 0)
		{
			n++;
			while (*str && ft_isspace(*str) == 0)
			{
				str++;
				continue ;
			}
		}
		str++;
	}
	return (n);
}

char		*split_cmdraw_dup(char *cmdraw, int *skiplen)
{
	int len;

	len = 0;
	while (*cmdraw == ' ' || *cmdraw == '\f' || *cmdraw == '\n'
	|| *cmdraw == '\r' || *cmdraw == '\t' || *cmdraw == '\v')
	{
		cmdraw++;
		*skiplen += 1;
	}
	while (cmdraw[len] && ft_isspace(cmdraw[len]) == 0)
		len++;
	return (ft_strndup(cmdraw, len));
}

char		**split_cmdraw(char *cmdraw)
{
	char	**ret;
	int		n;
	int		i;
	int		skiplen;

	n = split_cmdraw_n(cmdraw);
	ret = (char**)malloc(sizeof(char*) * (n + 1));
	ret[n] = NULL;
	i = 0;
	while (i < n)
	{
		skiplen = 0;
		ret[i] = split_cmdraw_dup(cmdraw, &skiplen);
		cmdraw += skiplen + ft_strlen(ret[i]);
		i++;
	}
	return (ret);
}

t_bool		replace_lock(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			n++;
		i++;
	}
	if (n % 2 == 0 && n > 0)
		return (TRUE);
	return (FALSE);
}
