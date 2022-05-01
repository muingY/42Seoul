/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:10:21 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/24 22:47:34 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called." << std::endl;

    this->brain = new Brain();
    brain->AutoInsertIdea("I want something to eat.");
    brain->AutoInsertIdea("Where is my ball?");
    brain->AutoInsertIdea("Cat's are arrogant.");
}
Dog::Dog(const Dog& _dog) : Animal(_dog.type)
{
    std::cout << "Dog copy constructor called." << std::endl;

    brain = new Brain(*_dog.brain);
}
Dog::~Dog()
{
    std::cout << "Dog destroyed." << std::endl;

    delete brain;
}

Dog& Dog::operator=(const Dog& operand)
{
    std::cout << "Dog assignation operator called." << std::endl;
    
    if (this != &operand)
    {
        this->type = operand.type;
        delete brain;
        this->brain = new Brain(*operand.brain);
    }

    return *this;
}

void Dog::MakeSound() const
{
    std::cout << type << ": Woof! Woof!" << std::endl;
}

void Dog::MindRead() const
{
    brain->PrintStatus();
    brain->PrintIdeaList();
}