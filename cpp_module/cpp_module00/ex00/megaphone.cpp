/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:38:36 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/06 22:40:24 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }

    std::string str;
    for (int i = 1; i < argc; i++)
    {
        str = argv[i];
        for (int i = 0; i < (int)str.length(); i++)
            str[i] = toupper(str[i]);
        std::cout << str;
    }
    std::cout << std::endl;
    return (0);
}
