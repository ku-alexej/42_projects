/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:41:50 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/10 18:21:35 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Harl.hpp"

int	main() {
	Harl		harl;
	std::string	level;

	while (true) {
		std::cout << "Enter the level of complaint (DEBUG, INFO, WARNING, ERROR) or EXIT: ";
		if (!std::getline(std::cin, level)) {
			std::cout << "Invalid input" << std::endl;
			break ;
		}
		if (level.compare("EXIT") == 0) {
			std::cout << "Exiting..." << std::endl;
			break ;
		}
		harl.complain(level);
	}

	return (0);
}
