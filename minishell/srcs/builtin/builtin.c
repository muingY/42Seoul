/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:03:17 by seongcho          #+#    #+#             */
/*   Updated: 2021/04/29 14:19:13 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
**  List of builtin commands, followed by their corresponding functions.
*/

void	set_builtin(t_builtin *builtin)
{
	builtin->builtin_str[0] = "cd";
	builtin->builtin_str[1] = "help";
	builtin->builtin_str[2] = "exit";
	builtin->builtin_str[3] = "unset";
	builtin->builtin_str[4] = "export";
	builtin->builtin_str[5] = "echo";
	builtin->builtin_str[6] = "pwd";
	builtin->builtin_str[7] = "env";
	builtin->builtin_func[0] = &ft_cd;
	builtin->builtin_func[1] = &ft_help;
	builtin->builtin_func[2] = &ft_exit;
	builtin->builtin_func[3] = &ft_unset;
	builtin->builtin_func[4] = &ft_export;
	builtin->builtin_func[5] = &ft_echo;
	builtin->builtin_func[6] = &ft_pwd;
	builtin->builtin_func[7] = &ft_env;
}

int		num_builtins(t_builtin *builtin)
{
	return (sizeof(builtin->builtin_str) / sizeof(char *));
}

int		exec_builtin(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int			i;
	t_builtin	*builtin;

	builtin = &(tag->builtin);
	i = -1;
	while (++i < num_builtins(builtin))
	{
		if (ft_strcmp(cmd->argv[0], builtin->builtin_str[i]) == 0)
		{
			return ((builtin->builtin_func[i])(tag, cmd, env));
		}
	}
	return (1);
}

/*
** Builtin function implementations.
*/

int		ft_help(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int			i;
	t_builtin	*builtin;

	(void)cmd;
	(void)env;
	builtin = &(tag->builtin);
	printf("MINISHELL\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	i = -1;
	while (++i < num_builtins(builtin))
	{
		printf("  %s\n", builtin->builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return (1);
}
