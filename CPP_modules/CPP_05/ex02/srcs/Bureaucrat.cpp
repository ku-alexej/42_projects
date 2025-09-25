/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:28:02 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/03 13:04:09 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

const std::string	&Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &form) {
	if (form.getGradeToSign() < this->_grade) {
		std::cout << *this << " cannot sign " << form << " because of lower grade " << std::endl;
		return ;
	}
	if (form.getIsSigned()) {
		std::cout << *this << " cannot sign " << form << " because it is already signed " << std::endl;
		return ;
	}
	std::cout << *this << " signs " << form << std::endl;
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const &form) {
	if (form.getGradeToExecute() < this->_grade) {
		std::cout << *this << " cannot execute " << form << " because of lower grade " << std::endl;
		return ;
	}
	if (!form.getIsSigned()) {
		std::cout << *this << " cannot execute " << form << " because it is not signed " << std::endl;
		return ;
	}
	std::cout << *this << " executes " << form << std::endl;
	form.execute(*this);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat: Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat: Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << "Bureaucrat{name=" << bureaucrat.getName()  << ", grade=" << bureaucrat.getGrade() << "}";
	return (out);
}
