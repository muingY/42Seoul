/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 08:57:35 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/21 08:59:23 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

struct Data
{
    int numData;
    float floatData;
    char charData;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif