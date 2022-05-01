/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:53:12 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/23 19:16:32 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main()
{
    Array<int> arrNum(5);
    Array<std::string> arrString(2);
    
    try
    {
        arrNum[0] = 1;
        arrNum[1] = 12;
        arrNum[2] = 123;
        arrNum[3] = 1234;
        arrNum[4] = 12345;

        std::cout << "---Int array test---" << std::endl;
        for (int i = 0; i < static_cast<int>(arrNum.Length()); i++)
        {
            std::cout << arrNum[i] << std::endl;
        }

        arrString[0] = "I am";
        arrString[1] = "the danger.";

        std::cout << "---String array test---" << std::endl;
        for (int i = 0; i < static_cast<int>(arrString.Length()) + 1; i++)
        {
            std::cout << arrString[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}