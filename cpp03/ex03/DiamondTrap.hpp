/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:10:11 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/10 19:28:15 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAPP_HPP
#define DIAMONDTRAPP_HPP    

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
    	public:
		    DiamondTrap();
		    DiamondTrap(const std::string& name);
		    DiamondTrap(DiamondTrap const & src);
            ~DiamondTrap();
		    
            DiamondTrap	&operator=(DiamondTrap const & src);

            void whoAmI(void);
            using ScavTrap::attack;

};

#endif