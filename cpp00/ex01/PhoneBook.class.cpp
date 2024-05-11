/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:02:07 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/08 15:16:42 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
    contactCount = 0;
}

PhoneBook::~PhoneBook(void) {};

void PhoneBook::addContact(void)
{
    Contact newContact;
    newContact.setContactInfo();

    if (newContact.getEmpty())
    {
        std::cout << "YOU FOOL, COMPLETE ALL THE INFO." << std::endl;
        return;
    }

    if (contactCount < 8 && !newContact.getEmpty())
    {
        contacts[contactCount] = newContact;
        contactCount++;
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        contacts[7] = newContact;
    }
}


void PhoneBook::getContact(void) const
{
    std::cout << "|   Index  |First Name| Last Name|  Nickname|" << std::endl;

    int validContacts = 0;
    for (int i = 0; i < contactCount; i++)
    {
        if (!contacts[i].getEmpty())
        {
            contacts[i].getSummary(validContacts);
            validContacts++;
        }
    }

    if (validContacts == 0)
    {
        std::cout << "No valid contacts to display" << std::endl;
        return;
    }

    int index;
    std::cout << std::endl;
    std::cout << "Enter the index of the contact to display: ";

    while (!(std::cin >> index) || index < 0 || index >= validContacts)
    {
        std::cout << "Invalid input. Please enter a valid index: "; 
        std::cin.clear(); //Questa funzione cancella lo stato di errore sul flusso di input. Questo è necessario perché se un'operazione di input fallisce, le successive operazioni di input falliranno anche se non viene cancellato lo stato di errore.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int validIndex = 0;
    for (int i = 0; i < contactCount; i++)
    {
        if (!contacts[i].getEmpty())
        {
            if (validIndex == index)
            {
                contacts[i].getDetails();
                break;
            }
            validIndex++;
        }
    }
}