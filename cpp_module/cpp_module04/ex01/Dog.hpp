/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:08:38 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/24 20:12:19 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
/* Functions */
public:
    Dog();
    Dog(const Dog& _dog);
    virtual ~Dog();

    Dog& operator=(const Dog& operand);

    virtual void MakeSound() const;

    void MindRead() const;

/* Variables */
private:
    Brain* brain;
};

#endif