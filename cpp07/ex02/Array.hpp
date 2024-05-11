/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:37:07 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/30 13:20:45 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>

class Array
{
    private:
        T           *_elem;
        unsigned int _size;

    public:
        Array() : _elem(NULL),_size(0) {}
        Array(unsigned int n) : _size(n)
        {
            _elem = new T[_size]();
        }
        Array(const Array &other) : _size(other._size)
        {
            _elem = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _elem[i] = other._elem[i];
        }
        ~Array()
        {
            delete[] _elem;
        }

        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] _elem;
                _size = other._size;
                _elem = new T[_size];
        
                for (unsigned int i = 0; i < _size; i++)
                _elem[i] = other._elem[i];
            }
    
            return *this;
        }


        T     &operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out od bounds");
            return _elem[index];
        }

        unsigned int getSize() const
        {
            return _size;
        }
};

#endif