/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:53:49 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/13 22:10:56 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

std::string const &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses an empty materia on " << target.getName() << " *" << std::endl;
}


// L'implementazione del costruttore e del distruttore.
// L'implementazione di getType() restituisce il tipo della Materia.
// L'implementazione di use(ICharacter &target) è una funzione di default che può essere sovrascritta nelle classi derivate.
