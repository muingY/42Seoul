/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 21:53:32 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/09 13:17:39 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_pars(char *input, int sub)
{
	int		i;
	int		len;
	int		type;
	char	*str;

	if (sub)
		clear_pars_sub(&g_tag);
	else
		clear_pars(&g_tag);
	i = 0;
	while (input[i] && i < (int)ft_strlen(input))
	{
		type = get_pars_type(input, i);
		len = get_pars_len(input, i, type);
		str = ft_substr(input, i, len);
		if (sub)
			add_pars_sub(&g_tag, str, type);
		else
			add_pars(&g_tag, str, type);
		free(str);
		i = i + len;
	}
	return (0);
}

int		is_bad_qend(char *s, int ty, int l)
{
	int		cnt_bsla;
	int		i;

	if ((ty == SINQ || ty == DOUQ) && l == 1)
		return (1);
	if (ty == SINQ && l >= 2 && s[l - 1] != '\'')
		return (1);
	if (ty == DOUQ && l >= 2 && s[l - 1] != '\"')
		return (1);
	if (ty == SINQ && l >= 2 && s[l - 1] == '\'')
		return (0);
	if (ty == DOUQ && l >= 2 && s[l - 1] == '\"' && s[l - 2] != '\\')
		return (0);
	i = l - 1;
	cnt_bsla = 0;
	while (--i > 0)
		if (s[i] == '\\')
			cnt_bsla++;
	if (ty == SINQ && l >= 2 && s[l - 1] == '\'' && cnt_bsla > 0)
		return (cnt_bsla % 2);
	if (ty == DOUQ && l >= 2 && s[l - 1] == '\"' && cnt_bsla > 0)
		return (cnt_bsla % 2);
	return (0);
}

void	replace_in_douq_str(t_pars *pars, char *str,
							int stype, int slen)
{
	char	*str_sub;

	(void)stype;
	str_sub = ft_substr(str, 1, slen - 2);
	free(pars->str);
	pars->str = str_sub;
	get_pars(str_sub, 1);
	free(str_sub);
	str_sub = get_parsed_sub_input_douq(&g_tag, 1);
	pars->str = str_sub;
}

/*
**		str_sub = ft_substr(str, 1, slen - 2);
**		free(pars->str);
**		pars->str = str_sub;
**		get_pars(str_sub, 1);
**		free(str_sub);
**		str_sub = get_parsed_sub_input_douq(&g_tag, 1);
**		pars->str = str_sub;
*/

char	*check_basicstr(t_pars *pars, char *str, int stype)
{
	int		slen;

	slen = ft_strlen(str);
	if (stype == SINQ && is_bad_qend(str, stype, slen))
		return ("\'");
	if (stype == DOUQ && is_bad_qend(str, stype, slen))
		return ("\"");
	if (stype == DSEM || stype == DPIP)
		return (str);
	if (stype == PIPE && (!pars->prev || !pars->next))
		return (str);
	if ((stype == RIGT || stype == DRGT || stype == LEFT) &&
		((!pars->next || pars->next->type >= PIPE) ||
			(is_empty_operation(pars, stype))))
		return (str);
	if (stype == SEMC && is_empty_operation(pars, stype))
		return (";");
	if (stype == DOUQ)
		replace_in_douq_str(pars, str, stype, slen);
	replace_dolr_str(pars, str, stype, slen);
	replace_bsla_str(pars, str, stype, slen);
	return (NULL);
}

/*
**	printf("---\n");
**	print_pars(&g_tag, 1);
**	printf("[parsed]%s\n", g_tag.parsed);
**	printf("---\n");
*/

int		check_basic_syntax_error(char *input)
{
	t_pars	*pars;
	char	*estr;

	if (!input || !*input)
		return (1);
	get_pars(input, 0);
	pars = g_tag.pars;
	while (pars)
	{
		estr = check_basicstr(pars, pars->str, pars->type);
		if (estr)
		{
			g_tag.parsed = ft_strdup2("err");
			g_tag.input = ft_strdup2(g_tag.parsed);
			return (returnf("bash0: syntax error near unexpected token ",
							2, estr, 258));
		}
		pars = pars->next;
	}
	g_tag.parsed = get_parsed_input(&g_tag);
	g_tag.input = ft_strdup2(g_tag.parsed);
	return (0);
}
