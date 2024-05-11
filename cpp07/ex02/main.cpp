/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:51 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/30 13:08:39 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> arr1;
    std::cout << "Size of arr1: " << arr1.getSize() << std::endl;

    Array<double> arr2(5);
    std::cout << "Size of arr2: " << arr2.getSize() << std::endl;

    Array<double> arr3 = arr2;
    std::cout << "Size of arr3: " << arr3.getSize() << std::endl;

    arr3[2] = 42.5;
    std::cout << "Element at index 2 of arr3: " << arr3[2] << std::endl;

    return 0;
}