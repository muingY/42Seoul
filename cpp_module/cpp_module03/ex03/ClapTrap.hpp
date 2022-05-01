/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:55:19 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/13 20:54:55 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
/* Functions */
public:
    ClapTrap();
    ClapTrap(ClapTrap& _clapTrap);
    ClapTrap(std::string _name);
    virtual ~ClapTrap();

    void setName(std::string _name);
    void setHitPoint(int _hitPoint);
    void setEnergyPoint(int _energyPoint);
    void setAttackDamage(int _attackDamage);
    std::string getName();
    int getHitPoint();
    int getEnergyPoint();
    int getAttackDamage();

    ClapTrap& operator=(const ClapTrap& operand);

    virtual void Attack(std::string const &target);
    virtual void TakeDamage(unsigned int amount);
    virtual void BeRepaired(unsigned int amount);

/* Variables */
private:
    std::string name;
    int hitPoint;
    int energyPoint;
    int attackDamage;
};

#endif