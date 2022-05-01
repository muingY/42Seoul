/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:52:54 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/23 19:03:59 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
public:
    Array()
    {
        this->size = 0;
        this->arr = new T[size];
    }
    Array(unsigned int n)
    {
        this->size = n;
        this->arr = new T[size];
    }
    Array(const Array& _array)
    {
        this->size = _array.Length();
        this->arr = new T[size];
        for (int i = 1; i < size; i++)
        {
            this->arr[i] = _array[i];
        }
    }
    ~Array()
    {
        delete[] arr;
    }

    Array& operator=(Array& operand)
    {
        if (this != &operand)
        {
            delete[] this;
            this->size = operand.Length();
            this->arr = new T[size];
            for (int i = 1; i < size; i++)
            {
                this->arr[i] = operand[i];
            }
        }
        return *this;
    }
    T& operator[](long long index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Array index is out of range.");
        }
        return arr[index];
    }

    size_t Length() const
    {
        return static_cast<size_t>(size);
    }

private:
    T* arr;
    unsigned int size;
};

#endif