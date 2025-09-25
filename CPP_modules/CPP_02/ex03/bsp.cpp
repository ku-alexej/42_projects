/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:07:25 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/11 16:40:47 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float abs(float f) {
	return (f < 0 ? -f : f);
}

static float zone(const Point p1, const Point p2, const Point p3) {
	Fixed f1(p1.getX() * p2.getY() - p3.getX() * p2.getY());
	Fixed f2(p3.getX() * p1.getY() - p1.getX() * p3.getY());
	Fixed f3(p2.getX() * p3.getY() - p2.getX() * p1.getY());
	Fixed result(f1 + f2 + f3);

	return (abs(result.toFloat()) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float zoneABP = zone(a, b, point);
	float zoneBCP = zone(b, c, point);
	float zoneCAP = zone(c, a, point);
	float zoneTriangle = zone(a, b, c);

	return ((zoneABP && zoneBCP && zoneCAP) && (zoneTriangle == zoneABP + zoneBCP + zoneCAP));
}