/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:29:15 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 17:02:04 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << MAGENTA << "WrongCat - constructor default" << RESET << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) {
	std::cout << MAGENTA << "WrongCat - copy constructor" << RESET << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
	std::cout << MAGENTA << "WrongCat - destructor" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << MAGENTA << "Meow... MEOOOOOOOOOOOOOOOW!!!" << RESET << std::endl;
}
