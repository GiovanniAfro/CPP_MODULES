/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:57:37 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/11 17:11:17 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat; //La forward declaration (dichiarazione anticipata),è utilizzata per informare il compilatore che esiste una classe chiamata Bureaucrat, anche se i dettagli completi della sua implementazione non sono ancora noti a questo punto.

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        class GradeTooHighExeption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowExeption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        Form();
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        ~Form();

        Form &operator=(const Form &other);

        const std::string &getName() const;
        bool getSigned() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;

        void beSigned(const Bureaucrat &br);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif