/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 21:53:32 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/09 00:04:15 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_complex_pars_len(char *s, int i, int type)
{
	int		len;

	len = 1;
	while (s[i + (++len) - 1])
	{
		if (type == SINQ && s[i + len - 1] == '\'')
			return (len);
		else if (type == DOUQ && s[i + len - 1] == '\"' &&
				s[i + len - 2] != '\\')
			return (len);
		else if (type == DOLR)
		{
			if (len == 2 && (ft_isdigit(s[i + len - 1]) ||
				s[i + len - 1] == '?'))
				return (len);
			else if (!(ft_isalnum(s[i + len - 1]) && s[i + len - 1] != '_'))
				return (len - 1);
		}
		else if (type == NORM && get_pars_type(s, i + len - 1) != NORM)
			return (len - 1);
	}
	return (len - 1);
}

int		get_pars_len(char *s, int i, int type)
{
	if (type == SPCE || type == PIPE || type == SEMC ||
		type == RIGT || type == LEFT)
		return (1);
	else if (type == BSLA && (!s[i + 1] || s[i + 1] == ' '))
		return (1);
	else if (type == DPIP || type == DSEM || type == BSLA || type == DRGT)
		return (2);
	else if (type == SINQ || type == DOUQ || type == DOLR || type == NORM)
		return (get_complex_pars_len(s, i, type));
	return (0);
}

void	replace_dolr_str_part2(t_pars *pars, char *str,
								int stype, int slen)
{
	char	*val;

	if (stype == DOLR)
		val = get_env_value(g_tag.env, (str + 1));
	if (stype == DOLR && (slen == 1 ||
		(slen == 2 && ft_isdigit(str[1])) || !val[0]))
	{
		free(pars->str);
		pars->str = ft_strdup2(" ");
		pars->type = SPCE;
		return ;
	}
	if (stype == DOLR && val[0])
	{
		free(pars->str);
		pars->str = ft_strdup2(val);
		pars->type = NORM;
		return ;
	}
}

void	replace_dolr_str(t_pars *pars, char *str, int stype, int slen)
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
		pars->str = ft_strdup2("'$'");
		pars->type = SINQ;
		return ;
	}
	replace_dolr_str_part2(pars, str, stype, slen);
}

void	replace_bsla_str(t_pars *pars, char *str, int stype, int slen)
{
	char *tmp;

	if (stype == NORM && slen == 1 && str[0] == '~' && (!pars->next ||
		(pars->next->type > DOLR || pars->next->type == SPCE)))
	{
		free(pars->str);
		tmp = get_env_value(g_tag.env, "HOME");
		pars->str = ft_strdup2(tmp);
	}
	if (stype == BSLA && slen == 2)
	{
		str[0] = '\'';
		tmp = ft_strjoin2(str, "'");
		free(pars->str);
		pars->str = tmp;
		pars->type = SINQ;
	}
	else if (stype == BSLA && slen == 1)
	{
		free(pars->str);
		pars->str = ft_strdup2(" ");
		pars->type = SPCE;
	}
}
