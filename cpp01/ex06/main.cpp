/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:56:11 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/22 12:17:16 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <log level>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(av[1]);

    return 0;
}