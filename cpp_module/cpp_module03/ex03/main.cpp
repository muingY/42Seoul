/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:13:41 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/12 20:44:55 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap* diamondBot = new DiamondTrap("DiaBot");

    diamondBot->WhoAmI();
    diamondBot->Attack("Something");
    diamondBot->TakeDamage(200);
    diamondBot->BeRepaired(100);

    delete diamondBot;
    return 0;
}