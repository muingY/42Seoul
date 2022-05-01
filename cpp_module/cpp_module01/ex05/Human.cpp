/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:31:22 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/27 16:47:19 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human()
{
    brain = new Brain;
}
Human::~Human()
{
    delete brain;
}

Brain& Human::getBrain()
{
    return *brain;
}

std::string Human::identify()
{
    return brain->identify();
}