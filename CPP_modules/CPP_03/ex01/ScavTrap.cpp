/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:19:00 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/15 19:36:23 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrapDefault") {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << BLUE << "ScavTrap \"" << _name << "\" was created by default constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << BLUE << "ScavTrap \"" << _name << "\" was created by name constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	*this = other;
	std::cout << BLUE << "ScavTrap \"" << _name << "\" was created by copy constructor" << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << BLUE << "ScavTrap " << _name << " is destroyed" << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->isInOut()) {
		std::cout << BLUE << "Oh no, ScavTrap \"" << this->_name << "\" can't attack anymore..." << RESET << std::endl;
		return;
	} else {
		this->_energyPoints--;
		std::cout << BLUE << "ScavTrap \"" << this->_name << "\" attacks \"" << target << "\","  << RESET;
		std::cout << BLUE << "causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << BLUE << "ScavTrap \"" << _name << "\" is trying Gate keeper mode." << RESET << std::endl;
	if (this->_hitPoints == 0) {
		std::cout << BLUE << "ScavTrap \"" << _name << "\" has no more hit points, ouch..." << RESET << std::endl;
		std::cout << BLUE << "Wait a minut, robots body still can be used as barrier." << RESET << std::endl;
		std::cout << BLUE << "So, why not... Gate keeper mode is on." << RESET << std::endl;
		return;
	}
	std::cout << BLUE << "ScavTrap \"" << _name << "\" is in Gate keeper mode!" << RESET << std::endl;
}
