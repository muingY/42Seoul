/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:53:56 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/27 14:15:56 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    this->type = NORMAL;
    this->name = "Nonamed";
}
Zombie::Zombie(std::string name, zombieType type)
{
    this->name = name;
    this->type = type;
}
Zombie::~Zombie()
{
    std::cout << "...Report destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << "[ Zombie Observe Report ]" << std::endl;
    std::cout << " - Name: " << name << std::endl;
    std::cout << " - Type: ";
    switch (type)
    {
    case NORMAL:
        std::cout << "NORMAL" << std::endl;
        std::cout << "   - Info: A normal and common zombie." << std::endl;
        break;
    case RUNNER:
        std::cout << "RUNNER" << std::endl;
        std::cout << "   - Info: Running fast, but weak." << std::endl;
        break;
    case HEAVY:
        std::cout << "HEAVY" << std::endl;
        std::cout << "   - Info: It looks fat and doesn't die well." << std::endl;
        break;
    case CONTAG:
        std::cout << "CONTAG" << std::endl;
        std::cout << "   - Info: They are usually looks fat. And carry body fluids that can be infected." << std::endl;
        break;
    case BOMBER:
        std::cout << "BOMBER" << std::endl;
        std::cout << "   - Info: It has an abnormally swollen abscess due to gas decay. It comes up fast and explodes." << std::endl;
        break;
    default:
        std::cout << "Warning! unknown type" << std::endl;
        break;
    }
}