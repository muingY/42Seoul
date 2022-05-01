/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:55:09 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 11:30:54 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot1("SPOT");
    ClapTrap bot2("HUBO");

    bot1.Attack("HUBO");
    bot2.TakeDamage(bot1.getAttackDamage());
    bot2.BeRepaired(10);
    return 0;
}