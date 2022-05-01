/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:35:59 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/14 12:16:32 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("ShrubberyCreationForm", 145, 137, target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& _shrubberyCreateForm) : Form(_shrubberyCreateForm) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& operand)
{
    if (this != &operand)
    {
        this->operator=(operand);
    }
    return *this;
}

void ShrubberyCreationForm::ExecuteForm() const
{
    std::ofstream file;

    file.open(getTarget() + "_shrubbery", std::ios::out | std::ios::app);
    if (file.is_open())
    {
        file << "      /\\      " << std::endl;
        file << "     /\\*\\     " << std::endl;
        file << "    /\\O\\*\\    " << std::endl;
        file << "   /*/\\/\\/\\   " << std::endl;
        file << "  /\\O\\/\\*\\/\\  " << std::endl;
        file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
        file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file.close();
    }
}