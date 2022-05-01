/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:13:41 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/11 21:27:57 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap* scavBot = new ScavTrap("TURRET");
    ClapTrap* clapBot = new ClapTrap("SPOT");

    scavBot->GuardGate();
    clapBot->Attack("TURRET");
    scavBot->TakeDamage(0);
    scavBot->BeRepaired(110);

    delete scavBot;
    delete clapBot;
    return 0;
}