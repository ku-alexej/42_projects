/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:09:29 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/16 14:12:22 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	this->_name = "DiamondTrapDefault";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
	std::cout << MAGENTA << "DiamondTrap \"" << this->_name << "\" was created by default constructor" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
	std::cout << MAGENTA << "DiamondTrap \"" << this->_name << "\" was created by name constructor" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	*this = other;
	std::cout << MAGENTA << "DiamondTrap \"" << this->_name << "\" was created by copy constructor" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << MAGENTA << "DiamondTrap " << this->_name << " is destroyed" << RESET << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << MAGENTA << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << RESET << std::endl;
}
