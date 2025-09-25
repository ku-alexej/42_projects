/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:49:07 by akurochk          #+#    #+#             */
/*   Updated: 2025/01/16 17:47:27 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void validate(int ac, char **av) {
    int i = 0;
    std::string str;

	if (ac < 2)
		throw std::invalid_argument("Usage: ./PmergeMe [numbers]");

    while (++i < ac) {
        str = av[i];
        if (str.empty()) 
            throw std::invalid_argument("Error: empty element");
        for (size_t i = 0; i < str.length(); ++i)
            if (!isdigit(str[i]))
                throw std::invalid_argument("Error: element contain not a digit character");
        if (atol(str.c_str()) < 0 || atol(str.c_str()) > std::numeric_limits<int>::max())
            throw std::overflow_error("Error: int overflow");
    }
}

int main(int ac, char **av) {

	try {
		validate(ac, av);
        PmergeMe pm;
        pm.run(ac, av);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}

	return (0);
}
