/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sub_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:40:21 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/09 00:25:58 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_bsla_str_sub(t_pars *pars, char *str, int stype, int slen)
{
	char	*tmp;
	char	*tmp2;
	char	*val;

	if (stype == BSLA && slen == 2 && (str[1] == '\\' || str[1] == '$'))
	{
		tmp = ft_substr(str, 1, 1);
		free(pars->str);
		pars->str = tmp;
		pars->type = NORM;
		return ;
	}
	if (stype == SINQ && slen > 3 && str[1] == '$')
	{
		tmp = ft_substr(str, 2, slen - 3);
		val = get_env_value(g_tag.env, tmp);
		tmp2 = ft_strjoin2("'", val);
		free(tmp);
		tmp = ft_strjoin2(tmp2, "'");
		free(tmp2);
		free(pars->str);
		pars->str = tmp;
	}
}

void	replace_dolr_str_sub_part2(t_pars *pars, char *str,
									int stype, int slen)
{
	char	*val;

	if (stype == DOLR)
		val = get_env_value(g_tag.env, (str + 1));
	if (stype == DOLR && (slen == 1 ||
		(slen == 2 && ft_isdigit(str[1])) || !val[0]))
	{
		free(pars->str);
		pars->str = ft_strdup2("");
		pars->type = NORM;
		return ;
	}
	else if (stype == DOLR && val[0])
	{
		free(pars->str);
		pars->str = ft_strdup2(val);
		pars->type = NORM;
		return ;
	}
}

void	replace_dolr_str_sub(t_pars *pars, char *str, int stype, int slen)
{
	if (stype == DOLR && slen == 2 && str[1] == '?')
	{
		free(pars->str);
		pars->str = ft_itoa(g_tag.status);
		pars->type = NORM;
		return ;
	}
	if (stype == DOLR && slen == 1 && (!pars->next || (pars->next &&
			(pars->next->type == SPCE || pars->next->type >= PIPE))))
	{
		free(pars->str);
		pars->str = ft_strdup2("$");
		pars->type = NORM;
		return ;
	}
	replace_dolr_str_sub_part2(pars, str, stype, slen);
}

char	*get_parsed_sub_input_douq(t_tag *tag, int flag)
{
	char	*input;
	char	*tmp1;
	t_pars	*pars;
	int		slen;

	pars = g_tag.pars_sub;
	while (pars)
	{
		slen = ft_strlen(pars->str);
		replace_dolr_str_sub(pars, pars->str, pars->type, slen);
		replace_bsla_str_sub(pars, pars->str, pars->type, slen);
		pars = pars->next;
	}
	input = get_parsed_sub_input(tag, 0);
	if (flag)
	{
		tmp1 = ft_strjoin2("\"", input);
		free(input);
		input = ft_strjoin2(tmp1, "\"");
		free(tmp1);
	}
	return (input);
}

void	print_pars_sub(t_tag *tag, int i)
{
	t_pars	*pars;

	pars = tag->pars_sub;
	while (pars)
	{
		if (i == 0)
			ft_putstr_fd(pars->str, 2);
		else if (i == 1 && pars->type != SPCE)
			printf("[type=%d][%s][len=%d]\n", pars->type, pars->str,
					(int)ft_strlen(pars->str));
		pars = pars->next;
		if (i == 0 && pars && (pars->prev->type >= PIPE || pars->type >= PIPE))
			ft_putchar_fd(' ', 2);
	}
	if (i == 0)
		ft_putchar_fd('\n', 2);
}
