/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:17:16 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/09 14:55:43 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of string   : " << &str << std::endl;
	std::cout << "Address of pointer  : " << stringPTR << std::endl;
	std::cout << "Address of reference: " << &stringREF << std::endl;

	std::cout << "Value of string     : " << str << std::endl;
	std::cout << "Value of pointer    : " << *stringPTR << std::endl;
	std::cout << "Value of reference  : " << stringREF << std::endl;

	return (0);	
}
