/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:19:42 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/31 22:28:19 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class ICharacter;
class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {}
    
    virtual std::string const& getName() const = 0;
    virtual void Equip(AMateria* m) = 0;
    virtual void UnEquip(int idx) = 0;
    virtual void Use(int idx, ICharacter& target) = 0;
};

#endif