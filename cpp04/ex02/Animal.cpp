/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:57:19 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/13 15:05:56 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknow")
{
    std::cout << "Constructor of Animal called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << "Copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor of Animal called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        _type = other._type;
        std::cout << "Overload Operator Animal called" << std::endl;
    }
    return *this;
}

void    Animal::makeSound() const
{
    std::cout << "The Animal make a generic sound" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}
