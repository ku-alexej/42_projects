/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:42:55 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/14 16:52:07 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	std::cout << std::endl;
	ScalarConverter::convert(av[1]);
	std::cout << std::endl;

	// std::cout << "test float:" << 123.123456789f << std::endl;
	// std::cout << "test float:" << 4.000001f << std::endl;

	return 0;
}
