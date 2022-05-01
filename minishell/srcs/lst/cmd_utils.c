/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:26:58 by seongcho          #+#    #+#             */
/*   Updated: 2021/04/22 22:48:07 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_cmd(t_cmd **cmd_head)
{
	t_cmd	*cmd;
	t_cmd	*nextcmd;
	int		i;

	if (!*cmd_head)
		return ;
	cmd = *cmd_head;
	while (cmd)
	{
		nextcmd = cmd->next;
		i = -1;
		while (cmd->argv[++i])
			free(cmd->argv[i]);
		free(cmd->argv);
		cmd->prev = NULL;
		cmd->next = NULL;
		free(cmd);
		cmd = nextcmd;
	}
	*cmd_head = NULL;
}

void	print_cmd(t_cmd *cmd)
{
	int i;
	int j;

	j = 0;
	while (cmd)
	{
		printf("[%d] ", j);
		i = -1;
		while (cmd->argv[++i])
			printf("%s ", cmd->argv[i]);
		if (cmd->is_pipe == 1)
			printf("|");
		printf("\n");
		j++;
		cmd = cmd->next;
	}
}
