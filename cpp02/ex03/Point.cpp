/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:41:47 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/08 18:28:18 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) 
{ 
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y)
{ 
}

Point::Point(const Point& src)
{
    *this = src; 
}

Point::~Point(void)
{
}

Point&	Point::operator=(const Point& rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed&>(_x) = rhs.getX();
		const_cast<Fixed&>(_y) = rhs.getY();
	}
	return *this;
}

Point Point::operator-(const Point& other) const 
{
    return Point(_x - other.getX(), _y - other.getY());
}

Fixed Point::getX() const
{
    return _x;
}

Fixed Point::getY() const
{
    return _y;
}
