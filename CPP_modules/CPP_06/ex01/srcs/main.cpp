/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:36:55 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/15 17:02:27 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data data;
	data.number = 42;
	data.c = 'V';

	uintptr_t ser = Serializer::serialize(&data);
	Data *deser = Serializer::deserialize(ser);

	std::cout << std::endl;
	if (deser == &data)
		std::cout << "Data and deserialized data are same :)" << std::endl;
	else
		std::cout << "Data and deserialized data are different :(" << std::endl;
	
	std::cout << std::endl;
	std::cout << "Old data ptr:        " << &data << std::endl;
	std::cout << "Old data number:     " << data.number << std::endl;
	std::cout << "Old data char:       " << data.c << std::endl;
	std::cout << std::endl;
	std::cout << "Deserialized ptr:    " << deser << std::endl;
	std::cout << "Deserialized number: " << deser->number << std::endl;
	std::cout << "Deserialized char:   " << deser->c << std::endl;
	std::cout << std::endl;

	return (0);
}
