/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:07:15 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/11 17:27:28 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static std::string	boolToAnswer(bool flag) {
	return (flag ? "yes" : "no");
}

int main(void) {

	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;

	Fixed		c(10);
	Fixed 		d(10);
	Fixed 		e(5);

	std::cout << "c > d  " << boolToAnswer(c > d) << std::endl;
	std::cout << "c < d  " << boolToAnswer(c < d) << std::endl;
	std::cout << "c >= d " << boolToAnswer(c >= d) << std::endl;
	std::cout << "c <= d " << boolToAnswer(c <= d) << std::endl;
	std::cout << "c == d " << boolToAnswer(c == d) << std::endl;
	std::cout << "c != d " << boolToAnswer(c != d) << std::endl;

	std::cout << "c > e  " << boolToAnswer(c > e) << std::endl;
	std::cout << "c < e  " << boolToAnswer(c < e) << std::endl;
	std::cout << "c >= e " << boolToAnswer(c >= e) << std::endl;
	std::cout << "c <= e " << boolToAnswer(c <= e) << std::endl;
	std::cout << "c == e " << boolToAnswer(c == e) << std::endl;
	std::cout << "c != e " << boolToAnswer(c != e) << std::endl;

	std::cout << "c + e =" << c + e << std::endl;
	std::cout << "c - e =" << c - e << std::endl;
	std::cout << "c * e =" << c * e << std::endl;
	std::cout << "c / e =" << c / e << std::endl;
	
	return 0;
}
