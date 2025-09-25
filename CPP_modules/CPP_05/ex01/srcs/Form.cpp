/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:10:41 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/26 14:33:32 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const Form &other) : _name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

const std::string	&Form::getName() const {
	return this->_name;
}

bool	Form::getIsSigned() const {
	return this->_isSigned;
}

int	Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int	Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Form: Grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Form: Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form{name=" << form.getName()  << ", gradeToSigne=" << form.getGradeToSign() << ", gradeToExecute=" << form.getGradeToExecute();
	if (form.getIsSigned())
		out << ", isSigned=true}";
	else
		out << ", isSigned=false}";
	return out;
}
