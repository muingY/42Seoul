/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:05:03 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/24 16:52:54 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &stack) { *this = stack; }
    ~MutantStack() {}
    
    MutantStack &operator=(const MutantStack &operand)
    {
    	std::stack<T>::operator = (operand);
	    return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin()
    {
    	return (this->c.begin());
    }
    iterator end()
    {
    	return (this->c.end());
    }
};

#endif