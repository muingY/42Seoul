/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:35:35 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/01 14:26:36 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Check your argument. (TargetFile, ReplaceTargetString, ReplaceString)" << std::endl;
        return 1;
    }
    
    Replace* replace = NULL;
    try
    {
        replace = new Replace(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));
        int rn = replace->DoReplace();
        std::cout << rn << " replacements complete." << std::endl;
    }
    catch(const std::string& e)
    {
        std::cerr << e << '\n';
    }
    if (replace != NULL)
    {
        delete replace;
    }
    return 0;
}