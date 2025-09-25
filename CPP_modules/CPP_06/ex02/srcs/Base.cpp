/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:22:43 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/15 20:42:49 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class A;
class B;
class C;

Base	*generate(void) {
	static bool isSeeded = false;
	if (!isSeeded) {
		std::srand(std::time(NULL));
		isSeeded = true;
	}

	int option = rand() % 3;
	switch (option) {
		case 0:
			std::cout << "A created" << std::endl;
			return (new A);
		case 1:
			std::cout << "B created" << std::endl;
			return (new B);
		default:
			std::cout << "C created" << std::endl;
			return (new C);
	}
}

void	identify(Base *p) {
	if (!p)
		std::cout << "NULL";
	else if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	std::cout << std::endl;
}

void	identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &e) {}

	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &e) {}

	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &e) {}
}
