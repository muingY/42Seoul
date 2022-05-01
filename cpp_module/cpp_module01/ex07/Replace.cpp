/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:35:33 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/30 23:00:31 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string _targetFileName, std::string _replaceStr, std::string _replaceRetStr)
{
    this->targetFileName = _targetFileName;
    this->replaceStr = _replaceStr;
    this->replaceRetStr = _replaceRetStr;

    targetFile.open(targetFileName.c_str());
    if (!targetFile.is_open())
    {
        throw std::string("Error: Can not open target file.");
    }
    resultFile.open((targetFileName + ".replace").c_str());
    if (!resultFile.is_open())
    {
        throw std::string("Error: Can not open result file.");
    }
}
Replace::~Replace()
{
    if (targetFile.is_open())
    {
        targetFile.close();
    }
    if (resultFile.is_open())
    {
        resultFile.close();
    }
}

int Replace::StrReplaceAll(std::string* line)
{
    if (replaceStr == replaceRetStr)
        return 0;
    int rn = 0;
    int si = 0;
    while (line->find(replaceStr, si) != std::string::npos)
    {
        int pos = line->find(replaceStr, si);
        line->erase(pos, replaceStr.length());
        line->insert(pos, replaceRetStr);
        si = pos + replaceRetStr.length();
        rn++;
    }
    return rn;
}

int Replace::DoReplace()
{
    int rn = 0;
    std::string line;
    
    int i = 0;
    while (targetFile.peek() != EOF)
    {
        if (i > 0)
        {
            resultFile.write("\n", 1);
        }
        getline(targetFile, line);
        rn += StrReplaceAll(&line);
        resultFile.write(line.c_str(), line.length());
        i++;
    }
    return rn;
}