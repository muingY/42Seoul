/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:12:53 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/05 13:15:33 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_set(char c, char *set)
{
	int		i;

	if (!set)
		return (0);
	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

static int	get_word_n2(char const *s, char *set)
{
	int i;
	int count;
	int cflag;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (is_set(s[i], set) && s[i])
			i++;
		cflag = 1;
		while (!is_set(s[i], set) && s[i])
		{
			if (cflag && isnotsent((char*)s, i) == TRUE)
				count++;
			cflag = 0;
			i++;
		}
	}
	return (count);
}

void		ft_strndup_without_sub(char *str, int *n,
t_bool *is_quontion, int len)
{
	n[1] = 0;
	n[0] = 0;
	*is_quontion = FALSE;
	while (n[1] < len)
	{
		if (str[n[1]] == '\"' || str[n[1]] == '\'')
		{
			if (str[n[1]] == '\"')
				n[0] = 1;
			else if (str[n[1]] == '\'')
				n[0] = 2;
		}
		n[1]++;
		if (n[0] > 0)
			break ;
	}
	while (n[0] > 0 && n[1] < len)
	{
		if (n[0] == 1 && str[n[1]] == '\"')
			*is_quontion = TRUE;
		else if (n[0] == 2 && str[n[1]] == '\'')
			*is_quontion = TRUE;
		n[1]++;
	}
}

char		*ft_strndup_without_quotation(char *str,
int len, int *ii)
{
	int		n[3];
	t_bool	is_quontion;

	ft_strndup_without_sub(str, n, &is_quontion, len);
	if (is_quontion == FALSE && n[0] > 0)
	{
		n[2] = n[1];
		while (str[n[1]])
		{
			if ((n[0] == 1 && str[n[1]] == '\"')
			|| (n[0] == 2 && str[n[1]] == '\''))
				is_quontion = TRUE;
			if (is_quontion == TRUE)
				break ;
			n[1]++;
		}
		if (is_quontion == TRUE)
		{
			len = n[1] + ft_str_quotation_i(str, n[1]);
			*ii += n[1] - n[2] + ft_str_quotation_i(str, n[1]);
		}
	}
	if (is_quontion == TRUE)
		return (ft_strndup(str, len));
	return (ft_strndup(str, len));
}

char		**ft_split2(char const *str, char *set, int *ac)
{
	char	**arr;
	char	*tmp;
	int		i[3];

	*ac = get_word_n2((char *)str, set);
	arr = (char **)malloc(sizeof(char *) * (*ac + 1));
	i[0] = 0;
	i[1] = 0;
	while (i[1] < (int)ft_strlen(str) && str[i[1]])
	{
		if (!is_set(str[i[1]], set) && (i[2] = 0) + 1)
		{
			tmp = (char*)str + i[1];
			while (str[i[1]] != '\0' && (i[2]++ + 1))
				if (is_set(str[++i[1]], set))
					break ;
			arr[i[0]++] = ft_strndup_without_quotation(tmp, i[2], &i[1]);
			arr[i[0] - 1] = replace_sent(arr[i[0] - 1],
			need_replace(arr[i[0] - 1]));
			continue;
		}
		i[1]++;
	}
	arr[i[0]] = NULL;
	return (arr);
}
