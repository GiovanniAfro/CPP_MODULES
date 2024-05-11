/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:51:37 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/09 03:26:08 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "THE HERO: " << _name << " IS HERE" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    std::cout << "COpy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default destructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other) 
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "Assignemt operetor called" << std::endl;
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0)
    {
        std::cout << "THE HERO: " << _name << " AttAcks " << target << ", CAUSING " << _attackDamage << " OMG THIS DAMAGE" << std::endl;
         _energyPoints--;
    }
    else
        std::cout << "THE HERO: " << _name << " FINISH THE STAMINA" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (_hitPoints > 0) 
    {
        std::cout << "THE HERO: " << _name << " takes " << amount << " OF DAMAGE" << std::endl;
        _hitPoints = (amount > _hitPoints) ? 0 : _hitPoints - amount;
    } else 
        std::cout << "THE HERO: " << _name << " IS DEAD" << std::endl;
}

// Member function: beRepaired
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > 0) 
    {
        std::cout << "THE HERO: " << _name << " uUUAAAAA IM REPARING MYSELF " << amount << " OF THIS LIFE" << std::endl;
        _hitPoints += amount;
        _energyPoints--;
    } else 
        std::cout << "THE HERO: " << _name << " cant repaired something broken.." << std::endl;
}