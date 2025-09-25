/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:17:16 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/09 14:39:07 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	/* Stuck */
	randomChump("Stuck Zombie");
	
	/* Heap */
	Zombie *zombie = newZombie("Heap  Zombie");
	zombie->announce();
	delete zombie;

	return (0);	
}
