/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:40:42 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/30 15:59:29 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
    bRun = true;
    for (int i = 0; i < 8; i++)
        phoneData[i].bUsed = false;
}

void Phonebook::CmdControl(std::string input)
{
    if (input.compare("EXIT") == 0)
    {
        bRun = false;
        std::cout << "Goodbye" << std::endl;
    }
    else if (input.compare("ADD") == 0)
    {
        try
        {
            CmdAdd();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else if (input.compare("SEARCH") == 0)
    {
        try
        {
            CmdSearch();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cout << "Error: Undefined command. Check manual." << std::endl;
    }
}

void Phonebook::CmdAdd()
{
    for (int i = 0; i < 8; i++)
    {
        if (phoneData[i].bUsed == true)
        {
            if (i == 7)
            {
                throw std::out_of_range("Error: No empty space left.");
            }
            continue;
        }
        phoneData[i].bUsed = true;
        std::cout << "[Register a new contact]" << std::endl;
        std::cout << " - first name      : ";
        std::getline(std::cin, phoneData[i].firstname);
        std::cout << " - last name       : ";
        std::getline(std::cin, phoneData[i].lastname);
        std::cout << " - nickname        : ";
        std::getline(std::cin, phoneData[i].nickname);
        std::cout << " - login           : ";
        std::getline(std::cin, phoneData[i].login);
        std::cout << " - postal address  : ";
        std::getline(std::cin, phoneData[i].postaladdress);
        std::cout << " - email address   : ";
        std::getline(std::cin, phoneData[i].emailaddress);
        std::cout << " - phone number    : ";
        std::getline(std::cin, phoneData[i].phonenumber);
        std::cout << " - birthday date   : ";
        std::getline(std::cin, phoneData[i].birthday);
        std::cout << " - favorite meal   : ";
        std::getline(std::cin, phoneData[i].favoritemeal);
        std::cout << " - underwear color : ";
        std::getline(std::cin, phoneData[i].underwearcolor);
        std::cout << " - darkest secret  : ";
        std::getline(std::cin, phoneData[i].secret);
        std::cout << "----Regist done----" << std::endl << std::endl;
        break;
    }
}
void Phonebook::CmdSearch()
{
    DisplayPhonebook();
    if (!phoneData[0].bUsed)
        return;
    std::cout << "Index: ";
    int searchIndex;
    std::cin >> searchIndex;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    if (!(searchIndex >= 0 && searchIndex < 8))
    {
        throw std::out_of_range("Error: Wrong index.");
    }
    if (!phoneData[searchIndex].bUsed || std::cin.fail())
    {
        throw std::out_of_range("Error: Wrong index.");
    }
    std::cout << "[Contact data display]" << std::endl;
    std::cout << " - first name      : " << phoneData[searchIndex].firstname << std::endl;
    std::cout << " - last name       : " << phoneData[searchIndex].lastname << std::endl;
    std::cout << " - nickname        : " << phoneData[searchIndex].nickname << std::endl;
    std::cout << " - login           : " << phoneData[searchIndex].login << std::endl;
    std::cout << " - postal address  : " << phoneData[searchIndex].postaladdress << std::endl;
    std::cout << " - email address   : " << phoneData[searchIndex].emailaddress << std::endl;
    std::cout << " - phone number    : " << phoneData[searchIndex].phonenumber << std::endl;
    std::cout << " - birthday date   : " << phoneData[searchIndex].birthday << std::endl;
    std::cout << " - favorite meal   : " << phoneData[searchIndex].favoritemeal << std::endl;
    std::cout << " - underwear color : " << phoneData[searchIndex].underwearcolor << std::endl;
    std::cout << " - darkest secret  : " << phoneData[searchIndex].secret << std::endl << std::endl;
}

void PrintContant(std::string str)
{
    int wc = 0;

    for (int i = 0; i < (10 - (int)str.length()); i++)
    {
        std::cout << " ";
        wc++;
    }
    for (int i = 0; (wc < 10 && i < (int)str.length()); i++)
    {
        if (wc == 9 && str.length() > 10)
        {
            std::cout << ".";
            return;
        }
        std::cout << str[i];
        wc++;
    }
}

void Phonebook::DisplayPhonebook()
{
    std::cout << "*----------*----------*----------*----------*" << std::endl;
    std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
    std::cout << "*----------*----------*----------*----------*" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (phoneData[i].bUsed == true)
        {
            std::cout << "|         " << i << "|";
            PrintContant(phoneData[i].firstname);
            std::cout << "|";
            PrintContant(phoneData[i].lastname);
            std::cout << "|";
            PrintContant(phoneData[i].nickname);
            std::cout << "|" << std::endl;
            std::cout << "*----------*----------*----------*----------*" << std::endl;
        }
    }
}