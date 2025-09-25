/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:07:34 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/11 16:45:53 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const Point &point);
		Point(const float x, const float y);
		~Point();

		Point	&operator=(const Point &point);

		Fixed	getX() const;
		Fixed	getY() const;
		
	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif