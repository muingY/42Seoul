/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:25:05 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/04/29 14:17:45 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_pwd(t_tag *tag, t_cmd *cmd, t_env *env)
{
	char	*dir;

	(void)tag;
	(void)cmd;
	(void)env;
	dir = getcwd(NULL, BUFSIZ);
	if (dir == NULL)
	{
		printf("\n");
		return (1);
	}
	printf("%s\n", dir);
	free(dir);
	return (0);
}
