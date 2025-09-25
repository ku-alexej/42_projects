/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:52:10 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/03 12:58:26 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &other) {
	if (this != &other)
		;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) {

	AForm *form = NULL;
	
	// if (formName.empty() || (...
	if (formName != "presidential pardon" && formName != "robotomy request" && formName != "shrubbery creation") {
		std::cout << "Intern can't create \"" << formName << "\" form" << std::endl;
		return (form);
	}

	switch (formName[0]) {
		case 'p':
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates for target " << target << " new form: " << *form << std::endl;
			break;
		case 'r':
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates for target " << target << " new form: " << *form << std::endl;
			break;
		case 's':
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates for target " << target << " new form: " << *form << std::endl;
			break;
		default:
			std::cout << "AAAAAAAAAAAAAAAAA \"" << formName << "\" HOW it's happend" << std::endl;
			form = NULL;
			break;
	}
	return (form);
}
