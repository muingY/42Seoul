/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:20:01 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/23 14:11:54 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "philohead.h"

int		main(int argc, char **argv)
{
	t_philocore philocore;

	if (!(argc >= 5 && argc <= 6))
		return (error(0, "Error: Invalid arguments"));
	if (philocontrol_init(&philocore, argv) != TRUE)
		error_exit(0, "Error: Init fail");
	if (philocontrol_start(&philocore) != TRUE)
		error_exit(0, "Error: Start fail");
	philocontrol_destroy(&philocore);
	return (0);
}
