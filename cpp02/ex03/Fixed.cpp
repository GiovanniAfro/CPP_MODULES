/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:25 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/06 17:05:21 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int value) : _value(value << fractionalBits)
{
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << fractionalBits)))
{
}

Fixed::Fixed(const Fixed& src)
{
    *this = src; //è un'espressione che indica l'assegnazione di un oggetto al proprio oggetto corrente nella programmazione. Nel contesto del copy constructor che hai definito, questa espressione è utilizzata per copiare il contenuto di un oggetto Fixed (rappresentato da src) nell'oggetto corrente, cioè *this. this: È un puntatore implicito all'oggetto corrente. In questo contesto, this rappresenta l'indirizzo dell'oggetto corrente di tipo Fixed. *this: L'operatore di dereferenziazione * applicato a this restituisce l'oggetto effettivo, non l'indirizzo. Quindi, *this rappresenta l'oggetto corrente di tipo Fixed
}

Fixed::~Fixed() 
{
}

Fixed& Fixed::operator=(const Fixed& rhs) 
{
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const 
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat() const
{
    return (static_cast<float>(this->_value) / static_cast<float>(1 << fractionalBits));
}

int Fixed::toInt() const
{
    return  this->_value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _value != other._value;
}

// Implementazione degli operatori aritmetici
Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Implementazione degli operatori di incremento/decremento
Fixed& Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed& Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --_value;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

//condizione ? valore_se_vera : valore_se_falsa;
