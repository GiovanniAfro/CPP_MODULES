/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:02:19 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/05 15:00:16 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _numbers;
    
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();

        Span &operator=(const Span &other);

        void addNumber(int num);
        
        template <typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end)
        {
            _numbers.insert(_numbers.end(), begin, end); //(iterator position, InputIterator first, InputIterator last);

            if (_numbers.size() > _N)
                throw std::overflow_error("Cannot add more numbers, maximum capacity");     
        }


        int shortestSpan() const;
        int longestSpan()   const;
};

#endif