/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:29:23 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/15 18:13:02 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	{
		/* TESTS for ClapTrap */
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
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	{
		/* TESTS for ScavTrap */
		ScavTrap scavTrap1;
		scavTrap1.showStatus();
		ScavTrap scavTrap2("ScavTrap2");
		scavTrap2.showStatus();
		ScavTrap scavTrap3(scavTrap2);
		scavTrap3.showStatus();
		scavTrap3 = ScavTrap("ScavTrap3");
		int i;

		std::cout << std::endl;
		i = -1;
		while (++i < 5) {
			for (int j = 0; j < 10; j++)
				scavTrap1.attack("WOLF");
			scavTrap1.showStatus();
		}
		scavTrap1.attack("WOLF");
		scavTrap1.beRepaired(500);
		scavTrap1.guardGate();

		std::cout << std::endl;
		i = -1;
		while (++i < 3) {
			scavTrap2.beRepaired(5);
			scavTrap2.showStatus();
		}
		scavTrap2.takeDamage(500);
		scavTrap2.showStatus();
		scavTrap2.beRepaired(5);
		scavTrap2.guardGate();
		
		std::cout << std::endl;
		i = -1;
		while (++i < 3) {
			scavTrap3.takeDamage(40);
			scavTrap3.attack("BEAR");
			scavTrap3.showStatus();
		}
		scavTrap3.beRepaired(500);
		scavTrap3.showStatus();
		scavTrap3.guardGate();
		std::cout << std::endl;
	}
	return (0);
}
