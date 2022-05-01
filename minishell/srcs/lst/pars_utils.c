/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:40:21 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/08 23:55:38 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** enum e_pars {
**	NORM, SPCE, PIPE, DPIP, SEMC, DSEM,
**	SINQ, DOUQ, BSLA, DOLR,
**	RIGT, DRGT, LEFT}
*/

int		get_pars_type(char *s, int i)
{
	if (s[i] == ' ')
		return (SPCE);
	else if (s[i] == '|' && s[i + 1] == '|')
		return (DPIP);
	else if (s[i] == '|')
		return (PIPE);
	else if (s[i] == ';' && s[i + 1] == ';')
		return (DSEM);
	else if (s[i] == ';')
		return (SEMC);
	else if (s[i] == '\'')
		return (SINQ);
	else if (s[i] == '\"')
		return (DOUQ);
	else if (s[i] == '\\')
		return (BSLA);
	else if (s[i] == '$')
		return (DOLR);
	else if (s[i] == '>' && s[i + 1] == '>')
		return (DRGT);
	else if (s[i] == '>')
		return (RIGT);
	else if (s[i] == '<')
		return (LEFT);
	return (NORM);
}

/*
** //printf("pars[type=%d]%s\n", pars->type, pars->str);
*/

char	*get_parsed_input(t_tag *tag)
{
	char	*input;
	char	*tmp1;
	char	*tmp2;
	t_pars	*pars;

	input = NULL;
	pars = tag->pars;
	while (pars)
	{
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

void	print_pars(t_tag *tag, int i)
{
	t_pars	*pars;

	pars = tag->pars;
	while (pars)
	{
		if (i == 0)
			ft_putstr_fd(pars->str, 2);
		else if (i == 1 && pars->type != SPCE)
			printf("[type=%d][%s][len=%d]\n", pars->type, pars->str,
					(int)ft_gstrlen(pars->str));
		pars = pars->next;
		if (i == 0 && pars && (pars->prev->type >= PIPE || pars->type >= PIPE))
			ft_putchar_fd(' ', 2);
	}
	if (i == 0)
		ft_putchar_fd('\n', 2);
}

int		add_pars(t_tag *tag, char *str, int type)
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
	if (!tag->pars)
	{
		new->prev = NULL;
		new->next = NULL;
		tag->pars = new;
		return (0);
	}
	last = tag->pars;
	while (last && last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = NULL;
	return (0);
}

void	clear_pars(t_tag *tag)
{
	t_pars	*pars;
	t_pars	*nextpars;

	if (!tag->pars)
		return ;
	pars = tag->pars;
	while (pars)
	{
		nextpars = pars->next;
		free(pars->str);
		pars->prev = NULL;
		pars->next = NULL;
		free(pars);
		pars = nextpars;
	}
	tag->pars = NULL;
	if (tag->parsed && *(tag->parsed))
		free(tag->parsed);
}
