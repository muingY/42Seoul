/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:55:32 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 11:25:53 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
/* Functions */
public:
    DiamondTrap();
    DiamondTrap(DiamondTrap& _diamondTrap);
    DiamondTrap(std::string _name);
    virtual ~DiamondTrap();

    DiamondTrap& operator=(DiamondTrap& operand);

    void WhoAmI();

    virtual void Attack(std::string const &target);
    virtual void TakeDamage(unsigned int amount);
    virtual void BeRepaired(unsigned int amount);

/* Variables */
private:
    std::string name;
};

#endif