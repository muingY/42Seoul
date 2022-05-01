/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:23:49 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/23 19:59:31 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T& t, int n)
{
    typename T::iterator iter;

    iter = std::find(t.begin(), t.end(), n);
    if (iter == t.end())
        throw(std::string("There is no same thing."));
    return (*iter);
}

#endif