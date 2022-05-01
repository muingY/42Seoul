/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:23:50 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/23 20:04:20 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vecNum;

    vecNum.push_back(1);
    vecNum.push_back(12);
    vecNum.push_back(123);
    vecNum.push_back(1234);
    vecNum.push_back(12345);

    try
    {
        while (true)
        {
            int sn;
            std::cout << "search number: ";
            std::cin >> sn;
            easyfind(vecNum, sn);
            std::cout << "...success!" << std::endl << std::endl;
        }
    }
    catch(const std::string& e)
    {
        std::cerr << e << '\n';
    }
    
    
    return 0;
}

//clang++ -o test *.cpp -Wall -Wextra -Werror -std=c++98