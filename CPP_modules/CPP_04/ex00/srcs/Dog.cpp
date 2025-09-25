/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:42 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 15:36:32 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << BLUE << "Dog - constructor default" << RESET << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << BLUE << "Dog - copy constructor" << RESET << std::endl;
}

Dog::~Dog() {
	std::cout << BLUE << "Dog - destructor" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

void Dog::makeSound() const {
	std::cout << BLUE << "Woof woof woof... Bark bark..." << RESET << std::endl;
}
