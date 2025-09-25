/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:10:41 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/26 15:17:46 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
	_name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const AForm &other) :
	_name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm	&AForm::operator=(const AForm &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

const std::string	&AForm::getName() const {
	return (this->_name);
}

bool	AForm::getIsSigned() const {
	return (this->_isSigned);
}

int	AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const {
	if (!this->_isSigned)
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	this->executeAction();
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("AForm: Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("AForm: Grade is too low");
}

const char	*AForm::FormIsNotSignedException::what() const throw() {
	return ("AForm: Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form{name=" << form.getName()  << ", gradeToSigne=" << form.getGradeToSign() << ", gradeToExecute=" << form.getGradeToExecute();
	if (form.getIsSigned())
		out << ", isSigned=true}";
	else
		out << ", isSigned=false}";
	return (out);
}
