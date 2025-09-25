/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:15:43 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 14:17:08 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("unknown") {
	// std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name) {
	// std::cout << "Character name constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &other) {
	// std::cout << "Character copy constructor" << std::endl;
	*this = other;
}

Character::~Character() {
	// std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character &Character::operator=(const Character &other) {
	// std::cout << "Character assignation operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

const std::string &Character::getName() const {
	// std::cout << "Character getName" << std::endl;
	return (this->_name);
}

void Character::equip(AMateria *m) {
	// std::cout << "Character equip" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	// std::cout << "Character unequip" << std::endl;
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
		return ;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	// std::cout << "Character use" << std::endl;
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}

void Character::printData() {
	std::cout << "Character name: [" << this->_name << "]"<< std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			std::cout << "Inventory[" << i << "]: [" << this->_inventory[i]->getType() << "]" << std::endl;
		else
			std::cout << "Inventory[" << i << "]: [empty]" << std::endl;
	}
}
