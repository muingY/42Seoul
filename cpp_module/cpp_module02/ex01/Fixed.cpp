/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:55:56 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 12:08:18 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;

    this->fixedValue = 0;
}
Fixed::Fixed(const Fixed& _fixed)
{
    std::cout << "Copy constructor called" << std::endl;

    this->fixedValue = _fixed.fixedValue;
}
Fixed::Fixed(const int _fixedValue)
{
    std::cout << "Int constructor called" << std::endl;

    this->fixedValue = _fixedValue << this->bit;
}
Fixed::Fixed(const float _fixedValue)
{
    std::cout << "Float constructor called" << std::endl;
    
    this->fixedValue = (int)(roundf(_fixedValue * (1 << this->bit)));
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& operand)
{
    std::cout << "Assignation operator called" << std::endl;

    if (this != &operand)
    {
        this->fixedValue = operand.getRawBits();
    }
    return *this;
}


int Fixed::getRawBits() const
{
    std::cout << "getRawBits member called" << std::endl;

    return fixedValue;
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member called" << std::endl;

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