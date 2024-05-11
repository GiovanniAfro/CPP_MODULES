/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:30:10 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/03 18:55:53 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfynd.hpp"

int main()
{
    std::vector<int> vec(1, 0);

    try
    {
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::vector<int>::iterator result1 = easyfind(vec, 3);
        std::cout << "Value found at position: " << std::distance(vec.begin(), result1) << std::endl;

        // std::vector<int>::iterator result2 = easyfind(vec, 10);
        // std::cout << "Value found at position: " << std::distance(vec.begin(), result2) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exeption : " << e.what() << std::endl;
    }

    return 0;
}