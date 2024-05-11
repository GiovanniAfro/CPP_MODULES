/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:41:47 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/08 18:31:17 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calcola i vettori dai vertici del triangolo
    Point ab = b - a;
    Point bc = c - b;
    Point ca = a - c;
    Point ap = point - a;
    Point bp = point - b;
    Point cp = point - c;

    // Calcola i prodotti vettoriali
    float pvetAB_AP = ab.getX().toFloat() * ap.getY().toFloat() - ab.getY().toFloat() * ap.getX().toFloat();
    float pvetBC_BP = bc.getX().toFloat() * bp.getY().toFloat() - bc.getY().toFloat() * bp.getX().toFloat();
    float pvetCA_CP = ca.getX().toFloat() * cp.getY().toFloat() - ca.getY().toFloat() * cp.getX().toFloat();


    // Controlla il segno dei prodotti vettoriali
    bool trianGLE = (pvetAB_AP >= 0 && pvetBC_BP >= 0 && pvetCA_CP >= 0) ||
                    (pvetAB_AP <= 0 && pvetBC_BP <= 0 && pvetCA_CP <= 0);

    // Restituisci true se il punto è all'interno del triangolo
    return trianGLE;
}
