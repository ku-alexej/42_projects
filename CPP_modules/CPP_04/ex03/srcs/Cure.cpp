/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:30:50 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 13:10:15 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	// std::cout << "Cure copy constructor" << std::endl;
}

Cure::~Cure() {
	// std::cout << "Cure destructor" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	// std::cout << "Cure assignation operator" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure *Cure::clone() const {
	// std::cout << "Cure clone" << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
