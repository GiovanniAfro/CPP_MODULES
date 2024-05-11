/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:25:00 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/13 17:14:25 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
    std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat& other) : _brain(new Brain(*(other._brain)))
{
    std::cout << "Cat copied!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed!" << std::endl;
    delete _brain;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assigned!" << std::endl;
    if (this != &other)
    {
        delete _brain;
        _brain = new Brain(*(other._brain));
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
    _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return _brain->getIdea(index);
}
