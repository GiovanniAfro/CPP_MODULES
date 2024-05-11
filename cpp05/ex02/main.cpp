/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:04:27 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/14 20:19:29 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat br("SILVIO", 50);
        ShrubberyCreationForm sh("Garden");
        RobotomyRequestForm ro("Alice");
        PresidentialPardonForm pa("Italia");

        std::cout << br << std::endl;
        std::cout << sh << std::endl;
        std::cout << ro << std::endl;
        std::cout << pa << std::endl;

        br.signForm(sh);
        br.signForm(ro);
        br.signForm(pa);

        br.executeForm(sh);
        br.executeForm(ro);
        br.executeForm(pa);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
