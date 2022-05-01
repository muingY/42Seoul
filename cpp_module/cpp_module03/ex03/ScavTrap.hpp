/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:12:50 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 11:26:22 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
/* Functions */
public:
    ScavTrap();
    ScavTrap(ScavTrap& scavTrap);
    ScavTrap(std::string _name);
    virtual ~ScavTrap();

    ScavTrap& operator=(ScavTrap& operand);

    void GuardGate();

    virtual void Attack(std::string const &target);
    virtual void TakeDamage(unsigned int amount);
    virtual void BeRepaired(unsigned int amount);
};

#endif