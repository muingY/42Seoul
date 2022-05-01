/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:29:50 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/15 11:32:52 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 72, 45, target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& _presidentialPardonForm) : Form(_presidentialPardonForm) {}
PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& operand)
{
    if (this != &operand)
    {
        this->operator=(operand);
    }
    return *this;
}

void PresidentialPardonForm::ExecuteForm() const
{
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}