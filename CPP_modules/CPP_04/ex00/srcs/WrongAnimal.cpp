/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:29:09 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 15:36:44 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << RED << "WrongAnimal - constructor default" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << RED << "WrongAnimal - copy constructor" << RESET << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal - destructor" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << RED << "*strange and wrong animal sounds*" << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}
