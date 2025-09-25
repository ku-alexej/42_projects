/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:09:55 by akurochk          #+#    #+#             */
/*   Updated: 2024/09/25 12:40:18 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	std::cout << std::endl;

	{
		std::cout << CYAN << "*** CASE 0: copy constructor ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucratA("Bunny", 10);
			std::cout << "CreatedA: " << bureaucratA << std::endl;
			Bureaucrat	bureaucratB(bureaucratA);
			std::cout << "CreatedB: " << bureaucratB << std::endl;		
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch(const std::exception& e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 1: operator= ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucratA("Fox", 10);
			std::cout << "CreatedA: " << bureaucratA << std::endl;
			Bureaucrat	bureaucratB;
			std::cout << "CreatedB: " << bureaucratB << std::endl;

			bureaucratB = bureaucratA;
			std::cout << "B = A" << std::endl;

			std::cout << "Data  A: " << bureaucratA << std::endl;
			std::cout << "Data  B: " << bureaucratB << std::endl;
			
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch(const std::exception& e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}
	
	{
		std::cout << CYAN << "*** CASE 2: Grade 0 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Frog", 0);
			std::cout << "Created: " << bureaucrat << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch(const std::exception& e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 3: Grade 1 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Bear", 1);
			std::cout << "Created: " << bureaucrat << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch(const std::exception& e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 4: Grade 75 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Lion", 75);
			std::cout << "Created: " << bureaucrat << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch(const std::exception& e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 5: Grade 150 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Horse", 150);
			std::cout << "Created: " << bureaucrat << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch(const std::exception& e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 6: Grade 151 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Rabbit", 151);
			std::cout << "Created: " << bureaucrat << std::endl;
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch(const std::exception& e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}
	
	{
		std::cout << CYAN << "*** CASE 7: Grade 5 and increment x4 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Wolf", 5);
			std::cout << "Created: " << bureaucrat << std::endl;
			
			int i = 0;
			while (i < 4) {
				std::cout << i + 1 << ": ";
				bureaucrat.incrementGrade();
				std::cout << bureaucrat << std::endl;
				i++;
			}
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 8: Grade 5 and increment x5 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Duck", 5);
			std::cout << "Created: " << bureaucrat << std::endl;
			
			int i = 0;
			while (i < 5) {
				std::cout << i + 1 << ": ";
				bureaucrat.incrementGrade();
				std::cout << bureaucrat << std::endl;
				i++;
			}
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 9: Grade 146 and decrement x4 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Seagull", 146);
			std::cout << "Created: " << bureaucrat << std::endl;
			
			int i = 0;
			while (i < 4) {
				std::cout << i + 1 << ": ";
				bureaucrat.decrementGrade();
				std::cout << bureaucrat << std::endl;
				i++;
			}
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN << "*** CASE 10: Grade 146 and decrement x5 ***" << std::endl << RESET;
		try {
			Bureaucrat	bureaucrat("Woodpecker", 146);
			std::cout << "Created: " << bureaucrat << std::endl;
			
			int i = 0;
			while (i < 5) {
				std::cout << i + 1 << ": ";
				bureaucrat.decrementGrade();
				std::cout << bureaucrat << std::endl;
				i++;
			}
			std::cout << GREEN << "No error" << std::endl << RESET;
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		std::cout << std::endl;
	}
	
	return 0;
}
