/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:04:08 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/02 14:38:52 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy request form", 72, 45), _target("someone") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("Robotomy request form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	RobotomyRequestForm::executeAction() const {
	static bool isSeeded = false;
	
	if (!isSeeded) {
		std::srand(std::time(NULL));
		isSeeded = true;
	}
	std::cout << "*some drilling noises*" << std::endl;
	if (std::rand() % 2) {
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Robotomization of " << this->_target << " has failed." << std::endl;
	}
}
