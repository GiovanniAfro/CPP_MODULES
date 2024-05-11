/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:06:19 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/13 16:14:37 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WronCat construcotr called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCAt Copy constrcuctor called" <<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        std::cout << "WrongCAt assigment operator called" << std::endl;
    }
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat make noises" << std::endl;
}