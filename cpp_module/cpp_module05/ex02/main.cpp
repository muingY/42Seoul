/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:33:18 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/15 12:26:54 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat* bureaucrats[3];

    bureaucrats[0] = new Bureaucrat("TreeBu", 130);
    bureaucrats[1] = new Bureaucrat("RoboBu", 30);
    bureaucrats[2] = new Bureaucrat("AllPublic", 1);
    
    Form* formSh = new ShrubberyCreationForm("Tree");
    Form* formRobo = new RobotomyRequestForm("Plant");
    Form* formPres = new PresidentialPardonForm("Dorumpu");

    bureaucrats[0]->SignForm(formSh);
    bureaucrats[0]->ExecuteForm(*formSh);
    bureaucrats[0]->ExecuteForm(*formRobo);
    bureaucrats[0]->ExecuteForm(*formPres);

    std::cout << "-------" << std::endl;

    bureaucrats[1]->SignForm(formRobo);
    bureaucrats[1]->ExecuteForm(*formSh);
    bureaucrats[1]->ExecuteForm(*formRobo);
    bureaucrats[1]->ExecuteForm(*formPres);

    std::cout << "-------" << std::endl;

    bureaucrats[2]->SignForm(formPres);
    bureaucrats[2]->ExecuteForm(*formSh);
    bureaucrats[2]->ExecuteForm(*formRobo);
    bureaucrats[2]->ExecuteForm(*formPres);

    delete bureaucrats[0];
    delete bureaucrats[1];
    delete bureaucrats[2];
    delete formSh;
    delete formRobo;
    delete formPres;

    return 0;
}