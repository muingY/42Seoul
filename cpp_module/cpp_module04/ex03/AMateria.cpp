/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:08:54 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/29 12:00:38 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& _type)
{
    this->type = _type;
}
AMateria::~AMateria() {}

std::string const& AMateria::getType() const
{
    return this->type;
}

void AMateria::Use(ICharacter& target) { (void)target; }