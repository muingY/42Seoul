/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:00:52 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/22 10:47:23 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* cat1 = new Cat();
    const Animal* dog1 = new Dog();
    const Animal* dog2 = new Dog((Dog&)*dog1);

    std::cout << "Animal basic type is " << meta->getType() << "." << std::endl;
    std::cout << "cat1 type is " << cat1->getType() << "." << std::endl;
    std::cout << "dog1 type is " << dog1->getType() << "." << std::endl;

    meta->MakeSound();
    cat1->MakeSound();
    dog1->MakeSound();
    dog2->MakeSound();
    
    delete meta;
    delete cat1;
    delete dog1;
    delete dog2;
    return 0;
}