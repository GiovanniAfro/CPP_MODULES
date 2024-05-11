/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:23:45 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/23 15:43:40 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() 
{
    Data data = {42, "Test"};
    Data* ptr = &data;

    uintptr_t serialized = Serializer::serialize(ptr);
    Data* deserialized = Serializer::deserialize(serialized);

    if (ptr == deserialized)
	{
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Data: " << deserialized->a << ", " << deserialized->b << std::endl;
    } 
	else 
        std::cout << "Serialization and deserialization failed!" << std::endl;                                          

    return 0;
}