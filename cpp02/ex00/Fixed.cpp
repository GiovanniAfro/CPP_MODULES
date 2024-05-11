/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:25 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/04 15:03:23 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src; //è un'espressione che indica l'assegnazione di un oggetto al proprio oggetto corrente nella programmazione. Nel contesto del copy constructor che hai definito, questa espressione è utilizzata per copiare il contenuto di un oggetto Fixed (rappresentato da src) nell'oggetto corrente, cioè *this. this: È un puntatore implicito all'oggetto corrente. In questo contesto, this rappresenta l'indirizzo dell'oggetto corrente di tipo Fixed. *this: L'operatore di dereferenziazione * applicato a this restituisce l'oggetto effettivo, non l'indirizzo. Quindi, *this rappresenta l'oggetto corrente di tipo Fixed
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout<< "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}