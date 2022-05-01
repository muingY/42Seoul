/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:24:58 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/27 14:57:50 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
    std::cout << "n: ";
    int n;
    std::cin >> n;

    ZombieHorde zombieHorde = ZombieHorde(n);
    zombieHorde.announce();
}