/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:26:57 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/31 22:32:30 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->LearnMateria(new Ice());
    src->LearnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->CreateMateria("ice");
    me->Equip(tmp);
    tmp = src->CreateMateria("cure");
    me->Equip(tmp);

    ICharacter* bob = new Character("bob");

    me->Use(0, *bob);
    me->Use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    return 0;
}