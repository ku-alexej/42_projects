/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:09:55 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/26 14:49:14 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << std::endl;

	{
		std::cout << CYAN << "*** CASE 0: copy constructor***" << std::endl << RESET;
		try {
			Form formA("Contract with mr. Hamster", 10, 10);
			std::cout << "Created A: " << formA << std::endl;
			Bureaucrat bureaucrat("Fox", 1);
			std::cout << "Created  : " << bureaucrat << std::endl;
			
			bureaucrat.signForm(formA);
			Form formB(formA);
			
			std::cout << "Data    A: " << formA << std::endl;
			std::cout << "Created B: " << formB << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
			
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 1: operator= ***" << std::endl << RESET;
		try {
			Form formA("Useless but important paper", 10, 10);
			std::cout << "Created A: " << formA << std::endl;
			Form formB;
			std::cout << "Created B: " << formB << std::endl;
			Bureaucrat bureaucrat("mr. Bear", 1);
			std::cout << "Created  : " << bureaucrat << std::endl;

			bureaucrat.signForm(formA);
			formB = formA;
			std::cout << "B = A" << std::endl;
			
			std::cout << "Data  A: " << formA << std::endl;
			std::cout << "Data  B: " << formB << std::endl;
			
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}
	
	{
		std::cout << CYAN << "*** CASE 2: gradeToSigne 0 ***" << std::endl << RESET;
		try {
			Form form("List of TOP-10 tree-houses", 0, 10);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 3: gradeToSigne 1 ***" << std::endl << RESET;
		try {
			Form form("List of holidays 2026", 1, 10);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 4: gradeToSigne 75 ***" << std::endl << RESET;
		try {
			Form form("Cristmas menu", 75, 10);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 5: gradeToSigne 150 ***" << std::endl << RESET;
		try {
			Form form("List of decoration for helloween", 150, 10);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}
	
	{
		std::cout << CYAN << "*** CASE 6: gradeToSigne 151 ***" << std::endl << RESET;
		try {
			Form form("Santas ban-list", 151, 10);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 7: gradeToExecute 0 ***" << std::endl << RESET;
		try {
			Form form("Santas ban-list", 10, 0);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 8: gradeToExecute 1 ***" << std::endl << RESET;
		try {
			Form form("Santas ban-list", 10, 1);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 9: gradeToExecute 75 ***" << std::endl << RESET;
		try {
			Form form("Santas ban-list", 10, 75);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 10: gradeToExecute 150 ***" << std::endl << RESET;
		try {
			Form form("Santas ban-list", 10, 150);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 11: gradeToExecute 151 ***" << std::endl << RESET;
		try {
			Form form("Santas ban-list", 10, 151);
			std::cout << "Created: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 12: beSigned 1 try 1 ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("Red Panda", 1);
			std::cout << "Created : " << bureaucrat << std::endl;
			Form form("Santas ban-list", 1, 150);
			std::cout << "Created : " << form << std::endl;
			form.beSigned(bureaucrat);
			std::cout << "beSigned: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 13: beSigned 1 try 75 ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("Red Panda", 1);
			std::cout << "Created: " << bureaucrat << std::endl;
			Form form("Santas ban-list", 50, 150);
			std::cout << "Created: " << form << std::endl;
			form.beSigned(bureaucrat);
			std::cout << "beSigned: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 14: beSigned 75 try 74 ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("Red Panda", 75);
			std::cout << "Created: " << bureaucrat << std::endl;
			Form form("Santas ban-list", 74, 150);
			std::cout << "Created: " << form << std::endl;
			form.beSigned(bureaucrat);
			std::cout << "beSigned: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 15: beSigned 75 try 75 ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("Red Panda", 75);
			std::cout << "Created: " << bureaucrat << std::endl;
			Form form("Santas ban-list", 75, 150);
			std::cout << "Created: " << form << std::endl;
			form.beSigned(bureaucrat);
			std::cout << "beSigned: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 16: beSigned 150 try 149 ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("Red Panda", 150);
			std::cout << "Created: " << bureaucrat << std::endl;
			Form form("Santas ban-list", 149, 150);
			std::cout << "Created: " << form << std::endl;
			form.beSigned(bureaucrat);
			std::cout << "beSigned: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 17: beSigned 150 try 150 ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("Red Panda", 150);
			std::cout << "Created: " << bureaucrat << std::endl;
			Form form("Santas ban-list", 150, 150);
			std::cout << "Created: " << form << std::endl;
			form.beSigned(bureaucrat);
			std::cout << "beSigned: " << form << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 18: signForm 1 try 1 ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("White Panda", 1);
			std::cout << "Created: " << bureaucrat << std::endl;
			Form form("File 3-4d-L5", 1, 150);
			std::cout << "Created: " << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}
	
	{
		std::cout << CYAN << "*** CASE 19: signForm 1 try 1 twice ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("White Panda", 1);
			std::cout << "Created: " << bureaucrat << std::endl;
			Form form("File 3-4d-L5", 1, 150);
			std::cout << "Created: " << form << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.signForm(form);
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}
	
	{
		std::cout << CYAN << "*** CASE 20: signForm 150 try 1 ***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("Pink Panda", 150);
			std::cout << "Created: " << bureaucrat << std::endl;
			Form form("File 3-4d-XYMeow", 1, 150);
			std::cout << "Created: " << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 21: signForm 150 try 1, then 1 try 1***" << std::endl << RESET;
		try {
			Bureaucrat bureaucrat("Pink Panda", 150);
			std::cout << "Created: " << bureaucrat << std::endl;
			Bureaucrat bureaucrat2("White Panda", 1);
			std::cout << "Created: " << bureaucrat2 << std::endl;
			Form form("File 3-4d-XYMeow", 1, 150);
			std::cout << "Created: " << form << std::endl;
			bureaucrat.signForm(form);
			bureaucrat2.signForm(form);
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	
	return 0;
}
