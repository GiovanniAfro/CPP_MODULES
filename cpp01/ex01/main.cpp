/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:16:45 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/17 11:27:29 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    const int hordeSize = 5;
    Zombie* zombieHordePtr = zombieHorde(hordeSize, "ZombieHorde");

    for (int i=0; i < hordeSize; i++)
        zombieHordePtr[i].announce();

    delete [] zombieHordePtr;

    return 0;
}