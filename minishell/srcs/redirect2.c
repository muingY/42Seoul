/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 02:39:59 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/02 19:37:40 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_redirect(t_tag *tag)
{
	if (tag->redirect0 > 0)
		close(tag->redirect0);
	tag->redirect0 = 0;
	if (tag->redirect1 > 0)
		close(tag->redirect1);
	tag->redirect1 = 0;
}

void	operate_pipe(t_tag *tag, t_cmd *cmd, int flag)
{
	if (flag == 0 && cmd->is_pipe)
		pipe(cmd->fd);
	else if (flag == 1)
	{
		if (cmd->is_pipe)
			dup2(cmd->fd[1], 1);
		if (cmd->prev && cmd->prev->is_pipe)
			dup2(cmd->prev->fd[0], 0);
	}
	else if (flag == 2)
	{
		if (cmd->is_pipe)
		{
			close(cmd->fd[1]);
			if (!cmd->next)
				close(cmd->fd[0]);
		}
		if (cmd->prev && cmd->prev->is_pipe)
			close(cmd->prev->fd[0]);
		close_redirect(tag);
	}
}

void	init_redirect(t_tag *tag)
{
	if (tag->redirect0 != 0 && tag->redirect0 != -1)
		close(tag->redirect0);
	tag->redirect0 = 0;
	if (tag->redirect1 != 0 && tag->redirect1 != -1)
		close(tag->redirect1);
	tag->redirect1 = 0;
}

int		get_arg_type(char *arg)
{
	if (!arg || !*arg)
		return (-1);
	else if (ft_strcmp(arg, "<") == 0)
		return (0);
	else if (ft_strcmp(arg, ">") == 0)
		return (1);
	else if (ft_strcmp(arg, ">>") == 0)
		return (2);
	else
		return (3);
}

int		get_redirect_fd(t_tag *tag, char *arg1, char *arg2)
{
	int a1type;
	int a2type;
	int opentype;

	a1type = get_arg_type(arg1);
	if (a1type < 0 || a1type > 2)
		return (0);
	a2type = get_arg_type(arg2);
	if (a2type == -1)
		return (returnf2(248, "newline"));
	else if (a2type < 3)
		return (returnf2(248, arg2));
	if (a1type == 1)
		opentype = O_WRONLY | O_TRUNC | O_CREAT;
	else if (a1type == 2)
		opentype = O_WRONLY | O_APPEND | O_CREAT;
	if (a1type == 1 || a1type == 2)
		tag->redirect1 = open(arg2, opentype, 0644);
	else if (a1type == 0)
		tag->redirect0 = open(arg2, O_RDONLY);
	return (1942);
}
