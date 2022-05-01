/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:39:37 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/29 13:42:12 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource& _materiaSource);
    virtual ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& operand);

    virtual void LearnMateria(AMateria* materia);
    virtual AMateria* CreateMateria(std::string const& type);

private:
    AMateria* templates[4];
};

#endif