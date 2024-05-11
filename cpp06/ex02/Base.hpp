/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:51:04 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/25 13:38:56 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Base
{
    public: 
        virtual ~Base();
};

class A : public Base{};

class B : public Base{};

class C : public Base{};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif