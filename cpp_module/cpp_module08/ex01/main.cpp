/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:05:38 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/24 16:03:09 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <list>

int main()
{
    Span sp = Span(5);
    sp.AddNumber(5);
    sp.AddNumber(3);
    sp.AddNumber(17);
    sp.AddNumber(9);
    sp.AddNumber(11);
    std::cout << sp.ShortestSpan() << std::endl;
    std::cout << sp.LongestSpan() << std::endl;



    Span sp2 = Span(10000);

    std::vector<int> spanPool;
    spanPool.reserve(10000);
    for (int i = 0; i < 10000; i++)
    {
        spanPool.push_back(i * 3);
    }
    sp2.AddNumber(spanPool.begin(), spanPool.end());

    std::cout << sp2.ShortestSpan() << std::endl;
    std::cout << sp2.LongestSpan() << std::endl;
    return 0;
}

//clang++ -o test *.cpp -Wall -Wextra -Werror -std=c++98