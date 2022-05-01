/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:05:17 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/24 15:46:03 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Span
{
public:
    Span(unsigned int _size);
    Span(const Span& _span);
    ~Span();

    Span& operator=(const Span& operand);

    void AddNumber(int n);
    template <class T>
    void AddNumber(T head, T tail)
    {
        if (static_cast<unsigned int>(std::distance(head, tail)) > (size - this->arr.size()))
        {
			throw std::length_error("Over max size");
        }
		else
		{
			while (head != tail)
			{
				AddNumber(*head);
				head++;
			}
		}
    }

    unsigned int ShortestSpan();
    unsigned int LongestSpan();

private:
    std::vector<int> arr;
    unsigned int size;
};

#endif