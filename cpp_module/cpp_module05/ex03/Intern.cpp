/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:53:48 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/15 14:22:03 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& _intern) { (void)_intern; }
Intern::~Intern() {}

Intern& Intern::operator=(const Intern& operand) { (void)operand; return *this; }

Form* NewFormShu(std::string target) { return new ShrubberyCreationForm(target); }
Form* NewFormRobo(std::string target) { return new RobotomyRequestForm(target); }
Form* NewFormPres(std::string target) { return new PresidentialPardonForm(target); }

Form* Intern::MakeForm(std::string name, std::string target)
{
    Form* ret = NULL;
    static std::string formNameList[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    Form* (*formNewFuncs[3])(std::string) = { &NewFormShu, &NewFormRobo, &NewFormPres };

    for (int i = 0; i < 3; i++)
    {
        if (formNameList[i] == name)
        {
            std::cout << "Intern create " << name << std::endl;
            ret = formNewFuncs[i](target);
            break;
        }
    }
    if (ret == NULL)
    {
        std::cout << "Form create fail. unknown form name." << std::endl;
    }

    return ret;
}