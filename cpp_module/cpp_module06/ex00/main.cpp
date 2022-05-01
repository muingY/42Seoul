/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:00:13 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/20 23:07:28 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvTool.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "Error: No input." << std::endl;
        return 0;
    }

    char charData;
    int intData;
    float floatData;
    double doubleData;

    bool bConv;

    std::cout << "char: ";
    bConv = ConvTool::ConvToChar(std::string(argv[1]), &charData);
    if (bConv) { std::cout << charData << std::endl; }
    else { std::cout << std::endl; }

    std::cout << "int: ";
    bConv = ConvTool::ConvToInt(std::string(argv[1]), &intData);
    if (bConv) { std::cout << intData << std::endl; }
    else { std::cout << std::endl; }

    std::cout << "float: ";
    bConv = ConvTool::ConvToFloat(std::string(argv[1]), &floatData);
    if (bConv)
    {
        std::cout << std::setprecision(1) << std::fixed << floatData;
        std::cout << "f" << std::endl;
    }
    else { std::cout << std::endl; }
    
    std::cout << "double: ";
    bConv = ConvTool::ConvToDouble(std::string(argv[1]), &doubleData);
    if (bConv)
    {
        std::cout << std::setprecision(1) << floatData;
        std::cout << std::endl;
    }
    else { std::cout << std::endl; }
    
    return 0;
}