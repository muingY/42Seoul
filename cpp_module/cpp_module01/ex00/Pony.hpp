/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:15:29 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/25 12:07:37 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{
public:
    Pony();
    Pony(int speed, int cargoWeight, int fuel);
    ~Pony();

    void ShowStatus();
    
private:
    int speed;
    int cargoWeight;
    int fuel;
};

#endif