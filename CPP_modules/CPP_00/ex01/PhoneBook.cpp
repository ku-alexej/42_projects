/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:56 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/01 16:30:50 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_id = 0;
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::_isNumeric(std::string str)
{
	size_t i = 0;
	
	while (i < str.length())
	{
		if (isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

int	PhoneBook::checkEndOfFile(void)
{
	if (std::cin.eof())
		return (1);
	return (0);
}

void	PhoneBook::add(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << YELLOW << "================ ADD CONTACT ================" << RESET << std::endl;
	std::cout << CYAN << "Enter first name    : " << RESET;
	std::getline(std::cin, firstName);
	if (checkEndOfFile())
		return ;
	std::cout << CYAN << "Enter last name     : " << RESET;
	std::getline(std::cin, lastName);
	if (checkEndOfFile())
		return ;
	std::cout << CYAN << "Enter nickname      : " << RESET;
	std::getline(std::cin, nickname);
	if (checkEndOfFile())
		return ;
	std::cout << CYAN << "Enter phone number  : " << RESET;
	std::getline(std::cin, phoneNumber);
	if (checkEndOfFile())
		return ;
	std::cout << CYAN << "Enter darkest secret: " << RESET;
	std::getline(std::cin, darkestSecret);
	if (checkEndOfFile())
		return ;
	if(firstName.empty() || lastName.empty() || nickname.empty()
		|| phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << RED << "Error: at last one of fields is empty." << RESET << std::endl;
		std::cout << CYAN << "Press ENTER to continue." << RESET;
		return ;
	}
	if(_isNumeric(phoneNumber) == false)
	{
		std::cout << RED << "Error: phone number must contain only digits." << RESET << std::endl;
		std::cout << CYAN << "Press ENTER to continue." << RESET;
		return ;
	}
	this->_contacts[this->_id % 8] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->_id++;
	std::cout << GREEN << "Contact added successfully." << RESET << std::endl;
	std::cout << CYAN << "Press ENTER to continue." << RESET;
}

void	PhoneBook::_printBook(void)
{
	int			i = 0;
	
	std::cout << YELLOW << "=============== SAVED CONTACTS ==============" << RESET << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	while (i < 8 && i < this->_id)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << this->_contacts[i].getFirstNameFormatted() << "|";
		std::cout << std::setw(10) << this->_contacts[i].getLastNameFormatted() << "|";
		std::cout << std::setw(10) << this->_contacts[i].getNicknameFormatted() << "|" << std::endl;
		i++;
	}
}

void	PhoneBook::search(void)
{
	std::string	index;
	
	
	if (this->_id == 0)
	{
		std::cout << "No contacts in phonebook." << std::endl;
		std::cout << CYAN << "Press ENTER to continue." << RESET;
		return ;
	}
	this->_printBook();
	std::cout << YELLOW << "=============== SEARCH CONTACT ==============" << RESET << std::endl;
	std::cout << CYAN << "Enter index of contact: " << RESET;
	std::getline(std::cin, index);
	if (checkEndOfFile())
		return ;
	if (index.empty() || _isNumeric(index) == false)
	{
		std::cout << "Incorrect index, search was stopped." << std::endl;
		std::cout << CYAN << "Press ENTER to continue." << RESET;
		return ;
	}
	else if (index.length() != 1 || index[0] - '0' >= this->_id || index[0] > '7')
	{
		std::cout << "Index doesn't exist, search was stopped." << std::endl;
		std::cout << CYAN << "Press ENTER to continue." << RESET;
		return ;
	}
	else
	{
		this->_contacts[index[0] - '0'].printContact();
	}
}