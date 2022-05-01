/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:55:41 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/22 21:04:26 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}
A::~A() {}
B::~B() {}
C::~C() {}

Base* Generate(void)
{
    int rand_num;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2);

    Base* ret = NULL;
    rand_num = dis(gen);

    switch (rand_num)
    {
    case 0:
        std::cout << "Gen A" << std::endl;
        ret = new A;
        break;
    case 1:
        std::cout << "Gen B" << std::endl;
        ret = new B;
        break;
    case 2:
        std::cout << "Gen C" << std::endl;
        ret = new C;
        break;
    default:
        break;
    }

    if (ret == NULL)
    {
        std::cout << "Generate fail!" << std::endl;
    }

    return ret;
}

void Identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "Identified...A" << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL)
    {
        std::cout << "Identified...B" << std::endl;
    }
    else if (dynamic_cast<C*>(p) != NULL)
    {
        std::cout << "Identified...C" << std::endl;
    }
}