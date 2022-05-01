/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvTool.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:00:15 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/20 22:52:27 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvTool.hpp"

ConvTool::ConvTool() {}
ConvTool::ConvTool(ConvTool& _convTool) { (void)_convTool; }
ConvTool::~ConvTool() {}

ConvTool& ConvTool::operator=(const ConvTool& operand) { (void)operand; return *this; }

CONVTYPE ConvTool::GetConvType(const std::string data)
{
    CONVTYPE ret = IMPOSSIBLE;

    bool isFloatSimbol = false;
    //bool isFloat = false;
    //bool isNum = false;
    bool isChar = false;
    //bool isMixed = false;

    // NAN or NANF detect
    if (data == "nanf")
    {
        ret = NANF;
        return ret;
    }
    else if (data == "nan")
    {
        ret = NANN;
        return ret;
    }

    // CHAR detect
    if (data.length() == 1)
    {
        if (!(data[0] >= '0' && data[0] <= '9'))
        {
            isChar = true;
            ret = CHAR;
            return ret;
        }
    }

    // INT detect
    int checkSum = 0;
    for (int i = 0; i < static_cast<int>(data.length()); i++)
    {
        if (i == 0 && data[0] == '-')
        {
            i += 1;
            checkSum++;
        }
        if (!(data[i] >= '0' && data[i] <= '9'))
        {
            break;
        }
        checkSum++;
    }
    if (checkSum == static_cast<int>(data.length()))
    {
        ret = INT;
        return ret;
    }

    // DOUBLE detect
    checkSum = 0;
    for (int i = 0; i < static_cast<int>(data.length()); i++)
    {
        if (i == 0 && data[0] == '-')
        {
            i += 1;
            checkSum++;
        }
        if (!((data[i] >= '0' && data[i] <= '9') || data[i] == '.'))
        {
            break;
        }
        checkSum++;
    }
    if (checkSum == static_cast<int>(data.length()))
    {
        ret = DOUBLE;
        return ret;
    }

    // FLOAT detect
    if (data[data.length() - 1] == 'f')
    {
        isFloatSimbol = true;
    }
    if (isFloatSimbol)
    {
        checkSum = 0;
        for (int i = 0; i < static_cast<int>(data.length()) - 1; i++)
        {
            if (i == 0 && data[0] == '-')
            {
                i += 1;
                checkSum++;
            }
            if (!((data[i] >= '0' && data[i] <= '9') || data[i] == '.'))
            {
                break;
            }
            checkSum++;
        }
        if (checkSum == static_cast<int>(data.length()) - 1)
        {
            ret = FLOAT;
            return ret;
        }
    }

    // IMPOSSIBLE
    ret = IMPOSSIBLE;
    return ret;
}



bool ConvTool::ConvToChar(const std::string data, char* ret)
{
    if (ret == NULL) { return false; }
    
    CONVTYPE convType = GetConvType(data);

    if (convType == NANF || convType == NANN || convType == IMPOSSIBLE)
    {
        std::cout << "impossible";
        return false;
    }
    else if (convType == CHAR)
    {
        *ret = data[0];
        if (isprint(*ret) == 0)
        {
            std::cout << "Non displayable";
            return false;
        }
    }
    else if (convType == INT || convType == FLOAT || convType == DOUBLE)
    {
        int numConv = std::atoi(data.c_str());

        if (numConv > CHAR_MAX)
        {
            std::cout << "impossible";
            return false;
        }
        *ret = static_cast<char>(numConv);
        if (isprint(*ret) == 0)
        {
            std::cout << "Non displayable";
            return false;
        }
    }
    return true;
}

bool ConvTool::ConvToInt(const std::string data, int* ret)
{
    if (ret == NULL) { return false; }

    CONVTYPE convType = GetConvType(data);

    if (convType == NANF || convType == NANN || convType == IMPOSSIBLE)
    {
        std::cout << "impossible";
        return false;
    }
    else if (convType == INT)
    {
        *ret = static_cast<int>(std::atof(data.c_str()));
    }
    else if (convType == FLOAT || convType == DOUBLE)
    {
        *ret = static_cast<int>(std::atof(data.c_str()));
    }
    else if (convType == CHAR)
    {
        *ret = static_cast<int>(data[0]);
    }
    return true;
}

bool ConvTool::ConvToFloat(const std::string data, float* ret)
{
    if (ret == NULL) { return false; }

    CONVTYPE convType = GetConvType(data);

    if (convType == IMPOSSIBLE)
    {
        std::cout << "impossible";
        return false;
    }
    else if (convType == NANN || convType == NANF)
    {
        std::cout << "nanf";
        return false;
    }
    else if (convType == FLOAT || convType == DOUBLE)
    {
        *ret = static_cast<float>(std::atof(data.c_str()));
    }
    else if (convType == INT)
    {
        *ret = static_cast<float>(std::atoi(data.c_str()));
    }
    else if (convType == CHAR)
    {
        *ret = static_cast<float>(data[0]);
    }
    return true;
}

bool ConvTool::ConvToDouble(const std::string data, double* ret)
{
    if (ret == NULL) { return false; }

    CONVTYPE convType = GetConvType(data);

    if (convType == IMPOSSIBLE)
    {
        std::cout << "impossible";
        return false;
    }
    else if (convType == NANN || convType == NANF)
    {
        std::cout << "nan";
        return false;
    }
    else if (convType == FLOAT || convType == DOUBLE)
    {
        *ret = static_cast<double>(std::atof(data.c_str()));
    }
    else if (convType == INT)
    {
        *ret = static_cast<double>(std::atoi(data.c_str()));
    }
    else if (convType == CHAR)
    {
        *ret = static_cast<double>(data[0]);
    }
    return true;
}
