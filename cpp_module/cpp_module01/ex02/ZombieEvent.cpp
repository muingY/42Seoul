/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:53:54 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/27 14:16:07 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
    type = NORMAL;
}

void ZombieEvent::setZombieType(zombieType type)
{
    this->type = type;
}
Zombie* ZombieEvent::newZombie(std::string name)
{
    Zombie* zombie = new Zombie(name, type);
    return zombie;
}