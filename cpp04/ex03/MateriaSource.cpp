/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:58:40 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/14 15:00:40 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        source[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.source[i])
            source[i] = other.source[i]->clone();
        else
            source[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete source[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        // Delete existing source
        for (int i = 0; i < 4; ++i)
        {
            delete source[i];
        }

        // Copy source
        for (int i = 0; i < 4; ++i)
        {
            if (other.source[i])
                source[i] = other.source[i]->clone();
            else
                source[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (source[i])
            continue;
        source[i] = m;
        break ;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (source[i] && source[i]->getType() == type)
        {
            return source[i]->clone();
        }
    }
    return NULL;
}

