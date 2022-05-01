/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:01:39 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/15 12:27:24 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string _name, unsigned int _accessGrade, unsigned int _executeGrade, std::string _target)
{
    this->name = _name;
    this->bSign = false;
    if (_accessGrade < 1 || _executeGrade < 1)
    {
        throw Form::GradeTooHighException();
    }
    if (_accessGrade > 150 || _executeGrade > 150)
    {
        throw Form::GradeTooLowException();
    }
    this->signGrade = _accessGrade;
    this->executeGrade = _executeGrade;
    this->target = _target;
}
Form::Form(const Form& _form)
{
    this->name = _form.name;
    this->bSign = _form.bSign;
    this->signGrade = _form.signGrade;
    this->executeGrade = _form.executeGrade;
    this->target = _form.target;
}
Form::~Form() {}

Form& Form::operator=(const Form& operand)
{
    if (this != &operand)
    {
        this->name = operand.name;
        this->bSign = operand.bSign;
        this->signGrade = operand.signGrade;
        this->executeGrade = operand.executeGrade;
        this->target = operand.target;
    }

    return *this;
}

std::string Form::getName() const { return name; }
bool Form::getBSign() const { return bSign; }
unsigned int Form::getSignGrade() const { return signGrade; }
unsigned int Form::getExecuteGrade() const { return executeGrade; }
std::string Form::getTarget() const { return target; }

void Form::BeSigned(const Bureaucrat* bureaucrat)
{
    if (bureaucrat->getGrade() > signGrade)
    {
        throw Form::GradeTooLowException();
    }
    bSign = true;
}
void Form::Execute(const Bureaucrat& executor) const
{
    if (!bSign)
    {
        throw std::string("No signed form, execute denine");
    }
    if (executor.getGrade() > executeGrade)
    {
        throw std::string("Grade too low");
    }
    this->ExecuteForm();
}

void Form::ExecuteForm() const {}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form detected too high grade.";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Form detected too low grade.";
}

std::ostream& operator<<(std::ostream& out, const Form& operand)
{
    out << operand.getName() << " form : [sign = " << operand.getBSign() << ", sign grade = " << operand.getSignGrade() << ", execute grade = " << operand.getExecuteGrade() << "]" << std::endl;
    return out;
}