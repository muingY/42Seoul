/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:33:17 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/05 19:21:46 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
    Bureaucrat(const std::string _name);
    Bureaucrat(const std::string _name, const unsigned int _grade);
    Bureaucrat(const Bureaucrat& _bureaucrat);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& operand);

    std::string getName() const;
    unsigned int getGrade() const;

    void GradeUp();
    void GradeDown();

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
    unsigned int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& operand);

#endif