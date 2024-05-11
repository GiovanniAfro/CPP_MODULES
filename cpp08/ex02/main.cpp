/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:00:09 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/04 10:07:34 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    // Aggiungiamo alcuni elementi alla pila
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(42);

    // Utilizziamo iteratori per attraversare la pila
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Testiamo la copia da MutantStack a std::stack
    std::stack<int> s(mstack);

    return 0;
}
