/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 08:59:46 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/22 20:51:32 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
    Data data;
    data.numData = 42;
    data.floatData = 3.141592f;
    data.charData = 'Y';

    std::cout << "[Original Data]" << std::endl;
    std::cout << "num data: " << data.numData << std::endl;
    std::cout << "float data: " << data.floatData << std::endl;
    std::cout << "char data: " << data.charData << std::endl;

    uintptr_t raw = serialize(&data);
    std::cout << "[Serialized Data]" << std::endl;
    std::cout << "serialized: " << raw << std::endl;

    Data* ret = deserialize(raw);
    std::cout << "[Deserialized Data]" << std::endl;
    std::cout << "num data: " << ret->numData << std::endl;
    std::cout << "float data: " << ret->floatData << std::endl;
    std::cout << "char data: " << ret->charData << std::endl;

    delete ret;

    return 0;
}