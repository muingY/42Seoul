/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:55:50 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/09 13:56:18 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <math.h>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed& _fixed);
    Fixed(const int _fixedValue);
    Fixed(const float _fixedValue);
    ~Fixed();

    Fixed &operator=(const Fixed& operand);

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt() const;

private:
    int fixedValue;
    static const int bit = 8;
};

std::ostream &operator<<(std::ostream& out, const Fixed& operand);

#endif