/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:41:47 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:10 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() 
{
    // Crea istanze di Point e Fixed per i test
    Point a(0.0f, 0.0f);
    Point b(1.0f, 0.0f);
    Point c(0.0f, 1.0f);

    Point insidePoint(0.2f, 0.2f);
    Point outsidePoint(2.0f, 2.0f);

    // Esegui la funzione bsp sui punti di cui sopra
    bool insideResult = bsp(a, b, c, insidePoint);
    bool outsideResult = bsp(a, b, c, outsidePoint);

    // Stampa i risultati
    std::cout << "Inside Point Result: " << std::boolalpha << insideResult << std::endl;
    std::cout << "Outside Point Result: " << std::boolalpha << outsideResult << std::endl;

    return 0;
}
