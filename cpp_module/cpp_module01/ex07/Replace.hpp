/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:35:31 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/30 21:54:46 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <fstream>
#include <iostream>

class Replace
{
/* functions */
public:
    Replace(std::string _targetFileName, std::string _replaceStr, std::string _replaceRetStr);
    ~Replace();

private:
    int StrReplaceAll(std::string* line);

public:
    int DoReplace();

/* variables */
private:
    std::ifstream targetFile;
    std::ofstream resultFile;

    std::string targetFileName;
    std::string replaceStr;
    std::string replaceRetStr;
};

#endif