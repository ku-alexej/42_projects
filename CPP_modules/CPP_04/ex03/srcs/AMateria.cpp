/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:09:39 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 13:08:57 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	// std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type) {
	// std::cout << "AMateria type constructor" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	// std::cout << "AMateria copy constructor" << std::endl;
	*this = other;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	// std::cout << "AMateria assignation operator" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

const std::string &AMateria::getType() const {
	// std::cout << "AMateria getType" << std::endl;
	return (this->_type);
}

void AMateria::use(ICharacter &target) {
	// std::cout << "AMateria use" << std::endl;
	(void)target;
}

