/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_canonical_util2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:22:31 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/06 12:23:56 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_canonical.h"

int		nc_atoi(const char *nptr)
{
	long long	result;
	int			neg_flag;

	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' ||
			*nptr == '\f' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	result = 0;
	neg_flag = 1;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			neg_flag *= -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (long long)(*nptr - '0');
		nptr++;
	}
	return ((int)(result * (long long)neg_flag));
}

int		nbr_length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	nc_get_cursor_pos(t_termcap *termcap)
{
	char	buf[255];
	int		ret;
	int		n[3];

	n[0] = 0;
	n[1] = 1;
	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	while (buf[n[1]])
	{
		if (buf[n[1]] >= '0' && buf[n[1]] <= '9')
		{
			if (n[0] == 0)
				termcap->row = nc_atoi(&buf[n[1]]) - 1;
			else
			{
				n[2] = nc_atoi(&buf[n[1]]);
				termcap->col = n[2] - 1;
			}
			n[0]++;
			n[1] += nbr_length(n[2]) - 1;
		}
		n[1]++;
	}
}

int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	nc_display(t_ncinput *nc, t_termcap *termcap, int input)
{
	if (nc->input_state == 0)
		return ;
	if (nc->input_state == 1)
	{
		if (nc->input != NULL)
		{
			if (termcap->col != 2)
				termcap->col--;
			tputs(tgoto(termcap->cm, termcap->col, termcap->row),
			1, putchar_tc);
			tputs(termcap->ce, 1, putchar_tc);
		}
		nc->input_state = -1;
	}
	else if (nc->input_state == -1)
	{
		termcap->col++;
		write(0, &input, 1);
	}
}
