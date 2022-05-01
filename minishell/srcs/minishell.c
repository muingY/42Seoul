/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:18:42 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/09 14:45:03 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_intro(void)
{
	int		fd;
	char	*line;

	fd = open("intro", O_RDONLY);
	if (fd < 0)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	line = NULL;
}

void	init(t_tag *tag, char **envp, int t1, char **t2)
{
	(void)t1;
	(void)t2;
	ft_memset((void *)tag, 0, sizeof(t_tag));
	set_builtin(&(tag->builtin));
	tag->envp = envp;
	set_env(envp, tag);
	tag->is_sigon = FALSE;
	tag->sig_c = 0;
	history_init(&tag->hist);
	print_intro();
}

/*
**	get_next_line(0, input);
**	(void)ncinput;
*/

void	do_inside_the_loop(t_tag *tag, char **input)
{
	int			rep_lock;
	t_ncinput	ncinput;

	clear_cmd(&(tag->cmd));
	tag->is_cmd = 1;
	non_canonical_init(0);
	ncinput = non_canonical_input();
	non_canonical_init(1);
	tag->is_cmd = 0;
	*input = ncinput.input;
	if (ncinput.input == NULL)
		*input = ft_strdup("");
	if (ft_strlen(*input) > 0)
		history_add(&tag->hist, *input);
	if (check_basic_syntax_error(*input) == 0)
	{
		free(*input);
		rep_lock = replace_lock(tag->input);
		set_cmd(&(tag->input), tag);
		if (rep_lock != TRUE)
			cmd_replace(tag);
		execution(tag, tag->cmd, tag->env);
	}
}

int		main(int argc, char **argv, char **envp)
{
	char	*input;
	t_bool	state;

	init(&g_tag, envp, argc, argv);
	state = TRUE;
	init_signal();
	while (state == TRUE)
	{
		if (g_tag.is_sigon == FALSE)
		{
			do_inside_the_loop(&g_tag, &input);
		}
		else
			g_tag.is_sigon = FALSE;
	}
	history_destory(&g_tag.hist);
	return (0);
}
