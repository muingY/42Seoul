/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:53:22 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/05 13:18:16 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool		iscap(char *str, int i, int type)
{
	int ii;
	int n;
	int n2;

	ii = i - 1;
	n = 0;
	while (ii >= 0)
	{
		if ((type == 1 && str[ii] == '\"') || (type == 2 && str[ii] == '\''))
			n = 1;
		ii--;
	}
	ii = i + 1;
	n2 = 0;
	while (ii < (int)ft_strlen(str))
	{
		if ((type == 1 && str[ii] == '\"') || (type == 2 && str[ii] == '\''))
			n2 = 1;
		ii++;
	}
	if (n == 1 && n2 == 1)
		return (TRUE);
	return (FALSE);
}

void		need_replace_del_sub(char *str, int i, int *type)
{
	*type = 1;
	if (str[i] == '\"')
		*type = 2;
}

t_bool		need_replace_del(char *str, int i)
{
	int		n[2];

	need_replace_del_sub(str, i, &n[1]);
	if (iscap(str, i, n[1]) == TRUE)
		return (FALSE);
	else
	{
		n[0] = i - 1;
		while (n[0] >= 0)
		{
			if ((n[1] == 1 && str[n[0]] == '\'')
			|| (n[1] == 2 && str[n[0]] == '\"'))
				return (TRUE);
			n[0]--;
		}
		n[0] = i + 1;
		while (n[0] < (int)ft_strlen(str))
		{
			if ((n[1] == 1 && str[n[0]] == '\'')
			|| (n[1] == 2 && str[n[0]] == '\"'))
				return (TRUE);
			n[0]++;
		}
	}
	return (FALSE);
}

char		*need_replace(char *str)
{
	t_bool	isneed;
	char	*ret;
	int		n[2];

	isneed = FALSE;
	n[0] = ft_strlen(str) + 1;
	ret = (char*)malloc(sizeof(char) * n[0]);
	ret[n[0] - 1] = '\0';
	n[1] = 0;
	while (str[n[1]])
	{
		if ((str[n[1]] == '\'' || str[n[1]] == '\"') ?
		(need_replace_del(str, n[1]) == TRUE) : FALSE)
		{
			isneed = TRUE;
			ret[n[1]] = '!';
		}
		else
			ret[n[1]] = ' ';
		n[1]++;
	}
	if (isneed == TRUE)
		return (ret);
	free(ret);
	return (NULL);
}

char		*replace_sent(char *str, char *remove_i)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (remove_i == NULL)
		return (str);
	ret = (char*)malloc(ft_strlen(str) + 1);
	tmp = ret;
	i = 0;
	while (str[i])
	{
		if (remove_i[i] != '!')
		{
			*tmp = str[i];
			tmp++;
		}
		i++;
	}
	*tmp = '\0';
	free(str);
	free(remove_i);
	return (ret);
}
