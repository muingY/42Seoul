/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_canonical_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:33:31 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/06 13:17:03 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_canonical.h"

void		non_canonical_init(int mode)
{
	struct termios			tio;
	static struct termios	tio_backup;

	if (mode == 0)
	{
		tcgetattr(STDIN_FILENO, &tio);
		tio_backup = tio;
		tio.c_lflag &= ~(ICANON | ECHO);
		tio.c_cc[VMIN] = 1;
		tio.c_cc[VTIME] = 0;
		tcsetattr(STDIN_FILENO, TCSANOW, &tio);
	}
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &tio_backup);
}

t_termcap	termcap_init(char *env_term)
{
	t_termcap ret;

	tgetent(NULL, env_term);
	ret.cm = tgetstr("cm", NULL);
	ret.ce = tgetstr("ce", NULL);
	ret.col = 0;
	ret.row = 0;
	return (ret);
}

t_ncinput	ncinput_init(void)
{
	t_ncinput	ret;

	ret.input = NULL;
	ret.input_state = -1;
	return (ret);
}

void		nc_input_process(int input, t_ncinput *ret,
int *is_continue, t_termcap *termcap)
{
	if (nc_isstr(input))
		ret->input = nc_stradd(ret->input, (char)input);
	else
	{
		if (input == 127)
		{
			ret->input_state = 1;
			ret->input = nc_strsub(ret->input);
		}
		else if (input == 10)
		{
			ret->input_state = 0;
			*is_continue = 0;
		}
		else if (input == 4283163 || input == 4348699)
			nc_history(&input, ret, termcap);
	}
}

t_ncinput	non_canonical_input(void)
{
	t_ncinput	ret;
	t_termcap	termcap;
	int			input;
	int			is_continue;

	ret = ncinput_init();
	termcap = termcap_init(TERM);
	nc_get_cursor_pos(&termcap);
	is_continue = 1;
	termcap.col += write(1, "> ", 2);
	while (read(0, &input, sizeof(int)) > 0 && is_continue)
	{
		nc_sub(input, &ret, &termcap, &is_continue);
		if (input == 4 && (ret.input == NULL || nc_strlen(ret.input) == 0))
			return (nc_ctrld(&ret));
		if (is_continue == 0)
		{
			if (ret.input_state == 0)
				write(1, "\n", 1);
			break ;
		}
		input = 0;
	}
	return (ret);
}
