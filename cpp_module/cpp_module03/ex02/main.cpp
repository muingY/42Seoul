/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:13:41 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/07/12 20:29:01 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap* fragBot = new FragTrap("MINE");

    fragBot->Attack("UFO");
    fragBot->TakeDamage(10);
    fragBot->BeRepaired(100);

    delete fragBot;
    return 0;
}