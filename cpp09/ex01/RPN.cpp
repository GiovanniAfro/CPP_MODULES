/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:32:04 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/13 12:52:56 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _operands = other._operands;
    return *this;
}

double RPN::stod(const std::string& str, size_t* pos = NULL)
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

bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double RPN::applyOperator(double a, double b, char tt)
{
    switch (tt)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw std::invalid_argument("Division by zero");
        return a / b;
    
    default:
        throw std::invalid_argument("Incalid operator");
    }
}

double RPN::calculate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) && token.length() == 1)
            _operands.push(RPN::stod(token));
        else if (isOperator(token[0]) && token.length() == 1) 
        {
            double operands2 = _operands.top();
            _operands.pop();
            double operands1 = _operands.top();
            _operands.pop();

            double result = applyOperator(operands1, operands2, token[0]);
            _operands.push(result);
        }
        else
            throw std::invalid_argument("Invalid token");
    }

    if (_operands.size() != 1)
        throw std::invalid_argument("Invalid expression");

    return _operands.top();
}
