/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:15:19 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/26 01:19:15 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheStack()
{
    std::cout << "---call ponyOnTheStack---" << std::endl;

    Pony pony;
    pony.ShowStatus();
}

void ponyOnTheHeap()
{
    std::cout << "---call ponyOnTheHeap---" << std::endl;

    Pony* pony = new Pony(70, 20, 100);
    pony->ShowStatus();
    delete pony;
}

int main()
{
    ponyOnTheStack();
    std::cout << std::endl;
    ponyOnTheHeap();
    return 0;
}