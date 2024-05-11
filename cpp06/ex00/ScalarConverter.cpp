/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:13:21 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/23 14:26:42 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
    return ;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default constructor called of Sca" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

int ScalarConverter::stoi(const std::string& str, size_t* pos = NULL) 
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

double ScalarConverter::stod(const std::string& str, size_t* pos = NULL)
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
    if (str[i] == '-' || str[i] == '+')
    {
        negativo = (str[i] == '-');
        ++i;
    }

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

void ScalarConverter::convert(const std::string& literal)
{
        // Convert to char
    try 
    {
        char charResult = static_cast<char>(ScalarConverter::stoi(literal));
        
        if (literal.find("inff") != std::string::npos)
            std::cout << "char : impossible" << std::endl;
        else if (literal.find("-inff") != std::string::npos)
            std::cout << "char : impossible" << std::endl;
        else if (literal.find("nan") != std::string::npos)
            std::cout << "char : impossible" << std::endl;
        else
        {
            if (isprint(charResult))
                std::cout << "char: '" << charResult << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        
    } 
    catch(const std::out_of_range& e)
    {
        std::cout << "char: Overflow or out of range" << std::endl;
    } 
    catch(const std::invalid_argument& e)
    {
        std::cout << "char: Conversion not possible" << std::endl;
    }

        // Convert to int
    try 
    {
        int intResult = static_cast<int>(ScalarConverter::stoi(literal));
        if (literal.find("inff") != std::string::npos)
            std::cout << "int : impossible, you are INTing ahahah, i'm sad" << std::endl;
        else if (literal.find("-inff") != std::string::npos)
            std::cout << "int : impossible, you are INTing ahahah, i'm sad" << std::endl;
        else if (literal.find("nan") != std::string::npos)
            std::cout << "int : impossible, you are INTing ahahah, i'm sad" << std::endl;
        else
            std::cout << "int: " << intResult << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "int: Overflow or out of range, you are INTing ahahah, i'm sad" << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << "int: Conversion not possible, you are INTing ahahah, i'm sad" << std::endl;
    }

        // Convert to float
    try 
    {
        size_t pos;
        float floatResult = static_cast<float>(ScalarConverter::stod(literal, &pos));

        // Handle special cases: -inff, +inf, nanf
        if (literal.find("inff") != std::string::npos)
            std::cout << "float: +inf" << std::endl;
        else if (literal.find("-inff") != std::string::npos)
            std::cout << "float: -inf" << std::endl;
        else if (literal.find("nan") != std::string::npos)
            std::cout << "float: nanf" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
    }
    catch(const std::out_of_range& e)
    {
            std::cout << "float: Overflow or out of range" << std::endl;
    } 
    catch(const std::invalid_argument& e) 
    {
            std::cout << "float: Conversion not possible" << std::endl;
    }

        // Convert to double
    try 
    {
        size_t pos;
        double doubleResult = static_cast<double>(ScalarConverter::stod(literal, &pos));

            // Handle special cases: -inf, +inf, nan
        if (literal.find("inf") != std::string::npos)
            std::cout << "double: " << ((literal[0] == '-') ? "-" : "+") << "inf" << std::endl;
        else if (literal.find("nan") != std::string::npos)
            std::cout << "double: nan" << std::endl;
        else
            std::cout << "double: " << std::fixed << std::setprecision(1) << doubleResult << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "double: Overflow or out of range" << std::endl;
    } 
    catch(const std::invalid_argument& e)
    {
        std::cout << "double: Conversion not possible" << std::endl;
    }
}