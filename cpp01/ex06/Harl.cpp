/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:59:12 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/22 13:15:29 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void    Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "WARNING:  think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void(Harl:: *LogFunction[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string log[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    size_t i = 0;
    while (level.compare(log[i]) && i < 4)
        i++;

    switch(i)
    {
        case 0:
        {
            (this->*LogFunction[0])();
        }
        case 1:
        {
            (this->*LogFunction[1])();
        }
        case 2:
        {
            (this->*LogFunction[2])();
        }
        case 3:
        {
            (this->*LogFunction[3])();
            break;
        }
        default:
        {
            std::cerr << "bruw what is this: " << level << std::endl;
            break;
        }
    }

}


// .find() e .end()
// In C++, il metodo .find(key) di una mappa restituisce un iteratore che punta all'elemento corrispondente alla chiave specificata key. Se l'elemento non viene trovato, .find() restituirà un iteratore uguale a .end().

// it = logFunctions.find(level);: Questa riga cerca l'elemento nella mappa logFunctions con la chiave level e restituisce un iteratore (it) che punta a quell'elemento se viene trovato. Se non viene trovato, it sarà uguale a logFunctions.end().

// it != logFunctions.end(): Questa condizione viene utilizzata per verificare se l'iteratore it punta a un elemento valido nella mappa o se è uguale a .end(). Se è uguale a .end(), significa che l'elemento cercato non è presente nella mappa.

// Sintassi this->*(it->second)
// Questa parte della sintassi è specifica per l'utilizzo di puntatori a membri di una classe.

// it->second: Qui it è un iteratore che punta a un elemento della mappa, e it->second restituisce il valore associato a quella chiave, che è un puntatore a funzione membro.

// (this->*(it->second))(): Questa è una sintassi comune per chiamare una funzione membro attraverso un puntatore a funzione membro. Spieghiamo i passaggi:

// this->*: È l'operatore per accedere ai membri di una classe attraverso un puntatore a membro. Nel nostro caso, this è un puntatore all'oggetto corrente, e * è l'operatore per dereferenziare il puntatore.

// (it->second): Questa parte restituisce il puntatore a funzione membro associato al livello di log.

// (): Infine, le parentesi tonde vengono utilizzate per chiamare effettivamente la funzione membro puntata dal puntatore a funzione membro.

// Quindi, la linea di codice this->*(it->second)(); sta chiamando dinamicamente la funzione membro associata al livello di log corrente sull'oggetto this della classe Harl.