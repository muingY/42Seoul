/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:39:13 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/23 21:33:35 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
/* Functions */
public:
    Brain();
    Brain(const Brain& _brain);
    ~Brain();

    Brain& operator=(const Brain& operand);

    std::string GetIdeaIndex(int i) const;
    void SetIdeaIndex(int i, std::string idea);
    bool AutoInsertIdea(std::string idea);

    void PrintStatus() const;
    void PrintIdeaList() const;

private:
    std::string ideaList[100];
};

#endif