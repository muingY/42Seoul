/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:58:39 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/25 19:52:59 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called." << std::endl;
}
Brain::Brain(const Brain& _brain)
{
    std::cout << "Brain copy constructor called." << std::endl;

    for (int i = 0; i < 100; i++)
    {
        this->ideaList[i] = _brain.ideaList[i];
    }
}
Brain::~Brain()
{
    std::cout << "Brain destroyed." << std::endl;
}

Brain& Brain::operator=(const Brain& operand)
{
    if (this != &operand)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideaList[i] = operand.ideaList[i];
        }
    }

    return *this;
}

std::string Brain::GetIdeaIndex(int i) const
{
    if (i >=0 && i < 100)
    {
        return "(Index error!)";
    }
    if (ideaList[i].empty())
    {
        return "(emply)";
    }
    
    return ideaList[i];
}
void Brain::SetIdeaIndex(int i, std::string idea)
{
    if ((i >=0 && i < 100) || idea.empty())
    {
        return;
    }
    ideaList[i] = idea;
}
bool Brain::AutoInsertIdea(std::string idea)
{
    bool isFull = true;

    for (int i = 0; i < 100; i++)
    {
        if (ideaList[i].empty())
        {
            isFull = false;
            ideaList[i] = idea;
            break;
        }
    }
    if (isFull)
    {
        return false;
    }
    return true;
}

void Brain::PrintStatus() const
{
    std::cout << "Brain do think." << std::endl;
}
void Brain::PrintIdeaList() const
{
    std::cout << "---Ideas---" << std::endl;

    bool isFullEmpty = true;
    for (int i = 0; i < 100; i++)
    {
        if (!ideaList[i].empty())
        {
            std::cout << " idea[" << i << "]: " << ideaList[i] << std::endl;
            isFullEmpty = false;
        }
    }
    if (isFullEmpty)
    {
        std::cout << " (empty idea list)" << std::endl;
    }
}