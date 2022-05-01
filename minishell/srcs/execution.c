/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:16:46 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/02 22:16:21 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_syntax_error(t_cmd *cmd, int check)
{
	int		i;

	if (!check)
		return (0);
	i = -1;
	while (++i < cmd->argc)
	{
		if (!cmd->argv[i])
			exitf("bash: syntax error near unexpected token",
				1, strerror(errno), 248);
		ft_putstr_fd(cmd->argv[i], 2);
		ft_putstr_fd("@", 2);
	}
	if (cmd->is_pipe)
		ft_putstr_fd("|", 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int		exec_cmd(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int status;

	check_syntax_error(cmd, 0);
	status = redirect_cmd(tag, cmd, env);
	if (status != 0)
		exit(status);
	if (ft_strcmp(cmd->argv[0], "pwd") == 0 ||
		ft_strcmp(cmd->argv[0], "echo") == 0 ||
		ft_strcmp(cmd->argv[0], "export") == 0 ||
		ft_strcmp(cmd->argv[0], "env") == 0)
	{
		status = exec_builtin(tag, cmd, env);
		exit(status);
	}
	check_cmd_path(cmd, env);
	return (execve(cmd->argv[0], cmd->argv, tag->envp));
}

int		exec_process(t_tag *tag, t_cmd *cmd, t_env *env)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	(void)wpid;
	operate_pipe(tag, cmd, 0);
	pid = fork();
	if (pid == 0)
	{
		operate_pipe(tag, cmd, 1);
		if (exec_cmd(tag, cmd, env) < 0)
			exitf_exec(cmd->argv[0], strerror(errno), (int)errno);
	}
	else if (pid < 0)
		exitf("bash: process error", 1, strerror(errno), 1);
	else
	{
		wpid = waitpid(pid, &status, 0);
		operate_pipe(tag, cmd, 2);
		if (WIFEXITED(status))
			tag->status = WEXITSTATUS(status);
	}
	return (0);
}

int		subexec(t_tag *tag, t_cmd *cmd, t_env *env)
{
	if (cmd->argv[0] == NULL)
		return (-1);
	else if (ft_strcmp(cmd->argv[0], "cd") == 0 ||
			ft_strcmp(cmd->argv[0], "exit") == 0 ||
			ft_strcmp(cmd->argv[0], "help") == 0 ||
			(ft_strcmp(cmd->argv[0], "export") == 0 && cmd->argc > 1) ||
			ft_strcmp(cmd->argv[0], "unset") == 0)
	{
		if (cmd->prev && cmd->prev->is_pipe &&
			!(ft_strcmp(cmd->prev->argv[0], "cd") == 0 ||
			ft_strcmp(cmd->prev->argv[0], "exit") == 0 ||
			ft_strcmp(cmd->prev->argv[0], "help") == 0 ||
			(ft_strcmp(cmd->prev->argv[0], "export") == 0 && cmd->argc > 1) ||
			ft_strcmp(cmd->prev->argv[0], "unset") == 0))
			close(cmd->prev->fd[0]);
		return (exec_builtin(tag, cmd, env));
	}
	else
		return (exec_process(tag, cmd, env));
}

void	execution(t_tag *tag, t_cmd *cmd, t_env *env)
{
	int			status;
	t_builtin	*builtin;

	(void)status;
	(void)builtin;
	builtin = &(g_tag.builtin);
	while (cmd)
	{
		status = subexec(tag, cmd, env);
		cmd = cmd->next;
	}
}
