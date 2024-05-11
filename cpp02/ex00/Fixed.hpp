/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:38:24 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/04 14:53:31 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _value;
        static const int fractionalBits = 8; //Quindi, fractionalBits è utilizzato per indicare come interpretare e combinare le parti intere e frazionarie di un numero a virgola fissa nella tua classe. In questo caso, è un valore costante che determina la precisione della tua rappresentazione a virgola fissa.

    public:
        Fixed();
        Fixed(const Fixed& src); //Fixed(const Fixed& src);: Questo è il copy constructor. Viene chiamato quando crei un nuovo oggetto Fixed copiando un oggetto esistente Fixed. La sintassi const Fixed& src significa che il parametro src è una referenza costante a un oggetto Fixed.
        ~Fixed();

        Fixed& operator=(const Fixed& rhs); //Fixed& operator=(const Fixed& rhs);: Questo è l'operatore di assegnazione. Viene chiamato quando assegni un oggetto Fixed a un altro oggetto Fixed. La sintassi Fixed& indica che la funzione restituisce un riferimento a un oggetto Fixed (per permettere l'assegnazione concatenata).

        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif
