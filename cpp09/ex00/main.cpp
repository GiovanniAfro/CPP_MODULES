/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:05:12 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/10 13:45:58 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Utilizzo: " <<  av[0] << " file_input\n";
        return 1;
    }

    std::ifstream inputFile(av[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Errore: impossibile aprire il file.\n";
        return 1;
    }
    
    std::string header;
    std::getline(inputFile, header);

    BitcoinExchange btc;

    if (!btc.loadExchangeRates("data.csv"))
    {
        std::cerr << "Errore: impossibile caricare i tassi di cambio. \n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string date;
        double value;
        if (btc.parseLine(line, date, value))
        {
            // Calcoliamo il valore dei bitcoin
            double bitcoinValue = btc.calculateBitcoinValue(date, value);
            if (bitcoinValue >= 0)  
            {
                std::cout << std::fixed << std::setprecision(5);
                std::cout << date << " => " << value << " = " << bitcoinValue <<std::endl;
            }
        } 
    }

    inputFile.close();
    return 0;
}
 