/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:55:56 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/14 12:08:14 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Defauld constructor called" << std::endl;

    this->fixedValue = 0;
}
Fixed::Fixed(Fixed& _fixed)
{
    std::cout << "Copy constructor called" << std::endl;

    this->fixedValue = _fixed.fixedValue;
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