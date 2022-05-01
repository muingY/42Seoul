/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:07:38 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/27 15:15:32 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    
    std::string* pstr = &str;
    std::string& rstr = str;

    std::cout << "pointer   : " << *pstr << std::endl;
    std::cout << "reference : " << rstr << std::endl;
    return 0;
}