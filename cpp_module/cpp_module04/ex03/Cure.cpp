/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:11:44 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/29 12:18:02 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure& _cure) : AMateria(_cure.type) {}
Cure::~Cure() {}

Cure& Cure::operator=(const Cure& operand)
{
    if (this != &operand)
    {
        this->type = operand.type;
    }

    return *this;
}

AMateria* Cure::Clone() const
{
    return (new Cure(*this));
}
void Cure::Use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() <<"’s wounds *" << std::endl;
}