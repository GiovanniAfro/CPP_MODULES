/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:02:19 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/17 15:12:40 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponPtr(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon)
{
    _weaponPtr = &weapon;
}

void HumanB::attack() const
{
    if (_weaponPtr)
        std::cout << _name << " attacks with their " << _weaponPtr->getType() << std::endl;
    else
        std::cout << _name << " : I HAVE FISTS IN MY HANDS " << std::endl;
}
