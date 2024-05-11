/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:41:24 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/05 16:00:19 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av) 
{    
    if (ac == 1) 
    {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    for (int i = 1; i < ac; i++) 
    {
        for (int j = 0; av[i][j]; j++) 
        {
            char c = av[i][j];
            if (c >= 'a' && c <= 'z') 
                c = toupper(c);
            std::cout << c;
        }
        if (i < ac - 1) 
            std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
