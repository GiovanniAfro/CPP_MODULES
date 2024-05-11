/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:21:34 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/10 16:30:38 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    try
    {
        checkGrade(_grade);
    }
    catch (const std::exception & e)
    {
        std::cerr << "Exeption caught in Bureaucrat constructor : " << e.what() << std::endl;
        this->_grade = 75;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
   std::cout << "Default Destrcuctor called for " << _name << std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incGrade()
{
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decGrade()
{
    checkGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::checkGrade(int newGrade) 
{
    if (newGrade < 1)
        throw GradeTooHighExecption();
    else if (newGrade > 150)
        throw GradeTooLowEception();
}

const char* Bureaucrat::GradeTooHighExecption::what() const throw ()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowEception::what() const throw()
{
    return("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}



