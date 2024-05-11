/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:28:28 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/11 21:54:44 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
}

Contact::~Contact(void) {};

void Contact::setContactInfo(void)
{
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) //è un'istruzione condizionale che controlla se è stata raggiunta la fine del file (EOF). Nel contesto dell'input dell'utente, ciò potrebbe verificarsi se l'utente invia un segnale EOF (di solito premendo Ctrl+D sui sistemi Unix o Ctrl+Z su Windows).
        exit(1);
    if (input.empty())
    {
        std::cout << "First name cannot be empty. Please try again." << std::endl;
        return;
    }
    firstName = input;

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(1);
    if (input.empty())
    {
        std::cout << "Last name cannot be empty. Please try again." << std::endl;
        return;
    }
    lastName = input;

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(1);
    if (input.empty())
    {
        std::cout << "Nickname cannot be empty. Please try again." << std::endl;
        return;
    }
    nickName = input;

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(1);
    if (input.empty())
    {
        std::cout << "Phone number cannot be empty. Please try again." << std::endl;
        return;
    }
    phoneNumber = input;

    std::cout << "Enter darkest secret :D : ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(1);
    if (input.empty())
    {
        std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
        return;
    }
    darkestSecret = input;
}

bool Contact::getEmpty(void) const
{
    return firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty();//La funzione .empty() è un membro della classe std::string in C++ che viene utilizzato per verificare se una stringa è vuota o contiene caratteri. Restituisce true se la stringa è vuota (ossia non contiene caratteri) e false se contiene almeno un carattere.
}

void Contact::getSummary(int index) const
{
    std::cout << "|" << std::setw(10) << index << "|"; //La funzione std::setw è una funzione della libreria <iomanip> in C++ che imposta la larghezza del campo di output per gli oggetti di output come std::cout. Questa funzione viene comunemente utilizzata per formattare l'output in modo che i dati siano allineati in colonne.
    std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
    std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
    std::cout << std::setw(10) << (nickName.length() > 10 ? nickName.substr(0, 9) + "." : nickName) << "|" << std::endl;
}

void Contact::getDetails(void) const
{
    std::cout << "Fisrt Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}