/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:05:22 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/27 13:20:55 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
public:
    AMateria(const std::string& _type);
    virtual ~AMateria();

    std::string const& getType() const;

    virtual AMateria* Clone() const = 0;
    virtual void Use(ICharacter& target);

protected:
    std::string type;
};

#endif