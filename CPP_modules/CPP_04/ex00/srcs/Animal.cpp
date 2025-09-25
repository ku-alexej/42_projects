/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:32 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 15:36:39 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << GREEN << "Animal - constructor default" << RESET << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << GREEN << "Animal - copy constructor" << RESET << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cout << GREEN << "Animal - destructor" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

void Animal::makeSound() const {
	std::cout << GREEN << "*strange animal sounds*" << RESET << std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}
