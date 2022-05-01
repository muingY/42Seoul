/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:16:52 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/15 11:29:32 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("RobotomyRequestForm", 72, 45, target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& _robotomyRequestForm) : Form(_robotomyRequestForm) {}
RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& operand)
{
    if (this != &operand)
    {
        this->operator=(operand);
    }
    return *this;
}

void RobotomyRequestForm::ExecuteForm() const
{
    std::cout << "Biiiiiiiiing- drrrrrrrr..." << std::endl;

    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<int> dis(0, 99);

    int rand_num = dis(gen);

    if (rand_num < 50)
    {
        std::cout << getTarget() << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << getTarget() << " failed to be robotomize." << std::endl;
    }
}