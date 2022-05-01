/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:03:36 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/31 22:38:31 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Animal** InitializeAnimalPool(const int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    Animal** ret;

    ret = new Animal*[size];
    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
        {
            ret[i] = new Cat();
        }
        else
        {
            ret[i] = new Dog();
        }
    }
    return ret;
}
void ShowAnimalPool(Animal** animalPool, const int size)
{
    for (int i = 0; i < size; i++)
    {
        animalPool[i]->MakeSound();
        
        if (i < size / 2)
        {
            dynamic_cast<Cat*>(animalPool[i])->MindRead();
        }
        else
        {
            dynamic_cast<Dog*>(animalPool[i])->MindRead();
        }
    }
}
void DestroyAnimalPool(Animal** animalPool, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (animalPool[i] != NULL)
        {
            delete animalPool[i];
        }
    }
    delete animalPool;
}

int main()
{
    Animal** animalPool;
    int size;

    std::cout << "Animal n: ";
    std::cin >> size;

    animalPool = InitializeAnimalPool(size);
    if (animalPool == NULL)
    {
        std::cout << "Error: Initialize AnimalPool fail." << std::endl;
        return 0;
    }
    ShowAnimalPool(animalPool, size);
    DestroyAnimalPool(animalPool, size);
    
    return 0;
}