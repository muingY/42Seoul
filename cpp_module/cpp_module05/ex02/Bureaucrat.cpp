/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:33:20 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/15 12:22:24 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name)
{
    this->name = _name;
    this->grade = 150;
}
Bureaucrat::Bureaucrat(const std::string _name, const unsigned int _grade)
{
    this->name = _name;
    if (_grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (_grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = _grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& _bureaucrat)
{
    this->name = _bureaucrat.name;
    this->grade = _bureaucrat.grade;
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& operand)
{
    if (this != &operand)
    {
        this->name = operand.name;
        this->grade = operand.grade;
    }

    return *this;
}

std::string Bureaucrat::getName() const { return this->name; }
unsigned int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::GradeUp()
{
    if (grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    grade--;
}
void Bureaucrat::GradeDown()
{
    if (grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    grade++;
}

void Bureaucrat::SignForm(Form* form)
{
    try
    {
        form->BeSigned(this);
    }
    catch(const std::exception& e)
    {
        std::cout << name << " cannot sign " << form->getName() << std::endl << " -reason: ";
        std::cerr << e.what() << '\n';
        return;
    }
    std::cout << name << " sign " << form->getName() << std::endl;
}
void Bureaucrat::ExecuteForm(Form const & form)
{
    try
    {
        form.Execute(*this);
    }
    catch(const std::string& e)
    {
        std::cout << name << " cannot execute " << form.getName() << std::endl << " -reason: ";
        std::cerr << e << '\n';
    }
    std::cout << name << " execute " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade data can not less than 1.";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade data can not more than 150.";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& operand)
{
    out << operand.getName() << ", bureaucrat grade " << operand.getGrade() << std::endl;
    return out;
}