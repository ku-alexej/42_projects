/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:19:59 by akurochk          #+#    #+#             */
/*   Updated: 2024/11/14 16:35:38 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: ./bitcoin [file]" << std::endl;
		return (1);
	}
	
	BitcoinExchange exchange;

	try {
		if (!exchange.readDataBase("data.csv") || !exchange.handleInput(av[1]))
			return (1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
