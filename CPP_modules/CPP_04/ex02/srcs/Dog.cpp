/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:42 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 17:48:53 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << BLUE << "Dog - constructor default" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << BLUE << "Dog - copy constructor" << RESET << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << BLUE << "Dog - destructor" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->_type = other.getType();
		*this->_brain = *other._brain;
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << BLUE << "Woof woof woof... Bark bark..." << RESET << std::endl;
}

void Dog::setType(std::string type) {
	this->_type = type;
}

void Dog::addIdea(std::string idea) {
	this->_brain->addIdea(idea);
}

void Dog::getIdeas() const {
	this->_brain->getIdeas();
}

void Dog::setIdea(int index, std::string idea) {
	this->_brain->setIdea(index, idea);
}
