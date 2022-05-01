/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:10:21 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/22 10:23:37 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called." << std::endl;
}
Dog::Dog(const Dog& _dog) : Animal(_dog.type)
{
    std::cout << "Dog copy constructor called." << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& operand)
{
    std::cout << "Dog assignation operator called." << std::endl;
    
    if (this != &operand)
    {
        this->type = operand.type;
    }

    return *this;
}

void Dog::MakeSound() const
{
    std::cout << type << ": Woof! Woof!" << std::endl;
}