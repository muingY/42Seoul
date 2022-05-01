/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 08:59:32 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/22 13:43:12 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t serialize(Data* ptr)
{
    char* ret = new char[sizeof(ptr->numData) + sizeof(ptr->floatData) + sizeof(ptr->charData)];

    *reinterpret_cast<int*>(ret) = ptr->numData;
    *reinterpret_cast<float*>(ret + sizeof(ptr->numData)) = ptr->floatData;
    *reinterpret_cast<char*>(ret + sizeof(ptr->numData) + sizeof(ptr->floatData)) = ptr->charData;
    
    return reinterpret_cast<uintptr_t>(ret);
}

Data* deserialize(uintptr_t raw)
{
    Data* ret = new Data;

    char* rawp = reinterpret_cast<char*>(raw);
    ret->numData = *(reinterpret_cast<int*>(rawp));
    ret->floatData = *(reinterpret_cast<float*>(rawp + sizeof(ret->numData)));
    ret->charData = *(reinterpret_cast<char*>(rawp + sizeof(ret->numData) + sizeof(ret->floatData)));

    return ret;
}