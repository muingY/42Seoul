/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:55:56 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/15 03:49:04 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedValue = 0;
}
Fixed::Fixed(const Fixed& _fixed)
{
    this->fixedValue = _fixed.fixedValue;
}
Fixed::Fixed(const int _fixedValue)
{
    this->fixedValue = _fixedValue << this->bit;
}
Fixed::Fixed(const float _fixedValue)
{
    this->fixedValue = (int)(roundf(_fixedValue * (1 << this->bit)));
}
Fixed::~Fixed()
{
    
}

Fixed &Fixed::operator=(const Fixed& operand)
{
    if (this != &operand)
    {
        this->fixedValue = operand.getRawBits();
    }
    return *this;
}

Fixed Fixed::operator+(const Fixed& operand) const
{
    Fixed ret;

    ret.setRawBits(this->fixedValue + operand.getRawBits());
    return ret;
}
Fixed Fixed::operator-(const Fixed& operand) const
{
    Fixed ret;

    ret.setRawBits(this->fixedValue - operand.getRawBits());
    return ret;
}
Fixed Fixed::operator*(const Fixed& operand) const
{
    Fixed ret;

    ret.setRawBits((this->fixedValue * operand.getRawBits()) >> this->bit);
    return ret;
}
Fixed Fixed::operator/(const Fixed& operand) const
{
    Fixed ret;

    ret.setRawBits((this->fixedValue << this->bit) / operand.getRawBits());
    return ret;
}
Fixed& Fixed::operator++()
{
    this->fixedValue++;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed ret(*this);

    operator++();
    return ret;
}
Fixed& Fixed::operator--()
{
    this->fixedValue--;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed ret(*this);

    operator--();
    return *this;
}

bool Fixed::operator>(const Fixed& operand) const
{
    return (this->fixedValue > operand.getRawBits());
}
bool Fixed::operator<(const Fixed& operand) const
{
    return (this->fixedValue < operand.getRawBits());
}
bool Fixed::operator>=(const Fixed& operand) const
{
    return (this->fixedValue >= operand.getRawBits());
}
bool Fixed::operator<=(const Fixed& operand) const
{
    return (this->fixedValue <= operand.getRawBits());
}
bool Fixed::operator==(const Fixed& operand) const
{
    return (this->fixedValue == operand.getRawBits());
}
bool Fixed::operator!=(const Fixed& operand) const
{
    return (this->fixedValue != operand.getRawBits());
}

int Fixed::getRawBits() const
{
    return fixedValue;
}
void Fixed::setRawBits(int const raw)
{
    fixedValue = raw;
}

float Fixed::toFloat() const
{
    return ((float)this->fixedValue / (float)(1 << this->bit));
}
int Fixed::toInt() const
{
    return (int)(this->fixedValue >> this->bit);
}

std::ostream &operator<<(std::ostream& out, const Fixed& operand)
{
    out << operand.toFloat();
    return (out);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a > b)
    {
        return b;
    }
    else if (a < b)
    {
        return a;
    }
    return a;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
    {
        return a;
    }
    else if (a < b)
    {
        return b;
    }
    return a;
}