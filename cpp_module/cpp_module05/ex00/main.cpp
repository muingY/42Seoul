/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:33:18 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/06 08:35:17 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat* b = NULL;

    try
    {
        std::string name;
        unsigned int grade;

        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Grade: ";
        std::cin >> grade;

        b = new Bureaucrat(name, grade);

        std::cout << *b << std::endl;
        std::cout << "(1 = GradeUp, 2 = GradeDown, 3 = Exit)" << std::endl;

        int input;
        bool isRun = true;
        while (isRun)
        {
            std::cin >> input;
            switch (input)
            {
            case 1:
                std::cout << "Call GradeUp" << std::endl;
                b->GradeUp();
                std::cout << *b << std::endl;
                break;
            case 2:
                std::cout << "Call GradeDown" << std::endl;
                b->GradeDown();
                std::cout << *b << std::endl;
                break;
            case 3:
                std::cout << "Exit!" << std::endl;
                isRun = false;
                break;
            default:
                break;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
    if (b != NULL)
    {
        delete b;
    }
    return 0;
}