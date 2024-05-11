/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:58:26 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/10 11:26:45 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called " << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "Scavtrap parameterized constructor called." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src._name)
{
    std::cout << "Scavtrap copy constructor called." << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap()
{
    std::cout<< "Destrcutor of scav was called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is dead! " << _name <<" cant attacks"<< std::endl;
        return;   
    }
    if (_energyPoints > 0)
    {
        std::cout << "THE SCAVTRAP: " << _name << " AttAcks " << target << ", CAUSING " << _attackDamage << " OMG THIS DAMAGE" << std::endl;
         _energyPoints--;
    }
    else
        std::cout << "THE SCAVTRAP: " << _name << " FINISH THE STAMINA" << std::endl;
}