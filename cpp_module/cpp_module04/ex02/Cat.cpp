/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:58:32 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/24 22:48:44 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called." << std::endl;

    brain = new Brain();
    brain->AutoInsertIdea("I am your master.");
    brain->AutoInsertIdea("Fuxx! water pool!");
    brain->AutoInsertIdea("Was that your cup? I've already pushed.");
}
Cat::Cat(const Cat& _cat) : Animal(_cat.type)
{
    std::cout << "Cat copy constructor called." << std::endl;

    brain = new Brain(*_cat.brain);
}
Cat::~Cat()
{
    std::cout << "Cat destroyed." << std::endl;

    delete brain;
}

Cat& Cat::operator=(const Cat& operand)
{
    std::cout << "Cat assignation operator called." << std::endl;
    
    if (this != &operand)
    {
        this->type = operand.type;
        delete brain;
        this->brain = new Brain(*operand.brain);
    }

    return *this;
}

void Cat::MakeSound() const
{
    std::cout << type << ": Meow~" << std::endl;
}

void Cat::MindRead() const
{
    brain->PrintStatus();
    brain->PrintIdeaList();
}