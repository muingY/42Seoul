/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:25:14 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/02 16:02:23 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_unset(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int		i;

	(void)tag;
	tag->status = 0;
	if (cmd->argc < 2)
		return (tag->status);
	i = 0;
	while (cmd->argv[++i])
	{
		if (!is_valid_env_str(cmd->argv[i], FALSE, FALSE))
		{
			ft_putstr_fd("bash: unset: `", 2);
			ft_putstr_fd(cmd->argv[i], 2);
			returnf("'", 1, "not a valid identifier", 1);
			continue;
		}
		tag->status = tag->status | del_env_key(env, cmd->argv[i]);
	}
	return (tag->status);
}
