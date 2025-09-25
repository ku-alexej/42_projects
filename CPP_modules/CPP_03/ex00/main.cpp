/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:29:23 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/15 17:16:18 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap1;
	clapTrap1.showStatus();
	ClapTrap clapTrap2("ClapTrap2");
	clapTrap2.showStatus();
	ClapTrap clapTrap3(clapTrap2);
	clapTrap3.showStatus();
	clapTrap3 = ClapTrap("ClapTrap3");
	int i;

	std::cout << std::endl;
	i = -1;
	while (++i < 4) {
		clapTrap1.attack("WOLF");
		clapTrap1.attack("WOLF");
		clapTrap1.attack("WOLF");
		clapTrap1.showStatus();
	}

	std::cout << std::endl;
	i = -1;
	while (++i < 3) {
		clapTrap2.beRepaired(5);
		clapTrap2.showStatus();
	}
	clapTrap2.takeDamage(100);
	clapTrap2.showStatus();
	
	std::cout << std::endl;
	i = -1;
	while (++i < 3) {
		clapTrap3.takeDamage(5);
		clapTrap3.attack("BEAR");
		clapTrap3.showStatus();
	}
	clapTrap3.beRepaired(500);
	clapTrap3.showStatus();
	std::cout << std::endl;

	return (0);
}
