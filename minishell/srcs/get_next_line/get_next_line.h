/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:52:55 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/02 03:42:01 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define FD_MAX 65535

# define RET_READED 1
# define RET_EOF 0
# define RET_ERROR -1

size_t	ft_gstrlen(const char *s);
char	*ft_gstrdup(const char *s);
char	*ft_gstrjoin(char *s1, char *s2);
size_t	ft_gstrlcpy(char *dest, const char *src, size_t size);
size_t	ft_gstrlcat(char *dest, const char *src, size_t size);

int		get_next_line(int fd, char **line);

#endif
