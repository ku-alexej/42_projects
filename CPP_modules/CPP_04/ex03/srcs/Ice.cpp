/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:38:07 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 13:10:18 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	// std::cout << "Ice copy constructor" << std::endl;
}

Ice::~Ice() {
	// std::cout << "Ice destructor" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	// std::cout << "Ice assignation operator" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Ice *Ice::clone() const {
	// std::cout << "Ice clone" << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
