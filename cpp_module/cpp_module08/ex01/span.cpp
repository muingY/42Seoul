/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:05:32 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/24 15:58:22 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int _size)
{
    this->size = _size;
}
Span::Span(const Span& _span)
{
    this->size = _span.size;
    this->arr = _span.arr;
}
Span::~Span() {}

Span& Span::operator=(const Span& operand)
{
    if (this != &operand)
    {
        this->size = operand.size;
        this->arr = operand.arr;
    }
    return *this;
}

void Span::AddNumber(int n)
{
    if (arr.size() >= size)
    {
        throw std::out_of_range("Span out of range");
    }
    arr.push_back(n);
}

unsigned int Span::ShortestSpan()
{
    std::vector<int> sortArr = arr;
    std::sort(sortArr.begin(), sortArr.end());

    unsigned int span = sortArr[1] - sortArr[0];
    for (int i = 1; i < static_cast<int>(sortArr.size()) - 1; i++)
    {
        if (static_cast<unsigned int>(sortArr[i + 1] - sortArr[i]) < span)
        {
            span = sortArr[i + 1] - sortArr[i];
        }
    }

    return span;
}
unsigned int Span::LongestSpan()
{
    std::vector<int> sortArr = arr;
    std::sort(sortArr.begin(), sortArr.end());

    unsigned int span = sortArr[sortArr.size() - 1] - sortArr[0];

    return span;
}