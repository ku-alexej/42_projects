/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:39:27 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 14:02:54 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	// std::cout << "MateriaSource copy constructor" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource() {
	// std::cout << "MateriaSource destructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	// std::cout << "MateriaSource assignation operator" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
		this->_materias[i] = other._materias[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
	// std::cout << "MateriaSource learnMateria" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	// std::cout << "MateriaSource createMateria" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (NULL);
}
