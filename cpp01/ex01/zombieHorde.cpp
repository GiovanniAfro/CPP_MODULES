/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:17:04 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/22 12:21:13 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N]; //alloco N zombie sull'heap con new[]

    for (int i=0; i < N; i++)
        horde[i] = Zombie(name); //inizializzo ogni zombie con il secondo costruttore

    return horde; //ritorno puntatore al primo zombie
}