/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:55:50 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/15 03:48:53 by hyungyyo         ###   ########.fr       */
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

    Fixed& operator=(const Fixed& operand);

    Fixed operator+(const Fixed& operand) const;
    Fixed operator-(const Fixed& operand) const;
    Fixed operator*(const Fixed& operand) const;
    Fixed operator/(const Fixed& operand) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    bool operator>(const Fixed& operand) const;
    bool operator<(const Fixed& operand) const;
    bool operator>=(const Fixed& operand) const;
    bool operator<=(const Fixed& operand) const;
    bool operator==(const Fixed& operand) const;
    bool operator!=(const Fixed& operand) const;

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt() const;

    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int fixedValue;
    static const int bit = 8;
};

std::ostream &operator<<(std::ostream& out, const Fixed& operand);

#endif