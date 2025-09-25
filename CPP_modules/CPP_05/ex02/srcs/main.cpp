/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:09:55 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/03 13:07:55 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testCopyConstructor() {

	Bureaucrat fox("Fox", 1);

	std::cout << CYAN << "*** COPY CONSTRUCTOR 0 ***" << std::endl << RESET;
	try {
		PresidentialPardonForm teddy("TEDDY");
		std::cout << YELLOW << "PresidentialPardonForm created: " << teddy << std::endl << RESET;
		fox.signForm(teddy);

		PresidentialPardonForm teddy_copy(teddy);
		std::cout << YELLOW << "PresidentialPardonForm src: " << teddy << std::endl << RESET;
		std::cout << YELLOW << "PresidentialPardonForm cpy: " << teddy_copy << std::endl << RESET;

		fox.signForm(teddy_copy);
		fox.executeForm(teddy);
		fox.executeForm(teddy_copy);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** COPY CONSTRUCTOR 1 ***" << std::endl << RESET;
	try {
		RobotomyRequestForm teddy("TEDDY");
		std::cout << YELLOW << "RobotomyRequestForm created: " << teddy << std::endl << RESET;
		fox.signForm(teddy);

		RobotomyRequestForm teddy_copy(teddy);
		std::cout << YELLOW << "RobotomyRequestForm src: " << teddy << std::endl << RESET;
		std::cout << YELLOW << "RobotomyRequestForm cpy: " << teddy_copy << std::endl << RESET;

		fox.signForm(teddy_copy);
		fox.executeForm(teddy);
		fox.executeForm(teddy_copy);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** COPY CONSTRUCTOR 2 ***" << std::endl << RESET;
	try {
		ShrubberyCreationForm teddy("TEDDY");
		std::cout << YELLOW << "ShrubberyCreationForm created: " << teddy << std::endl << RESET;
		fox.signForm(teddy);

		ShrubberyCreationForm teddy_copy(teddy);
		std::cout << YELLOW << "ShrubberyCreationForm src: " << teddy << std::endl << RESET;
		std::cout << YELLOW << "ShrubberyCreationForm cpy: " << teddy_copy << std::endl << RESET;

		fox.signForm(teddy_copy);
		fox.executeForm(teddy_copy);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;
}

void	testOperator() {
	Bureaucrat fox("Fox", 1);

	std::cout << CYAN << "*** OPERATOR \"=\" 0 ***" << std::endl << RESET;
	try {
		PresidentialPardonForm bear("BEAR");
		PresidentialPardonForm someone;
		std::cout << YELLOW << "PresidentialPardonForm bear   : " << bear << std::endl << RESET;
		std::cout << YELLOW << "PresidentialPardonForm default: " << someone << std::endl << RESET;

		fox.signForm(bear);
		fox.signForm(someone);
		fox.executeForm(bear);
		fox.executeForm(someone);
		std::cout << YELLOW << "PresidentialPardonForm bear   : " << bear << std::endl << RESET;
		std::cout << YELLOW << "PresidentialPardonForm default: " << someone << std::endl << RESET;

		someone = bear;
		std::cout << YELLOW << "someone = bear" << std::endl;
		std::cout << YELLOW << "PresidentialPardonForm bear   : " << bear << std::endl << RESET;
		std::cout << YELLOW << "PresidentialPardonForm default: " << someone << std::endl << RESET;

		fox.executeForm(bear);
		fox.executeForm(someone);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** OPERATOR \"=\" 1 ***" << std::endl << RESET;
	try {
		RobotomyRequestForm bear("BEAR");
		RobotomyRequestForm someone;
		std::cout << YELLOW << "RobotomyRequestForm bear   : " << bear << std::endl << RESET;
		std::cout << YELLOW << "RobotomyRequestForm default: " << someone << std::endl << RESET;

		fox.signForm(bear);
		fox.signForm(someone);
		fox.executeForm(bear);
		fox.executeForm(someone);
		std::cout << YELLOW << "RobotomyRequestForm bear  : " << bear << std::endl << RESET;
		std::cout << YELLOW << "RobotomyRequestForm default: " << someone << std::endl << RESET;

		someone = bear;
		std::cout << YELLOW << "someone = bear" << std::endl;
		std::cout << YELLOW << "RobotomyRequestForm bear  : " << bear << std::endl << RESET;
		std::cout << YELLOW << "RobotomyRequestForm default: " << someone << std::endl << RESET;

		fox.executeForm(bear);
		fox.executeForm(someone);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** OPERATOR \"=\" 2 ***" << std::endl << RESET;
	try {
		ShrubberyCreationForm bear("BEAR");
		ShrubberyCreationForm someone;
		std::cout << YELLOW << "ShrubberyCreationForm bear  : " << bear << std::endl << RESET;
		std::cout << YELLOW << "ShrubberyCreationForm default: " << someone << std::endl << RESET;

		fox.signForm(bear);
		fox.signForm(someone);

		fox.executeForm(someone);
		std::cout << YELLOW << "ShrubberyCreationForm bear  : " << bear << std::endl << RESET;
		std::cout << YELLOW << "ShrubberyCreationForm default: " << someone << std::endl << RESET;

		someone = bear;
		std::cout << YELLOW << "someone = bear" << std::endl;
		std::cout << YELLOW << "ShrubberyCreationForm bear  : " << bear << std::endl << RESET;
		std::cout << YELLOW << "ShrubberyCreationForm default: " << someone << std::endl << RESET;

		fox.executeForm(someone);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;
}

void	testPresidentialPardonForm() {
	Bureaucrat fox("Fox", 5);
	Bureaucrat lion("Lion", 25);
	Bureaucrat rabbit("Rabbit", 150);

	std::cout << CYAN << "*** PresidentialPardonForm 0: signForm executeForm ***" << std::endl << RESET;
	try {
		PresidentialPardonForm deer("DEER_0");
		std::cout << YELLOW << "PresidentialPardonForm deer : " << deer << std::endl << RESET;

		rabbit.signForm(deer);
		lion.signForm(deer);
		fox.signForm(deer);

		std::cout << YELLOW << "PresidentialPardonForm deer: " << deer << std::endl << RESET;

		rabbit.executeForm(deer);
		lion.executeForm(deer);
		fox.executeForm(deer);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** PresidentialPardonForm 1: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << rabbit << std::endl << RESET;
		PresidentialPardonForm deer("DEER_1");
		std::cout << YELLOW << "PresidentialPardonForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.beSigned(rabbit)" << std::endl << RESET;
		deer.beSigned(rabbit);

		std::cout << YELLOW << "PresidentialPardonForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.execute(rabbit)" << std::endl << RESET;
		deer.execute(rabbit);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** PresidentialPardonForm 2: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << lion << std::endl << RESET;
		PresidentialPardonForm deer("DEER_2");
		std::cout << YELLOW << "PresidentialPardonForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.beSigned(lion)" << std::endl << RESET;
		deer.beSigned(lion);

		std::cout << YELLOW << "PresidentialPardonForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.execute(lion)" << std::endl << RESET;
		deer.execute(lion);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** PresidentialPardonForm 3: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << fox << std::endl << RESET;
		PresidentialPardonForm deer("DEER_3");
		std::cout << YELLOW << "PresidentialPardonForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.beSigned(fox)" << std::endl << RESET;
		deer.beSigned(fox);

		std::cout << YELLOW << "PresidentialPardonForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.execute(fox)" << std::endl << RESET;
		deer.execute(fox);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;
}

void	testRobotomyRequestForm() {
	Bureaucrat fox("Fox", 45);
	Bureaucrat lion("Lion", 72);
	Bureaucrat rabbit("Rabbit", 150);

	std::cout << CYAN << "*** RobotomyRequestForm 0: signForm executeForm ***" << std::endl << RESET;
	try {
		RobotomyRequestForm deer("DEER_0");
		std::cout << YELLOW << "RobotomyRequestForm deer : " << deer << std::endl << RESET;

		rabbit.signForm(deer);
		lion.signForm(deer);
		fox.signForm(deer);

		std::cout << YELLOW << "RobotomyRequestForm deer: " << deer << std::endl << RESET;

		rabbit.executeForm(deer);
		lion.executeForm(deer);
		fox.executeForm(deer);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** RobotomyRequestForm 1: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << rabbit << std::endl << RESET;
		RobotomyRequestForm deer("DEER_1");
		std::cout << YELLOW << "RobotomyRequestForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.beSigned(rabbit)" << std::endl << RESET;
		deer.beSigned(rabbit);

		std::cout << YELLOW << "RobotomyRequestForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.execute(rabbit) x 5" << std::endl << RESET;
		for(int i = 0; i < 5; i++)
			deer.execute(rabbit);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** RobotomyRequestForm 2: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << lion << std::endl << RESET;
		RobotomyRequestForm deer("DEER_2");
		std::cout << YELLOW << "RobotomyRequestForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.beSigned(lion)" << std::endl << RESET;
		deer.beSigned(lion);

		std::cout << YELLOW << "RobotomyRequestForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.execute(lion) x 5" << std::endl << RESET;

		for(int i = 0; i < 5; i++)
			deer.execute(lion);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** RobotomyRequestForm 3: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << fox << std::endl << RESET;
		RobotomyRequestForm deer("DEER_3");
		std::cout << YELLOW << "RobotomyRequestForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.beSigned(fox)" << std::endl << RESET;
		deer.beSigned(fox);

		std::cout << YELLOW << "RobotomyRequestForm deer: " << deer << std::endl << RESET;

		std::cout << YELLOW << "Try deer.execute(fox) x 5" << std::endl << RESET;

		for(int i = 0; i < 5; i++)
			deer.execute(fox);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;
}

void	testShrubberyCreationForm() {
	Bureaucrat fox("Fox", 137);
	Bureaucrat lion("Lion", 145);
	Bureaucrat rabbit("Rabbit", 150);

	std::cout << CYAN << "*** ShrubberyCreationForm 0: signForm executeForm ***" << std::endl << RESET;
	try {
		ShrubberyCreationForm wolf("WOLF_0");
		std::cout << YELLOW << "ShrubberyCreationForm wolf : " << wolf << std::endl << RESET;

		rabbit.signForm(wolf);
		lion.signForm(wolf);
		fox.signForm(wolf);

		std::cout << YELLOW << "ShrubberyCreationForm wolf: " << wolf << std::endl << RESET;

		rabbit.executeForm(wolf);
		lion.executeForm(wolf);
		fox.executeForm(wolf);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** ShrubberyCreationForm 1: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << rabbit << std::endl << RESET;
		ShrubberyCreationForm wolf("WOLF_1");
		std::cout << YELLOW << "ShrubberyCreationForm wolf: " << wolf << std::endl << RESET;

		std::cout << YELLOW << "Try wolf.beSigned(rabbit)" << std::endl << RESET;
		wolf.beSigned(rabbit);
		std::cout << YELLOW << "ShrubberyCreationForm wolf: " << wolf << std::endl << RESET;

		std::cout << YELLOW << "Try wolf.execute(rabbit)" << std::endl << RESET;
		wolf.execute(rabbit);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** ShrubberyCreationForm 2: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << lion << std::endl << RESET;
		ShrubberyCreationForm wolf("WOLF_2");
		std::cout << YELLOW << "ShrubberyCreationForm wolf: " << wolf << std::endl << RESET;

		std::cout << YELLOW << "Try wolf.beSigned(lion)" << std::endl << RESET;
		wolf.beSigned(lion);
		std::cout << YELLOW << "ShrubberyCreationForm wolf: " << wolf << std::endl << RESET;

		std::cout << YELLOW << "Try wolf.execute(lion)" << std::endl << RESET;
		wolf.execute(lion);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;

	std::cout << CYAN << "*** ShrubberyCreationForm 3: beSigned exexcute ***" << std::endl << RESET;
	try {
		std::cout << YELLOW << "Bureaucrat                 : " << fox << std::endl << RESET;
		ShrubberyCreationForm wolf("WOLF_3");
		std::cout << YELLOW << "ShrubberyCreationForm wolf: " << wolf << std::endl << RESET;

		std::cout << YELLOW << "Try wolf.beSigned(fox)" << std::endl << RESET;
		wolf.beSigned(fox);
		std::cout << YELLOW << "ShrubberyCreationForm wolf: " << wolf << std::endl << RESET;

		std::cout << YELLOW << "Try wolf.execute(fox)" << std::endl << RESET;
		wolf.execute(fox);

		std::cout << GREEN << "No error" << std::endl << RESET;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	std::cout << std::endl;
}

int	main() {
	std::cout << std::endl;
	testCopyConstructor();
	testOperator();
	testPresidentialPardonForm();
	testRobotomyRequestForm();
	testShrubberyCreationForm();
	return 0;
}
