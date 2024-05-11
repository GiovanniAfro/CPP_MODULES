/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:53:36 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/13 22:10:55 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(const AMateria& other);
        AMateria(std::string const &type);
        virtual ~AMateria();

        AMateria& operator=(const AMateria& other);

        std::string const &getType() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif


// AMateria è una classe astratta che fornisce l'interfaccia di base per i tipi di Materia.
// Ha una funzione virtuale pura clone() che deve essere implementata dalle sue classi derivate.
// Ha una funzione virtuale use(ICharacter &target) che può essere sovrascritta nelle classi derivate per definire il comportamento dell'uso della Materia.
// Il distruttore virtuale virtual ~AMateria() assicura che il distruttore delle classi derivate venga chiamato correttamente.
