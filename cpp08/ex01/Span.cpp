/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:02:24 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/05 14:55:42 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : _N(n)
{
    _numbers.reserve(_N);
}

Span::Span(const Span &other)
{
    *this = other;
}

Span::~Span()
{
    std::cout << "Default destructor called" <<std::endl;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int num)
{
    if (_numbers.size() < _N)
        _numbers.push_back(num);
    else
        throw std::overflow_error("Cannot add more numbers, maximum capacity");
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); i++)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");
    
    std::vector<int>::const_iterator minElement = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxElement = std::max_element(_numbers.begin(), _numbers.end());

    int span = *maxElement - *minElement;

    return span;
}