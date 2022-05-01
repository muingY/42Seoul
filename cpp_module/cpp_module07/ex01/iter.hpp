/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:34:05 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/22 21:48:23 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* arr, unsigned int b, void (*func)(T*))
{
    for (int i = 0; static_cast<unsigned int>(i) < b; i++)
    {
        func(&arr[i]);
    }
}

void func1_modified(int* a)
{
    *a *= 10;
}
void func2_print(int* b)
{
    std::cout << "func2_print: " << *b << std::endl;
}

template <typename T>
void func3_print(T* p)
{
    std::cout << "func3_print: " << *p << std::endl;
}

#endif