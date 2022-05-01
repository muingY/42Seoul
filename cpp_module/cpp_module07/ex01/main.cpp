/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:34:20 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/22 21:51:32 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int arrNum[] = { 1, 2, 3, 4, 5 };
    iter(arrNum, 5, func1_modified);
    std::cout << "-----" << std::endl;
    iter(arrNum, 5, func2_print);
    std::cout << "-----" << std::endl;
    iter(arrNum, 5, func3_print);
    std::cout << "-----" << std::endl;

    float arrfloat[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    iter(arrfloat, 5, func3_print);

    return 0;
}