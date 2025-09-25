/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:09:55 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/03 12:54:35 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	ft_delete(AForm *form) {
	if (form)
		delete form;
}

void	testFormsCreation() {
	std::cout << CYAN << "*** testFormsCreation ***" << std::endl << RESET;

	Intern	intern;
	AForm	*form1;
	AForm	*form2;
	AForm	*form3;
	AForm	*form4;
	AForm	*form5;

	form1 = intern.makeForm("presidential pardon", "target1");
	form2 = intern.makeForm("robotomy request", "target2");
	form3 = intern.makeForm("shrubbery creation", "target3");
	form4 = intern.makeForm("", "target4");
	form5 = intern.makeForm("pink spaghetti", "target5");

	ft_delete(form1);
	ft_delete(form2);
	ft_delete(form3);
	ft_delete(form4);
	ft_delete(form5);
	std::cout << std::endl;
}

void	testSignAndExecute() {
	std::cout << CYAN << "*** testSignAndExecute ***" << std::endl << RESET;

	Intern		intern;
	Bureaucrat	fox("Fox", 5);
	Bureaucrat	wolf("Wolf", 25);
	Bureaucrat	bear("Bear", 45);
	Bureaucrat	rabbit("Rabbit", 72);
	Bureaucrat	dog("Dog", 137);
	Bureaucrat	hamster("Hamster", 145);
	Bureaucrat	cat("Cat", 150);
	AForm		*form1 = intern.makeForm("presidential pardon", "target1");
	AForm		*form2 = intern.makeForm("robotomy request", "target2");
	AForm		*form3 = intern.makeForm("shrubbery creation", "target3");
	std::cout << std::endl;

	std::cout << YELLOW << ".signForm(*form1)" << std::endl << RESET;
	cat.signForm(*form1);
	hamster.signForm(*form1);
	dog.signForm(*form1);
	rabbit.signForm(*form1);
	bear.signForm(*form1);
	wolf.signForm(*form1);
	fox.signForm(*form1);
	std::cout << std::endl;

	std::cout << YELLOW << ".executeForm(*form1)" << std::endl << RESET;
	cat.executeForm(*form1);
	hamster.executeForm(*form1);
	dog.executeForm(*form1);
	rabbit.executeForm(*form1);
	bear.executeForm(*form1);
	wolf.executeForm(*form1);
	fox.executeForm(*form1);
	std::cout << std::endl;

	std::cout << YELLOW << ".signForm(*form2)" << std::endl << RESET;
	cat.signForm(*form2);
	hamster.signForm(*form2);
	dog.signForm(*form2);
	rabbit.signForm(*form2);
	bear.signForm(*form2);
	wolf.signForm(*form2);
	fox.signForm(*form2);
	std::cout << std::endl;

	std::cout << YELLOW << ".executeForm(*form2)" << std::endl << RESET;
	cat.executeForm(*form2);
	hamster.executeForm(*form2);
	dog.executeForm(*form2);
	rabbit.executeForm(*form2);
	bear.executeForm(*form2);
	wolf.executeForm(*form2);
	fox.executeForm(*form2);
	std::cout << std::endl;

	std::cout << YELLOW << ".signForm(*form3)" << std::endl << RESET;
	cat.signForm(*form3);
	hamster.signForm(*form3);
	dog.signForm(*form3);
	rabbit.signForm(*form3);
	bear.signForm(*form3);
	wolf.signForm(*form3);
	fox.signForm(*form3);
	std::cout << std::endl;

	std::cout << YELLOW << ".executeForm(*form3)" << std::endl << RESET;
	cat.executeForm(*form3);
	hamster.executeForm(*form3);
	dog.executeForm(*form3);
	rabbit.executeForm(*form3);
	bear.executeForm(*form3);
	wolf.executeForm(*form3);
	fox.executeForm(*form3);
	std::cout << std::endl;

	ft_delete(form1);
	ft_delete(form2);
	ft_delete(form3);
	std::cout << std::endl;
}

int	main() {
	std::cout << std::endl;
	testFormsCreation();
	testSignAndExecute();
	return (0);
}
