/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:10:48 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/13 17:14:32 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
    std::cout << "Dog created!" << std::endl;
}

Dog::Dog(const Dog& other) : _brain(new Brain(*(other._brain)))
{
    std::cout << "Dog copied!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed!" << std::endl;
    delete _brain;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assigned!" << std::endl;
    if (this != &other)
    {
        delete _brain;
        _brain = new Brain(*(other._brain));
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return _brain->getIdea(index);
}
