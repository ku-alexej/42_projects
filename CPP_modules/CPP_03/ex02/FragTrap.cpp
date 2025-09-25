/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:36:53 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/15 19:36:31 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrapDefault") {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << YELLOW << "FragTrap \"" << _name << "\" was created by default constructor" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << YELLOW << "FragTrap \"" << _name << "\" was created by name constructor" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	*this = other;
	std::cout << YELLOW << "FragTrap \"" << _name << "\" was created by copy constructor" << RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << YELLOW << "FragTrap " << _name << " is destroyed" << RESET << std::endl;
}

void FragTrap::highFivesGuys() {
	if (this->_hitPoints == 0) {
		std::cout << YELLOW << "From Walhalla FragTrap \"" << _name << "\" is asking for high fives!" << RESET << std::endl;
	} else {
		std::cout << YELLOW << "FragTrap \"" << _name << "\" is asking for high fives!" << RESET << std::endl;
	}
}
