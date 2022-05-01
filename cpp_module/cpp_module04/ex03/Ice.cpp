/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:02:04 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/29 12:18:38 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& _ice) : AMateria(_ice.type) {}
Ice::~Ice() {}

Ice& Ice::operator=(const Ice& operand)
{
    if (this != &operand)
    {
        this->type = operand.type;
    }

    return *this;
}

AMateria* Ice::Clone() const
{
    AMateria* ret = new Ice(*this);
    return ret;
}
void Ice::Use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}