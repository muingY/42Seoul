/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_canonical_util3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:39:03 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/09 15:04:15 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_canonical.h"

void	nc_sighelp(t_ncinput *nc, t_termcap *termcap)
{
	if (g_tag.sig_c == 1)
	{
		nc_clear_buf(nc, termcap);
		g_tag.sig_c = 0;
	}
}

void	nc_sub(int input, t_ncinput *ret,
t_termcap *termcap, int *is_continue)
{
	nc_sighelp(ret, termcap);
	nc_input_process(input, ret, is_continue, termcap);
	if (ret->input_state == 3 ||
	(input == 4479771 || input == 4414235))
	{
		ret->input_state = -1;
		return ;
	}
	nc_display(ret, termcap, input);
}

void	nc_clear_buf(t_ncinput *nc, t_termcap *termcap)
{
	(void)termcap;
	while (nc_strlen(nc->input) > 1 && nc->input != NULL)
	{
		nc->input = nc_strsub(nc->input);
		nc->input_state = 1;
		nc_display(nc, termcap, 0);
	}
	if (nc->input != NULL)
	{
		nc->input = nc_strsub(nc->input);
		nc->input_state = 1;
		nc_display(nc, termcap, 0);
	}
	nc_get_cursor_pos(termcap);
}

void	nc_write_buf(t_ncinput *nc, t_termcap *termcap, char *str)
{
	int	i;
	int	tmp;

	tmp = 1;
	i = 0;
	while (str[i] != '\0')
	{
		nc_input_process(str[i], nc, &tmp, termcap);
		nc_display(nc, termcap, str[i]);
		i++;
	}
}

void	nc_history(int *input, t_ncinput *ret, t_termcap *termcap)
{
	int hist_ret;

	if (*input == 4283163)
	{
		hist_ret = history_up(&g_tag.hist);
		if (hist_ret == 0)
		{
			ret->input_state = 3;
			return ;
		}
		nc_clear_buf(ret, termcap);
		nc_write_buf(ret, termcap, g_tag.hist.stack[g_tag.hist.i + 1]);
		ret->input_state = 3;
		return ;
	}
	hist_ret = history_down(&g_tag.hist);
	if (hist_ret == 0)
	{
		nc_clear_buf(ret, termcap);
		nc_history_sub(ret);
		return ;
	}
	nc_clear_buf(ret, termcap);
	nc_write_buf(ret, termcap, g_tag.hist.stack[g_tag.hist.i + 1]);
	ret->input_state = 3;
}
