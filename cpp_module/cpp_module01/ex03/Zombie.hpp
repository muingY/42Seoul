/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:49:38 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/26 01:24:14 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string> 

enum zombieType
{
    NORMAL,
    RUNNER,
    HEAVY,
    CONTAG,
    BOMBER
};

class Zombie
{
public:
    Zombie();
    Zombie(std::string name, zombieType type);
    ~Zombie();

    void announce();

private:
    zombieType type;
    std::string name;
};

#endif