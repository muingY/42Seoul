/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sub_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:40:21 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/09 00:24:04 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_bsla_douq(char *s)
{
	char	c;
	int		w;
	int		r;

	c = '\\';
	w = 0;
	r = 0;
	while (s[r])
	{
		if (!(s[r] == c && s[r + 1] && s[r + 1] == '\"'))
		{
			s[w++] = s[r];
		}
		r++;
	}
	s[w] = 0;
}

void	remove_quote_in_the_edge(t_tag *tag, t_pars *pars)
{
	char *tmp1;

	(void)*tag;
	tmp1 = ft_substr(pars->str, 1, ft_strlen(pars->str) - 2);
	if (pars->type == DOUQ)
		replace_bsla_douq(tmp1);
	free(pars->str);
	pars->str = tmp1;
}

/*
**			tmp1 = ft_substr(pars->str, 1, ft_strlen(pars->str) - 2);
**			if (pars->type == DOUQ)
**				replace_bsla_douq(tmp1);
**			free(pars->str);
**			pars->str = tmp1;
*/

char	*get_parsed_sub_input(t_tag *tag, int no_quote)
{
	char	*input;
	char	*tmp1;
	char	*tmp2;
	t_pars	*pars;

	input = NULL;
	pars = tag->pars_sub;
	while (pars)
	{
		if (no_quote && (pars->type == DOUQ || pars->type == SINQ))
			remove_quote_in_the_edge(tag, pars);
		tmp1 = ft_strdup2(pars->str);
		tmp2 = ft_strjoin2(input, tmp1);
		free(tmp1);
		free(input);
		input = tmp2;
		pars = pars->next;
		if (pars && (pars->prev->type >= PIPE || pars->type >= PIPE))
		{
			tmp1 = ft_strjoin2(input, " ");
			free(input);
			input = tmp1;
		}
	}
	return (input);
}

int		add_pars_sub(t_tag *tag, char *str, int type)
{
	t_pars *new;
	t_pars *last;

	if (!str || !*str)
		return (1);
	if (!(new = (t_pars *)malloc(sizeof(t_pars))))
		return (1);
	if (!(new->str = ft_strdup2(str)))
		return (1);
	new->type = type;
	if (!tag->pars_sub)
	{
		new->prev = NULL;
		new->next = NULL;
		tag->pars_sub = new;
		return (0);
	}
	last = tag->pars_sub;
	while (last && last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = NULL;
	return (0);
}

void	clear_pars_sub(t_tag *tag)
{
	t_pars	*pars;
	t_pars	*nextpars;

	if (!tag->pars_sub)
		return ;
	pars = tag->pars_sub;
	while (pars)
	{
		nextpars = pars->next;
		free(pars->str);
		pars->prev = NULL;
		pars->next = NULL;
		free(pars);
		pars = nextpars;
	}
	tag->pars_sub = NULL;
}
