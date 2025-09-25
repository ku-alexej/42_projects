/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:07:29 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/11 17:01:14 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

static std::string	boolToAnswer(bool flag) {
	return (flag ? "yes" : "no");
}

int	main(void) {
	{
		Point	a(0, 0);
		Point	b(3, 6);
		Point	c(7, 1);
		Point	p1(4, 3);	// inside
		Point	p2(6, 6);	// outside
		Point	p3(7, 1);	// in C
		Point	p4(2, 4);	// in AB

		std::cout << "Triangle: a" << a << ",  b" << b << ",  c" << c << std::endl;
		std::cout << "Is p1" << p1 << " inside the triangle? " << boolToAnswer(bsp(a, b, c, p1)) << std::endl;
		std::cout << "Is p2" << p2 << " inside the triangle? " << boolToAnswer(bsp(a, b, c, p2)) << std::endl;
		std::cout << "Is p3" << p3 << " inside the triangle? " << boolToAnswer(bsp(a, b, c, p3)) << std::endl;
		std::cout << "Is p4" << p4 << " inside the triangle? " << boolToAnswer(bsp(a, b, c, p4)) << std::endl;
	}
	{
		Point	a(0, 0);
		Point	b(0, -10);
		Point	c(-10, -10);
		Point	p1(4, 3);	// outside
		Point	p2(-1, -5);	// inside
		Point	p3(-10, -10);	// in C
		Point	p4(0, -5);	// in AB

		std::cout << "Triangle: a" << a << ",  b" << b << ",  c" << c << std::endl;
		std::cout << "Is p1" << p1 << " inside the triangle? " << boolToAnswer(bsp(a, b, c, p1)) << std::endl;
		std::cout << "Is p2" << p2 << " inside the triangle? " << boolToAnswer(bsp(a, b, c, p2)) << std::endl;
		std::cout << "Is p3" << p3 << " inside the triangle? " << boolToAnswer(bsp(a, b, c, p3)) << std::endl;
		std::cout << "Is p4" << p4 << " inside the triangle? " << boolToAnswer(bsp(a, b, c, p4)) << std::endl;
	}
	return (0);
}
