/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:53:49 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/27 14:13:29 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <stdlib.h>
#include <time.h>

void randomChump()
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
    ZombieEvent zombieEvent;

    srand(time(NULL));
    zombieEvent.setZombieType(zombieType(rand() % 5));
    Zombie *zombie = zombieEvent.newZombie(namepool[rand() % 25]);
    zombie->announce();
    delete zombie;
}

int main()
{
    randomChump();
    return 0;
}