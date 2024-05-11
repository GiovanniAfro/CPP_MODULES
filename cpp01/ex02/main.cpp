/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:10:36 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/17 14:18:27 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() 
{
    // String variable initialized 
    std::string string = "HI THIS IS BRAIN";

    // stringPTR: A pointer to the string
    std::string *stringPTR = &string;

    // stringREF: A reference to the string
    std::string &stringREF = string;

    // Printing memory addresses
    std::cout << "Memory address of the string variable: " << &string << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // Printing values
    std::cout << "Value of the string variable: " << string << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
