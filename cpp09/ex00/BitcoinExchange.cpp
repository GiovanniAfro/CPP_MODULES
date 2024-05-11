/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:56 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/12 16:02:17 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _exchangeRates = other._exchangeRates;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

int BitcoinExchange::stoi(const std::string& str, size_t* pos = NULL) 
{
    size_t i = 0;
    int risultato = 0;
    bool negativo = false;

    // Salta gli spazi iniziali
    while (i < str.length() && isspace(str[i]))
        ++i;

    // Gestisci il segno
    if (str[i] == '-' || str[i] == '+')
    {
        negativo = (str[i] == '-');
        ++i;
    }

    // Converti le cifre in intero
    while (i < str.length() && isdigit(str[i]))
    {
        int cifra = str[i] - '0';
        if (risultato > (INT_MAX - cifra) / 10)
            throw std::out_of_range("stoi: Overflow or out of range");
        risultato = risultato * 10 + cifra;
        ++i;
    }

    // Imposta la posizione del primo carattere non numerico
    if (pos != NULL)
        *pos = i;

    // Applica il segno
    return (negativo ? -risultato : risultato);
}

double BitcoinExchange::stod(const std::string& str, size_t* pos = NULL)
{
    size_t i = 0;
    double risultato = 0.0;
    bool negativo = false;
    bool parteDecimale = false;
    double potenzaDecimale = 1.0;

    // Salta gli spazi iniziali
    while (i < str.length() && isspace(str[i]))
        ++i;

    // Gestisci il segno
    if (str[i] == '-')
    {
        negativo = (str[i] == '-');
        i++;
    }
    else if (str[i] == '+')
        i++;

    // Converti le cifre intere
    while (i < str.length() && (isdigit(str[i]) || str[i] == '.')) 
    {
        if (str[i] == '.')
            parteDecimale = true;
        else 
        {
            if (parteDecimale)
            {
                potenzaDecimale *= 0.1;
                risultato = risultato + (str[i] - '0') * potenzaDecimale;
            } 
            else 
            {
                if (risultato > (1.7976931348623158e+308 - (str[i] - '0')) / 10)
                    throw std::out_of_range("stod: Overflow or out of range");
                risultato = risultato * 10.0 + (str[i] - '0');
            }
        }
        ++i;
    }

    // Imposta la posizione del primo carattere non numerico
    if (pos != NULL)
        *pos = i;

    // Applica il segno
    return (negativo ? -risultato : risultato);
}

bool BitcoinExchange::loadExchangeRates(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string date;
            std::string rateStr;
            if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
            {
                try
                {
                    double rate = BitcoinExchange::stod(rateStr);
                    _exchangeRates[date] = rate;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
        file.close();
        return true;
    }
    return false;
} 

bool BitcoinExchange::parseLine(const std::string& line, std::string& date, double& value)
{
    std::istringstream iss(line);
    std::string token;

    if (std::getline(iss, token, '|'))
    {
        // Parsing dell'anno, mese e giorno
        int year, month, day;
        try
        {
            year = BitcoinExchange::stoi(token.substr(0, 4));
            month = BitcoinExchange::stoi(token.substr(5, 2));
            day = BitcoinExchange::stoi(token.substr(8, 2));
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Error: bad input => " << token << std::endl;
            return false;
        }

        // Controllo che l'anno sia valido (tra 1900 e 2100, ad esempio)
        if (year < 2009 || year > 2100)
        {
            std::cerr << "Error: bad input => " << token << std::endl;
            return false;
        }

        // Controllo che il mese sia compreso tra 1 e 12
        if (month < 1 || month > 12)
        {
            std::cerr << "Error: bad input => " << token << std::endl;
            return false;
        }

        // Definizione del numero di giorni per ogni mese (senza considerare gli anni bisestili)
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Controllo che il giorno sia valido per il mese specificato
        if (day < 1 || day > daysInMonth[month - 1])
        {
            std::cerr << "Error: bad input => " << token << std::endl;
            return false;
        }

        date = token;

        if (std::getline(iss, token))
        {
            try
            {
                size_t pos;
                value = BitcoinExchange::stod(token, &pos);

                // Controllo che il numero abbia il formato corretto e sia compreso tra 0 e 1000
                if (pos != token.length())
                {
                    std::cerr << "Error: bad input => " << token << std::endl;
                    return false;
                }
                if (value < 0)
                {
                    std::cerr << "Error: not a positive number." << std::endl;
                    return false;
                }
                if (value > 1000)
                {
                    std::cerr << "Error: too large a number." << std::endl;
                    return false;
                }
                
                return true;
            }
            catch(const std::exception& e)
            {
                return false;
            }    
        }
    }
    return false;
}

double BitcoinExchange::calculateBitcoinValue(const std::string& date, double value)
{
    std::string closestDate = findClosetDate(date);
    std::map<std::string, double>::const_iterator it = _exchangeRates.find(closestDate);

    if (it != _exchangeRates.end())
        return value * it->second;
    return -1;
}

std::string BitcoinExchange::findClosetDate(const std::string& date)
{
    std::map<std::string, double>::iterator it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.begin() || it->first == date)
        return it->first;
    else if (it == _exchangeRates.end())
    {
        std::map<std::string, double>::iterator last = _exchangeRates.begin();
        std::map<std::string, double>::iterator next = last;

        while (next != _exchangeRates.end())
        {
            last = next;
            next++;
        }

        return last->first;
    }
    else
    {
        --it;
        return it->first;
    }
}