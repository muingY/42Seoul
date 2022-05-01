/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:35:43 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 11:24:00 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called." << std::endl;

    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
}
FragTrap::FragTrap(FragTrap& fragTrap) : ClapTrap(fragTrap.getName())
{
    std::cout << "FragTrap default constructor called." << std::endl;

    setHitPoint(fragTrap.getHitPoint());
    setEnergyPoint(fragTrap.getEnergyPoint());
    setAttackDamage(fragTrap.getAttackDamage());
}
FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap constructor called." << std::endl;

    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& operand)
{
    std::cout << "FragTrap assignation operator called." << std::endl;

    if (this != &operand)
    {
        this->setName(operand.getName());
        this->setHitPoint(operand.getHitPoint());
        this->setEnergyPoint(operand.getEnergyPoint());
        this->setAttackDamage(operand.getAttackDamage());
    }
    return *this;
}

void FragTrap::HighFivesGuys()
{
    std::cout << "FragTrap " << getName() << ", highfive!" << std::endl;
}

void FragTrap::Attack(std::string const &target)
{
    if (getEnergyPoint() <= 0)
    {
        std::cout << "FragTrap " << getName() << " can not attack. Energy point is empty." << std::endl;
        return;
    }

    setEnergyPoint(getEnergyPoint() - 1);
    
    std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " point of damage! (energy point = " << getEnergyPoint() << ")" << std::endl;
}
void FragTrap::TakeDamage(unsigned int amount)
{
    setHitPoint(getHitPoint() - amount);

    std::cout << "FragTrap " << getName() << " takes " << amount << " damage (HP = " << getHitPoint() << ")" << std::endl;
    if (getHitPoint() <= 0)
    {
        std::cout << "FragTrap " << getName() << " is broken." << std::endl;
    }
}
void FragTrap::BeRepaired(unsigned int amount)
{
    if ((int)amount > getHitPoint())
    {
        setHitPoint(amount);
    }
    
    std::cout << "FragTrap " << getName() << " repaired. (HP = " << getHitPoint() << ")" << std::endl; 
}