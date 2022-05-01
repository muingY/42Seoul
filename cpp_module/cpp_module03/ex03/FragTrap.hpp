/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:34:46 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 11:26:16 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
/* Functuons */
public:
    FragTrap();
    FragTrap(FragTrap& fragTrap);
    FragTrap(std::string _name);
    virtual ~FragTrap();

    FragTrap& operator=(FragTrap& operand);

    void HighFivesGuys();

    virtual void Attack(std::string const &target);
    virtual void TakeDamage(unsigned int amount);
    virtual void BeRepaired(unsigned int amount);
};

#endif