/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:23 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 17:02:15 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << CYAN << "Brain - constructor default" << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << CYAN << "Brain - copy constructor" << RESET << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << CYAN << "Brain - destructor" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	for (int i = 0; other._ideas[i].empty() != true; i++)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}

void Brain::addIdea(std::string idea) {
	int i = 0;
	
	while (this->_ideas[i].empty() != true)
		i++;
	if (i < 100) {
		this->_ideas[i] = idea;
		std::cout << CYAN << "Brain - idea added" << RESET << std::endl;
		return ;
	}
	std::cout << CYAN << "Brain - brain is full" << RESET << std::endl;
}

void Brain::getIdeas() {
    for (int i = 0; this->_ideas[i].empty() != true; i++) {
        if (this->_ideas[i + 1].empty() != true)
            std::cout << this->_ideas[i] << ", ";
        else
            std::cout << this->_ideas[i];
    }
}

void Brain::setIdea(int index, std::string idea) {
	if (this->_ideas[index].empty() == true || index < 0 || index >= 100) {
		std::cout << CYAN << "Brain - idea not found" << RESET << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
	std::cout << CYAN << "Brain - idea set" << RESET << std::endl;
	return ;
}
