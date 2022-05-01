/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:33:18 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/08/07 22:17:38 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat* b = NULL;
    Form* form_LowLevel = NULL;
    Form* form_HighLevel = NULL;

    try
    {
        b = new Bureaucrat("James", 100);
        form_LowLevel = new Form("PublicData", 150, 150);
        form_HighLevel = new Form("TopSecret", 1, 1);

        b->SignForm(form_LowLevel);
        b->SignForm(form_HighLevel);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    if (b != NULL) { delete b; }
    if (form_LowLevel != NULL) { delete form_LowLevel; }
    if (form_HighLevel != NULL) { delete form_HighLevel; }
    return 0;
}