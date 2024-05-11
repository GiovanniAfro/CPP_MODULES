/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:46:01 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/17 15:19:44 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        const   Weapon& _weaponRef; //Il riferimento weaponRef viene inizializzato con questo oggetto, e da quel momento in poi, weaponRef può essere utilizzato solo per accedere alle funzioni di Weapon ma non per modificarne lo stato (poiché è un riferimento costante).

    public:
        HumanA(std::string  name, const Weapon& weapon);
        ~HumanA();
        void attack() const;
};

#endif