/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:21:45 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/10 16:22:13 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat br1("Silvio", 100);
        std::cout << br1 << std::endl;

        br1.incGrade();
        std::cout << "After increasing grade: " << br1 << std::endl;

        br1.decGrade();
        std::cout << "After decresing grade: " << br1 << std::endl;

        Bureaucrat br2("Giorgio", 160);
        Bureaucrat br3("Ascano", -1);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exeption caught in main: " << e.what() << std::endl;
    }

    return 0;
}