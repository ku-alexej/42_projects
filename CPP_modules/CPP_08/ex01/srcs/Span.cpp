/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:05:37 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:37 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) : _v(other._v), _n(other._n) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_v = other._v;
		this->_n = other._n;
	}
	return (*this);
}

void Span::addNumber(int num) {
	if (this->_v.size() < _n)
		this->_v.push_back(num);
	else
		throw std::runtime_error("Span is full");
}

unsigned int Span::shortestSpan() {
	unsigned int dist = 0;

	if (this->_v.size() < 2)
		throw std::runtime_error("Not enough elements");

	std::sort(this->_v.begin(), this->_v.end());
	dist = this->_v.back() - this->_v.front();
	for (std::vector<int>::iterator it = this->_v.begin(); it != this->_v.end() - 1; it++) {
		if (dist > static_cast<unsigned int>(abs(*(it + 1) - *it)))
			dist = *(it + 1) - *it;
	}

	return (dist);
}

unsigned int Span::longestSpan() {
	if (this->_v.size() < 2)
		throw std::runtime_error("Not enough elements");

	std::sort(this->_v.begin(), this->_v.end());
	return (this->_v.back() - this->_v.front());
}

void Span::print() const {
	for (std::vector<int>::const_iterator it = this->_v.begin(); it != this->_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_v.size() + std::distance(begin, end) > _n)
		throw std::runtime_error("Span is full");
	this->_v.insert(this->_v.end(), begin, end);
}

