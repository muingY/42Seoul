/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:55:50 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/09 13:56:10 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(Fixed& _fixed);
    ~Fixed();

    Fixed &operator=(const Fixed& operand);

    int getRawBits() const;
    void setRawBits(int const raw);

private:
    int fixedValue;
    static const int bit = 8;
};

#endif