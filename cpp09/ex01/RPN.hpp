/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:23:04 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/13 12:53:44 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        ~RPN();

        RPN& operator=(const RPN &other);
        
        double calculate(const std::string& expression);

    private:
        std::stack<double> _operands;

        bool isOperator(char c);
        double applyOperator(double a, double b, char op);
        double stod(const std::string& str, size_t* pos);
};

#endif