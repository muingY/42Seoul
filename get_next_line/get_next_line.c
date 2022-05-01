/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:52:57 by hyungyyo          #+#    #+#             */
/*   Updated: 2020/12/28 19:47:05 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		is_line(char *buffer)
{
	size_t		pos;

	pos = 0;
	while (buffer[pos] != '\0')
	{
		if (buffer[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1);
}

static int		get_line(char **remain_str, char **line, int cut_pos)
{
	size_t	len;
	char	*tmp;

	(*remain_str)[cut_pos] = '\0';
	*line = ft_strdup(*remain_str);
	len = ft_strlen(*remain_str + cut_pos + 1);
	if (len == 0)
	{
		free(*remain_str);
		*remain_str = 0;
		return (RET_READED);
	}
	tmp = ft_strdup(*remain_str + cut_pos + 1);
	free(*remain_str);
	*remain_str = tmp;
	return (RET_READED);
}

static int		remain_process(char **remain_str, char **line, int size)
{
	int cut_pos;

	if (size < 0)
		return (RET_ERROR);
	if (*remain_str && (cut_pos = is_line(*remain_str)) >= 0)
		return (get_line(remain_str, line, cut_pos));
	else if (*remain_str)
	{
		*line = *remain_str;
		*remain_str = 0;
		return (RET_EOF);
	}
	*line = ft_strdup("");
	return (RET_EOF);
}

int				get_next_line(int fd, char **line)
{
	static char	*remain_str[FD_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			read_ret;
	int			cut_pos;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (RET_ERROR);
	while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_ret] = '\0';
		remain_str[fd] = ft_strjoin(remain_str[fd], buffer);
		if ((cut_pos = is_line(remain_str[fd])) >= 0)
			return (get_line(&remain_str[fd], line, cut_pos));
	}
	return (remain_process(&remain_str[fd], line, read_ret));
}
