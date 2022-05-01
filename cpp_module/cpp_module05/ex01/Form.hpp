/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 08:54:37 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/06 23:19:47 by hyungyyo         ###   ########.fr       */
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
    Form(std::string _name, unsigned int _accessGrade, unsigned int _executeGrade);
    Form(const Form& _form);
    ~Form();

    Form& operator=(const Form& operand);

    std::string getName() const;
    bool getBSign() const;
    unsigned int getSignGrade() const;
    unsigned int getExecuteGrade() const;

    void BeSigned(const Bureaucrat* bureaucrat);

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
};

std::ostream& operator<<(std::ostream& out, const Form& operand);

#endif