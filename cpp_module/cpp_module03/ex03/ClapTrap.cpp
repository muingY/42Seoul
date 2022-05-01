/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:55:17 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/13 20:56:39 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called." << std::endl;

    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
}
ClapTrap::ClapTrap(ClapTrap& _clapTrap)
{
    std::cout << "ClapTrap copy constructor called." << std::endl;

    this->name = _clapTrap.name;
    this->hitPoint = _clapTrap.hitPoint;
    this->energyPoint = _clapTrap.energyPoint;
    this->attackDamage = _clapTrap.attackDamage;
}
ClapTrap::ClapTrap(std::string _name)
{
    std::cout << "ClapTrap constructor called." << std::endl;

    this->name = _name;
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destoryed." << std::endl;
}

void ClapTrap::setName(std::string _name) { this->name = _name; }
void ClapTrap::setHitPoint(int _hitPoint) { this->hitPoint = _hitPoint; }
void ClapTrap::setEnergyPoint(int _energyPoint) { this->energyPoint = _energyPoint; }
void ClapTrap::setAttackDamage(int _attackDamage) { this->attackDamage = _attackDamage; }
std::string ClapTrap::getName() { return this->name; }
int ClapTrap::getHitPoint() { return this->hitPoint; }
int ClapTrap::getEnergyPoint() { return this->energyPoint; }
int ClapTrap::getAttackDamage() { return this->attackDamage; }

ClapTrap& ClapTrap::operator=(const ClapTrap& operand)
{
    std::cout << "ClapTrap assignation operator called." << std::endl;

    if (this != &operand)
    {
        this->name = operand.name;
        this->hitPoint = operand.hitPoint;
        this->energyPoint = operand.energyPoint;
        this->attackDamage = operand.attackDamage;
    }
    return *this;
}

void ClapTrap::Attack(std::string const &target)
{
    if (energyPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " can not attack. Energy point is empty." << std::endl;
        return;
    }

    energyPoint--;
    
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " point of damage! (energy point = " << energyPoint << ")" << std::endl;
}
void ClapTrap::TakeDamage(unsigned int amount)
{
    hitPoint -= amount;

    std::cout << "ClapTrap " << name << " takes " << amount << " damage (HP = " << hitPoint << ")" << std::endl;
    if (hitPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " is broken." << std::endl;
    }
}
void ClapTrap::BeRepaired(unsigned int amount)
{
    if ((int)amount > hitPoint)
    {
        hitPoint = amount;
    }
    
    std::cout << "ClapTrap " << name << " repaired. (HP = " << hitPoint << ")" << std::endl; 
}