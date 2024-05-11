/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:39:41 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/17 14:45:39 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string type) : _type(type) {}

Weapon::~Weapon () {}

const std::string& Weapon::getType() const
{
    return _type;
}

void   Weapon::setType(const std::string& newType)
{
    _type = newType;
}