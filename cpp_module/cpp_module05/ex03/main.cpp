/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:33:18 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/15 14:22:29 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Form* form;
    Intern intern;

    form = intern.MakeForm("shrubbery creation", "A");
    if (form == NULL)
    {
        std::cout << "Form error!" << std::endl;
    }
    else
    {
        delete form;
    }
    form = intern.MakeForm("robotomy request", "B");
    if (form == NULL)
    {
        std::cout << "Form error!" << std::endl;
    }
    else
    {
        delete form;
    }
    form = intern.MakeForm("presidential pardon", "C");
    if (form == NULL)
    {
        std::cout << "Form error!" << std::endl;
    }
    else
    {
        delete form;
    }
    form = intern.MakeForm("asdf", "C");
    if (form == NULL)
    {
        std::cout << "Form error!" << std::endl;
    }
    else
    {
        delete form;
    }

    return 0;
}