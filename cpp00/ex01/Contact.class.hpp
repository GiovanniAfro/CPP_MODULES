/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:58:06 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/07 14:20:53 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <stdlib.h>

class Contact
{

    public:
        Contact(void);
        ~Contact(void);
        void    setContactInfo(void);
        bool    getEmpty(void) const;
        void    getSummary(int  index) const;
        void    getDetails(void) const;

    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif