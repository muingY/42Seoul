/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:57:50 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/22 10:08:06 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
/* Functions */
public:
    Cat();
    Cat(const Cat& _cat);
    virtual ~Cat();

    Cat& operator=(const Cat& operand);

    virtual void MakeSound() const;
};

#endif