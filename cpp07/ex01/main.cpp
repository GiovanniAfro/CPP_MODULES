/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:12:36 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/30 12:28:43 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template< typename T >
void printElement(T const &element)
{
    std::cout << element << " ";
}

int main()
{
    int inArr[] = {1, 2, 3, 4, 5};
    double doArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char chArr[] = {'a', 'b', 'c', 'd', 'f'};

    std::cout << "intArray: ";
    iter(inArr, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "doubleArray: ";
    iter(doArr, 5, printElement<double>);
    std::cout << std::endl;

    std::cout << "charArray: ";
    iter(chArr, 5, printElement<char>);
    std::cout << std::endl;

    return 0;
}