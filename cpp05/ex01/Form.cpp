/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:22:28 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/12 15:58:27 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(1), _gradeToExecute(1){}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
/*     try
    { */
        if (gradeToSign < 0 || gradeToExecute < 0)
            throw GradeTooHighExeption();
        else if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowExeption();
 /*    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught in Form constructor: " << e.what() << std::endl;
        throw;
    } */
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::~Form()
{
    std::cout << "Default Form destrcutor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &br)
{
/*     try
    { */
        if (br.getGrade() <= _gradeToSign)
            _signed = true;
        else
            throw GradeTooLowExeption();
/*     }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught in beSigned: " << e.what() << std::endl;
        throw;
    } */
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName()
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute()
       << ", Signed: " << (form.getSigned() ? "Yes" : "No");

    return os;
}

const char *Form::GradeTooHighExeption::what() const throw()
{
    return "Grade is too high, you fool";
}

const char *Form::GradeTooLowExeption::what() const throw()
{
    return "Grade is too low, you fools";
}