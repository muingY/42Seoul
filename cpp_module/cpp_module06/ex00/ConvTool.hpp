/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvTool.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:00:12 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/20 21:49:30 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVTOOL_HPP
#define CONVTOOL_HPP

#include <string>
#include <iostream>

enum CONVTYPE
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NANF,
    NANN,
    IMPOSSIBLE
};

class ConvTool
{
/* Function */
public:
    ConvTool();
    ConvTool(ConvTool& _convTool);
    ~ConvTool();

    ConvTool& operator=(const ConvTool& operand);

    static CONVTYPE GetConvType(const std::string data);

    static bool ConvToChar(const std::string data, char* ret);
    static bool ConvToInt(const std::string data, int* ret);
    static bool ConvToFloat(const std::string data, float* ret);
    static bool ConvToDouble(const std::string data, double* ret);
};

#endif
