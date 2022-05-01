/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:55:42 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/05 12:14:03 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_sigint(int signo)
{
	(void)signo;
	g_tag.is_sigon = TRUE;
	if (g_tag.is_cmd == 1)
	{
		ft_putstr_fd("\n> ", 2);
		g_tag.sig_c = 1;
	}
	else
	{
		printf("\n");
		g_tag.status = 130;
	}
}

void	signal_sigquit(int signo)
{
	(void)signo;
	g_tag.is_sigon = TRUE;
	if (g_tag.is_cmd == 0)
	{
		printf("Quit: 3\n");
		g_tag.status = 131;
	}
}

void	init_signal(void)
{
	signal(SIGINT, signal_sigint);
	signal(SIGQUIT, signal_sigquit);
}
