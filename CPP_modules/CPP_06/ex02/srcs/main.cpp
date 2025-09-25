/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:43:41 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/15 21:05:26 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main() {
	Base *base = NULL;

	std::cout << std::endl << "Test NULL" << std::endl;
	identify(base);
	identify(*base);
	std::cout << std::endl;

	for (int i = 1; i < 6; i++) {
		std::cout << "Test "<< i << std::endl;
		base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	return (0);
}
