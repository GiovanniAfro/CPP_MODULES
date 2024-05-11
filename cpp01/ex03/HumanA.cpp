/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:52:05 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/17 14:57:31 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon& weapon) : _name(name), _weaponRef(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const
{
    std::cout << _name << " attacks with their " << _weaponRef.getType() << std::endl;
}

