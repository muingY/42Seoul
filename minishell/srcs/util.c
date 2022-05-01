/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:14:36 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/02 19:53:44 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_ppchar(char **ppchar)
{
	int i;

	i = 0;
	while (ppchar[i] != NULL)
	{
		free(ppchar[i]);
		i++;
	}
	free(ppchar);
}

char	*ft_strndup(char *s, int n)
{
	char	*result;
	size_t	i;

	if (n == 0)
		return (ft_strdup(""));
	result = (char*)malloc(n + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < (size_t)n)
	{
		result[i] = s[i];
		i++;
	}
	result[n] = '\0';
	return (result);
}

void	error(char *msg)
{
	printf("error_%s\n", msg);
	exit(-1);
}

t_bool	basic_split_istoken(char *input)
{
	char	*token[2];
	int		i;

	token[0] = ";";
	token[1] = "|";
	i = 0;
	while (i < 2)
	{
		if (ft_strncmp(input, token[i], ft_strlen(token[i])) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int		ft_str_quotation_i(char *str, int n)
{
	int i;

	if ((str[n] == '\"' || str[n] == '\'') && (ft_isalpha(str[n + 1])))
	{
		i = n + 1;
		while (str[i] && str[i] != ' ')
			i++;
		return (i);
	}
	return (1);
}
