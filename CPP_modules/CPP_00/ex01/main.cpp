/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:17:16 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/01 16:35:53 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "PhoneBook.hpp"

void printOptions(void)
{
	std::cout << YELLOW << "=================== MENU ====================" << RESET << std::endl;
	std::cout << "Please, enter one of the following commands:" << std::endl;
	std::cout << "ADD    - to add a new contact" << std::endl;
	std::cout << "SEARCH - to search for a contact" << std::endl;
	std::cout << "EXIT   - to exit the program" << std::endl;
}

int	main(int argc, char **argv)
{
	PhoneBook	phoneBook;
	std::string	command;

	(void)argc;
	(void)argv;
	std::cout << GREEN << "=============================================" << RESET << std::endl;
	std::cout << GREEN << "=       Welcome to Awesome PhoneBook        =" << RESET << std::endl;
	std::cout << GREEN << "=============================================" << RESET << std::endl;
	std::cout << std::endl;
	printOptions();
	while (true)
	{
		std::cout << CYAN << "Enter command: " << RESET;
		if(!std::getline(std::cin, command))
		{
			std::cout << std::endl << RED << "Error: reading error." << RESET << std::endl;
			std::cout << "Program will be closed." << std::endl;
			return (1);
		}
		if (phoneBook.checkEndOfFile())
		{
			std::cout << std::endl << RED << "Error: input error." << RESET << std::endl;
			std::cout << "Program will be closed." << std::endl;
			return (1);
		}
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			break ;
		else
		{
			std::cout << RED << "Error: unknown command." << RESET << std::endl;
			continue ;
		}
		if (phoneBook.checkEndOfFile())
		{
			std::cout << std::endl << RED << "Error: input error." << RESET << std::endl;
			std::cout << "Program will be closed." << std::endl;
			return (1);
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		printOptions();		
	}
	std::cout << YELLOW << "=================== EXIT ====================" << RESET << std::endl;
	return (0);
}
