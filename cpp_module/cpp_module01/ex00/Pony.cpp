/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:15:27 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/25 15:40:42 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony()
{
    std::cout << "> Pony instance create" << std::endl;
    this->speed = 50;
    this->cargoWeight = 20;
    this->fuel = 0;
}
Pony::Pony(int speed, int cargoWeight, int fuel)
{
    std::cout << "> Pony instance create" << std::endl;
    this->speed = speed;
    this->cargoWeight = cargoWeight;
    this->fuel = fuel;
}
Pony::~Pony()
{
    std::cout << "> Pony instance destroy" << std::endl;
}

void Pony::ShowStatus()
{
    std::cout << "speed        : " << speed << std::endl;
    std::cout << "cargo weight : " << cargoWeight << std::endl;
    std::cout << "fuel         : " << fuel << std::endl;
}