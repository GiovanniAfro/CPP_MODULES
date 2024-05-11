/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:00:27 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/16 11:49:18 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    typedef AForm * (Intern::*createFormFunction)(const std::string &);

    struct FormInfo
    {
        const char *name;
        createFormFunction creator;
    };

    FormInfo forms[] = 
    {
        {"presidential pardon", &Intern::createPresidentialPardon},
        {"robotomy request", &Intern::createRobotomyRequest},
        {"shrubbery creation", &Intern::createShrubberyCreation}
    };

    AForm *newForm = NULL;

    for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i)
    {
        if (formName == forms[i].name)
        {
            newForm = (this->*(forms[i].creator))(target);
            break;
        }
    }

    if (newForm != NULL)
    {
        std::cout << "Intern creates " << *newForm << std::endl;
    }
    else
    {
        std::cerr << "Error: Unknown form type" << std::endl;
    }

    return newForm;
}

AForm *Intern::createPresidentialPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequest(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreation(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}
