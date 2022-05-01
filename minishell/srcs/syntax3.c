/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:59:10 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/09 13:17:48 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_empty_operation(t_pars *pars, int stype)
{
	t_pars	*pars_prev;

	if (pars->type != stype)
		return (0);
	if (!pars->prev)
		return (1);
	pars_prev = pars->prev;
	while (pars_prev && pars_prev->type == SPCE)
		pars_prev = pars_prev->prev;
	if (!pars_prev || pars_prev->type == stype)
		return (1);
	if ((stype == RIGT || stype == DRGT || stype == LEFT) &&
		(pars_prev->type == RIGT || pars_prev->type == DRGT ||
		pars_prev->type == LEFT))
		return (1);
	return (0);
}
