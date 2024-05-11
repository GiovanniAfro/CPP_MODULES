/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:51:42 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/14 20:13:56 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int _grade;

        void    checkGrade(int newGrade);

    public:
        class GradeTooHighExecption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowEception : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);
		
		Bureaucrat& operator=(const Bureaucrat& other);

        void    executeForm(const AForm &form) const;
        const std::string& getName() const;
        int getGrade() const;

        void incGrade();
        void decGrade();
        void signForm(AForm &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif