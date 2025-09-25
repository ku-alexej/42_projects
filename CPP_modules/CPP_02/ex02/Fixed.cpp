/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:07:12 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/11 17:28:15 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::Fixed(const int iValue) {
	this->_value = iValue << this->_fractional_bits;
}

Fixed::Fixed(const float fValue) {
	this->_value = roundf(fValue * (1 << this->_fractional_bits));
}

Fixed::~Fixed() {
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	this->_value = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const {
	return (this->_value > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const {
	return (this->_value < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return (this->_value >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return (this->_value <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
	return (this->_value == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return (this->_value != fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator++() {
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--() {
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	operator--();
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed const	&Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

Fixed const	&Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

int	Fixed::getRawBits(void) const {
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << this->_fractional_bits));
}

int	Fixed::toInt(void) const {
	return (this->_value >> this->_fractional_bits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
