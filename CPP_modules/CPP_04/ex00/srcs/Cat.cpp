/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:38 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 15:36:37 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << YELLOW << "Cat - constructor default" << RESET << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << YELLOW << "Cat - copy constructor" << RESET << std::endl;	
}

Cat::~Cat() {
	std::cout << YELLOW << "Cat - destructor" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

void Cat::makeSound() const {
	std::cout << YELLOW << "Meow meow meow... Prrrrr..." << RESET << std::endl;
}
