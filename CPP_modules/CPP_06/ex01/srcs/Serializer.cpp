/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:32:47 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/15 16:35:47 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer &other) {
	*this = other;
}

Serializer	&Serializer::operator=(const Serializer &other) {
	if (this != &other)
		;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
