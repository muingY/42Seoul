/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:57:50 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/23 21:32:27 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
/* Functions */
public:
    Cat();
    Cat(const Cat& _cat);
    virtual ~Cat();

    Cat& operator=(const Cat& operand);

    virtual void MakeSound() const;
    
    void MindRead() const;

/* Variables */
private:
    Brain* brain;
};

#endif