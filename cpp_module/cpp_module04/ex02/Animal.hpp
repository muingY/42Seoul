/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:13:02 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/25 19:47:35 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
/* Functions */
public:
    Animal();
    Animal(const Animal& _animal);
    Animal(std::string _type);
    virtual ~Animal();

    std::string getType() const;
    void setType(std::string _type);

    Animal& operator=(const Animal& operand);

    virtual void MakeSound() const = 0;
    virtual void MindRead() const = 0;

/* Variables */
protected:
    std::string type;
    Brain* brain;
};

#endif