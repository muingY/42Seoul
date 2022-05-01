/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 08:54:37 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/12 23:02:17 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form(std::string _name, unsigned int _signGrade, unsigned int _executeGrade, std::string _target);
    Form(const Form& _form);
    virtual ~Form();

    Form& operator=(const Form& operand);

    std::string getName() const;
    bool getBSign() const;
    unsigned int getSignGrade() const;
    unsigned int getExecuteGrade() const;
    std::string getTarget() const;

    void BeSigned(const Bureaucrat* bureaucrat);
    void Execute(const Bureaucrat& executor) const;

private:
    virtual void ExecuteForm() const;

public:
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

private:
    std::string name;
    bool bSign;
    unsigned int signGrade;
    unsigned int executeGrade;
    std::string target;
};

std::ostream& operator<<(std::ostream& out, const Form& operand);

#endif