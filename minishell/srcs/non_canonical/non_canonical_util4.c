/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_canonical_util4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:41:51 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/09 14:42:45 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_canonical.h"

void	nc_history_sub(t_ncinput *ret)
{
	g_tag.hist.i = g_tag.hist.top;
	ret->input_state = 3;
}
