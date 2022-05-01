/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:22:44 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/29 11:30:13 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
    Character(const std::string _name);
    Character(const Character& _character);
    virtual ~Character();

    Character& operator=(const Character& operand);

    virtual std::string const& getName() const;

    virtual void Equip(AMateria* m);
    virtual void UnEquip(int idx);
    virtual void Use(int idx, ICharacter& target);

private:
    std::string name;
    AMateria* materiaInven[4];
};

#endif