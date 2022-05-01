/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:55:19 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/22 20:57:54 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <random>

class Base
{
public:
    virtual ~Base();
};

class A : public Base
{
public:
    virtual ~A();
};

class B : public Base
{
public:
    virtual ~B();
};

class C : public Base
{
public:
    virtual ~C();
};

Base* Generate(void);
void Identify(Base* p);

#endif