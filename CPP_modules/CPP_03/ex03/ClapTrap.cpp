/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:29:16 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/15 19:36:42 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrapDefault"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap \"" << _name << "\" was created by default constructor" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap \"" << _name << "\" was created by name constructor" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << GREEN << "ClapTrap \"" << _name << "\" was created by copy constructor" << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << GREEN << "ClapTrap " << _name << " is destroyed" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target) {
	if (this->isInOut()) {
		std::cout << GREEN << "Oh no, ClapTrap \"" << this->_name << "\" can't attack anymore..." << RESET << std::endl;
		return;
	} else {
		this->_energyPoints--;
		std::cout << GREEN << "ClapTrap \"" << this->_name << "\" attacks \"" << target << "\"," << RESET;
		std::cout << GREEN << "causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << GREEN << "ClapTrap \"" << this->_name << "\" is already dead!" << RESET << std::endl;
		std::cout << GREEN << "Oh no, the attack was wasted..." << std::endl;
		return;
	} else if (this->_hitPoints <= amount) {
		this->_hitPoints = 0;
		std::cout << GREEN << "ClapTrap \"" << _name << "\" took " << amount << " points of damage and died!" << RESET << std::endl;
	} else {
		this->_hitPoints -= amount;
		std::cout << GREEN << "ClapTrap \"" << _name << "\" took " << amount << " points of damage and survived!" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->isInOut()) {
		std::cout << GREEN << "Oh no, it can no longer repair itself..." << RESET << std::endl;
		return;
	} else {
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << GREEN << "ClapTrap \"" << _name << "\" was repaired for " << amount << " hit points!" << RESET << std::endl;
	}
}

bool ClapTrap::isInOut() const {
	if (this->_hitPoints == 0) {
		std::cout << "\"" << this->_name << "\" is dead!" << std::endl;
		return (true);
	} else if (this->_energyPoints == 0) {
		std::cout << "\"" << this->_name << "\" has no more energy!" << std::endl;
		return (true);
	}
	return (false);
}

void ClapTrap::showStatus() const {
	std::cout << "Stats of \"" << this->_name;
	std::cout << "\" (HP: " << this->_hitPoints;
	std::cout << ", EP: " << this->_energyPoints;
	std::cout << ", Att: " << this->_attackDamage << ")" << std::endl;
}
