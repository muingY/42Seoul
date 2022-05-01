/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:40:31 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/24 21:58:13 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void DisplayMain()
{
    std::cout << ">>------- P H O N E   B O O K -------<<" << std::endl << std::endl;
    std::cout << "   ADD    : Regis new contact" << std::endl;
    std::cout << "   SEARCH : Display data and search" << std::endl;
    std::cout << "   EXIT   : Exit phonebook" << std::endl << std::endl;
}

int main()
{
    Phonebook phonebook;
    std::string input;

    while (phonebook.bRun)
    {
        std::cin.clear();
        DisplayMain();
        std::cout << "> ";
        std::getline(std::cin, input);
        phonebook.CmdControl(input);
    }
    return (0);
}