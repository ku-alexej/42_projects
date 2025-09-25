/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:07:32 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/11 16:46:40 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::~Point() {
}

Point &Point::operator=(const Point &point) {
	if (this != &point) {
		(Fixed)this->_x = point.getX();
		(Fixed)this->_y = point.getY();
	}
	return (*this);
}

Fixed Point::getX() const {
	return (this->_x);
}

Fixed Point::getY() const {
	return (this->_y);
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
	out << "(" << point.getX() << "," << point.getY() << ")";
	return (out);
}
