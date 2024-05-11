/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:11:06 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/05 18:49:08 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{

    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    getContact(void) const;
    
    private:
        Contact contacts[8];
        int     contactCount;
        
};

#endif