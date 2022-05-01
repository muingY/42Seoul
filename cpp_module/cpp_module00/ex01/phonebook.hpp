/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:40:48 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/24 22:19:58 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits.h>

struct PhoneCell
{
    bool        bUsed;
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string login;
    std::string postaladdress;
    std::string emailaddress;
    std::string phonenumber;
    std::string birthday;
    std::string favoritemeal;
    std::string underwearcolor;
    std::string secret;
};

class Phonebook
{
/* functions */
public:
    Phonebook();

    void CmdControl(std::string input);

    void CmdAdd();
    void CmdSearch();

    void DisplayPhonebook();

/* variables */
private:
    PhoneCell phoneData[8];

public:
    bool bRun;
};

#endif