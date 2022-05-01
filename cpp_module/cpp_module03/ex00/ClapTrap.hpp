/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:55:19 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/13 20:54:33 by hyungyyo         ###   ########.fr       */
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
    ~ClapTrap();

    void setName(std::string _name);
    void setHitPoint(int _hitPoint);
    void setEnergyPoint(int _energyPoint);
    void setAttackDamage(int _attackDamage);
    std::string getName();
    int getHitPoint();
    int getEnergyPoint();
    int getAttackDamage();

    ClapTrap& operator=(const ClapTrap& operand);

    void Attack(std::string const &target);
    void TakeDamage(unsigned int amount);
    void BeRepaired(unsigned int amount);

/* Variables */
private:
    std::string name;
    int hitPoint;
    int energyPoint;
    int attackDamage;
};

#endif