/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:12:52 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 11:11:51 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;

    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
}
ScavTrap::ScavTrap(ScavTrap& scavTrap) : ClapTrap(scavTrap.getName())
{
    std::cout << "ScavTrap copy constructor called" << std::endl;

    setHitPoint(scavTrap.getHitPoint());
    setEnergyPoint(scavTrap.getEnergyPoint());
    setAttackDamage(scavTrap.getAttackDamage());
}
ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destoryed." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& operand)
{
    std::cout << "ScavTrap assignation operator called." << std::endl;

    if (this != &operand)
    {
        this->setName(operand.getName());
        this->setHitPoint(operand.getHitPoint());
        this->setEnergyPoint(operand.getEnergyPoint());
        this->setAttackDamage(operand.getAttackDamage());
    }
    return *this;
}

void ScavTrap::GuardGate()
{
    std::cout << "ScavTrap " << getName() << " is on gate keeper mode." << std::endl;
}

void ScavTrap::Attack(std::string const &target)
{
    if (getEnergyPoint() <= 0)
    {
        std::cout << "ScavTrap " << getName() << " can not attack. Energy point is empty." << std::endl;
        return;
    }

    setEnergyPoint(getEnergyPoint() - 1);
    
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " point of damage! (energy point = " << getEnergyPoint() << ")" << std::endl;
}
void ScavTrap::TakeDamage(unsigned int amount)
{
    setHitPoint(getHitPoint() - amount);

    std::cout << "ScavTrap " << getName() << " takes " << amount << " damage (HP = " << getHitPoint() << ")" << std::endl;
    if (getHitPoint() <= 0)
    {
        std::cout << "ScavTrap " << getName() << " is broken." << std::endl;
    }
}
void ScavTrap::BeRepaired(unsigned int amount)
{
    if ((int)amount > getHitPoint())
    {
        setHitPoint(amount);
    }
    
    std::cout << "ScavTrap " << getName() << " repaired. (HP = " << getHitPoint() << ")" << std::endl; 
}