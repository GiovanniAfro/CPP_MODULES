/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:09:15 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/10 19:30:34 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap clap("ALAN");

    clap.attack("STU");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ScavTrap scav("STU");
    scav.attack("ALAN");
    scav.beRepaired(5);
    scav.guardGate();

    FragTrap frag("LESLI");
    frag.attack("tu");
    frag.highFivesGuys();

    DiamondTrap diamond1("Faker");
    DiamondTrap diamond2("gio");
    diamond1.whoAmI();
    diamond2.whoAmI();
    diamond1.attack("youuu");
    diamond1.takeDamage(10);
    diamond1.guardGate();
}