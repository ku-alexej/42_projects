/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:52 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/01 16:17:42 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret) :
	_firstName(firstName), _lastName(lastName), _nickname(nickname),
	_phoneNumber(phoneNumber), _darkestSecret(darkestSecret)
{
}

Contact::~Contact()
{
}

std::string	Contact::getFirstNameFormatted()
{
	return (_formatField(this->_firstName));
}

std::string	Contact::getLastNameFormatted()
{
	return (_formatField(this->_lastName));
}

std::string	Contact::getNicknameFormatted()
{
	return (_formatField(this->_nickname));
}

std::string	Contact::_formatField(std::string field)
{
	if (field.length() > 10)
	{
		field.resize(9);
		field.append(".");
	}
	return (field);
}

void	Contact::printContact()
{
	std::cout << YELLOW << "================ CONTACT INFO ===============" << RESET << std::endl;
	std::cout << "First name    : " << this->_firstName << std::endl;
	std::cout << "Last name     : " << this->_lastName << std::endl;
	std::cout << "Nickname      : " << this->_nickname << std::endl;
	std::cout << "Phone number  : " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
	std::cout << CYAN << "Press ENTER to continue." << RESET;
}