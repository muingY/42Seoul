/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:12:20 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 11:36:45 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor called." << std::endl;

    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(30);
}
DiamondTrap::DiamondTrap(DiamondTrap& _diamondTrap) : ClapTrap(_diamondTrap.getName())
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;

    this->name = _diamondTrap.name;
    setHitPoint(_diamondTrap.getHitPoint());
    setEnergyPoint(_diamondTrap.getEnergyPoint());
    setAttackDamage(_diamondTrap.getAttackDamage());
}
DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name")
{
    std::cout << "DiamondTrap constructor called." << std::endl;
    
    this->name = _name;
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(30);
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destroyed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& operand)
{
    std::cout << "DiamondTrap assignation operator called." << std::endl;

    if (this != &operand)
    {
        this->name = operand.name;
        this->setName(operand.getName());
        setHitPoint(operand.getHitPoint());
        setEnergyPoint(operand.getEnergyPoint());
        setAttackDamage(operand.getAttackDamage());
    }
    return *this;
}

void DiamondTrap::WhoAmI()
{
    std::cout << "DiamondTrap name is " << name << ". And ClapTrap name is " << getName() << "." << std::endl;
}

void DiamondTrap::Attack(std::string const &target)
{
    ScavTrap::Attack(target);
}
void DiamondTrap::TakeDamage(unsigned int amount)
{
    setHitPoint(getHitPoint() - amount);

    std::cout << "DiamondTrap " << getName() << " takes " << amount << " damage (HP = " << getHitPoint() << ")" << std::endl;
    if (getHitPoint() <= 0)
    {
        std::cout << "DiamondTrap " << getName() << " is broken." << std::endl;
    }
}
void DiamondTrap::BeRepaired(unsigned int amount)
{
    if ((int)amount > getHitPoint())
    {
        setHitPoint(amount);
    }
    
    std::cout << "DiamondTrap " << getName() << " repaired. (HP = " << getHitPoint() << ")" << std::endl; 
}