/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:24:54 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/27 15:02:50 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <stdlib.h>
#include <time.h>

ZombieHorde::ZombieHorde(int n)
{
    this->n = n;
    
    zombiePool = new Zombie*[this->n];
    srand(time(NULL));
    for (int i = 0; i < this->n; i++)
    {
        zombiePool[i] = randomChump();
    }
}
ZombieHorde::~ZombieHorde()
{
    for (int i = 0; i < n; i++)
    {
        delete zombiePool[i];
    }
    delete zombiePool;
}

void ZombieHorde::announce()
{
    for (int i = 0; i < n; i++)
    {
        zombiePool[i]->announce();
    }
}

Zombie* ZombieHorde::randomChump()
{
    std::string namepool[] = {
        "Anabel",
        "Anemone",
        "Adriana",
        "Barbara",
        "Boris",
        "Charlie",
        "Catarina",
        "Chris",
        "Diana",
        "Elsa",
        "Evan",
        "Flora",
        "Fidelia",
        "Gertrude",
        "Giuliana",
        "Henry",
        "Irene",
        "Isabel",
        "Janet",
        "Jenny",
        "Julia",
        "Kate",
        "Lina",
        "Leo",
        "Mupy"
    };
    Zombie *zombie = new Zombie(namepool[rand() % 25], zombieType(rand() % 5));
    return zombie;
}