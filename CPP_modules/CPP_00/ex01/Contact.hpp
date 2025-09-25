/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:49 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/01 14:58:54 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		std::string	_formatField(std::string field);
	public:
		Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname,
			std::string phoneNumber,std::string darkestSecret);
		~Contact(void);
		std::string	getFirstNameFormatted(void);
		std::string	getLastNameFormatted(void);
		std::string	getNicknameFormatted(void);
		void		printContact(void);
};

#endif
