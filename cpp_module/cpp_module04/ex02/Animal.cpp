/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:36:16 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/23 21:32:36 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called." << std::endl;

    this->type = "(unset)";
}
Animal::Animal(const Animal& _animal)
{
    std::cout << "Animal copy constructor called." << std::endl;

    this->type = _animal.type;
}
Animal::Animal(std::string _type)
{
    std::cout << "Animal constructor called." << std::endl;

    this->type = _type;
}
Animal::~Animal()
{
    std::cout << "Animal destroyed." << std::endl;
}

std::string Animal::getType() const { return type; }
void Animal::setType(std::string _type) { this->type = _type; }


Animal& Animal::operator=(const Animal& operand)
{
    if (this != &operand)
    {
        this->type = operand.type;
    }

    return *this;
}

void Animal::MakeSound() const
{
    std::cout << "Animal can make sound. What did you expect? This is just standard animal class." << std::endl;
}