/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:23:26 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/14 14:52:10 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *source[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        virtual ~MateriaSource();

        MateriaSource &operator=(const MateriaSource &other);

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif

// MateriaSource è una classe concreta che implementa l'interfaccia IMateriaSource.
// Ha un array di Materie come memoria.
// La funzione learnMateria(AMateria *m) aggiunge una Materia all'array.
// La funzione createMateria(std::string const &type) restituisce una nuova Materia clonando quella memorizzata che corrisponde al tipo specificato.
