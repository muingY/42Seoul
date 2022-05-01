/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:26:23 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/29 13:34:04 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string _name)
{
    this->name = _name;
    for (int i = 0; i < 4; i++)
    {
        this->materiaInven[i] = NULL;
    }
}
Character::Character(const Character& _chracter)
{
    this->name = _chracter.name;
    for (int i = 0; i < 4; i++)
    {
        if (_chracter.materiaInven[i] != NULL)
        {
            this->materiaInven[i] = _chracter.materiaInven[i]->Clone();
        }
        else
        {
            this->materiaInven[i] = NULL;
        }
    }
}
Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (materiaInven[i] != NULL)
        {
            delete materiaInven[i];
            materiaInven[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& operand)
{
    if (this != &operand)
    {
        this->name = operand.name;
        for (int i = 0; i < 4; i++)
        {
            if (operand.materiaInven[i] != NULL)
            {
                if (this->materiaInven[i] != NULL)
                {
                    delete this->materiaInven[i];
                }
                this->materiaInven[i] = operand.materiaInven[i]->Clone();
            }
            else
            {
                if (this->materiaInven[i] != NULL)
                {
                    delete this->materiaInven[i];
                }
                this->materiaInven[i] = NULL;
            }
        }
    }

    return *this;
}

std::string const& Character::getName() const
{
    return name;
}

void Character::Equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (m == materiaInven[i])
        {
            break;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (materiaInven[i] == NULL)
        {
            materiaInven[i] = m;
            break;
        }
    }
}
void Character::UnEquip(int idx)
{
    if (!(idx >= 0 && idx <= 3))
    {
        return;
    }
    
    if (materiaInven[idx] != NULL)
    {
        materiaInven[idx] = NULL;
    }
}
void Character::Use(int idx, ICharacter& target)
{
    if (!(idx >= 0 && idx <= 3))
    {
        return;
    }

    if (materiaInven[idx] != NULL)
    {
        materiaInven[idx]->Use(target);
    }
}