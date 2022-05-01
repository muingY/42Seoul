/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:58:32 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/22 10:05:33 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called." << std::endl;
}
Cat::Cat(const Cat& _cat) : Animal(_cat.type)
{
    std::cout << "Cat copy constructor called." << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat destroyed." << std::endl;
}

Cat& Cat::operator=(const Cat& operand)
{
    std::cout << "Cat assignation operator called." << std::endl;
    
    if (this != &operand)
    {
        this->type = operand.type;
    }

    return *this;
}

void Cat::MakeSound() const
{
    std::cout << type << ": Meow~" << std::endl;
}