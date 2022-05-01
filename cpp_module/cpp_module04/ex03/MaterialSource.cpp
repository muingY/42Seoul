/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaterialSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:49:01 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/31 22:31:09 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        this->templates[i] = NULL;
    }
}
MateriaSource::MateriaSource(const MateriaSource& _materiaSource)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materiaSource.templates[i] != NULL)
        {
            this->templates[i] = _materiaSource.templates[i]->Clone();
        }
        else
        {
            this->templates[i] = NULL;
        }
    }
}
MateriaSource::~MateriaSource()
{
    AMateria* temp;

    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL)
        {
            temp = templates[i];
            delete templates[i];
            templates[i] = NULL;
            for (int ii = i; ii < 4; ii++)
            {
                if (templates[ii] == temp)
                {
                    templates[ii] = NULL;
                }
            }
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& operand)
{
    if (this != &operand)
    {
        for (int i = 0; i < 4; i++)
        {
            if (operand.templates[i] != NULL)
            {
                if (this->templates[i] != NULL)
                {
                    delete templates[i];
                }
                this->templates[i] = operand.templates[i]->Clone();
            }
            else
            {
                if (this->templates[i] != NULL)
                {
                    delete this->templates[i];
                }
                this->templates[i] = NULL;
            }
        }
    }

    return *this;
}

void MateriaSource::LearnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == NULL)
        {
            templates[i] = materia;
            break;
        }
    }
}
AMateria* MateriaSource::CreateMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL)
        {
            if (type == templates[i]->getType())
            {
                return templates[i]->Clone();
            }
        }
    }
    return NULL;
}