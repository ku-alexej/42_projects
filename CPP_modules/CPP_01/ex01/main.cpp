/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:17:16 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/09 14:53:27 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie *zombie = zombieHorde(5, "zombieHordeName");
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "Test: anonce for " << i << " Zombie" << std::endl;
		zombie[i].announce();
	}
	std::cout << std::endl << "Test: destroy zombieHorde" << std::endl;
	delete [] zombie;
	std::cout << std::endl;
	
	return (0);	
}
