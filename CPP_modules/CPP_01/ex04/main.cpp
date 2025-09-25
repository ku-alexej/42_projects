/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:29:55 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/10 17:34:59 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceUtils.hpp"

int	main(int argc, char **argv) {
	argvChecker(argc, argv);
	
	std::string	fileIn = argv[1];
	std::string	fileOut = argv[1] + std::string(".replace");
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	buffer;

	std::ifstream input(fileIn.c_str());
	fileCheckerIn(input, fileIn);
	
	std::ofstream output(fileOut.c_str());
	fileCheckerOut(output, fileOut);

	if (s1.compare(s2) != 0) {
		while (std::getline(input, buffer)) {
			output << replaceLoop(buffer, s1, s2) << std::endl;
		}
	} else {
		output << input.rdbuf();		
	}

	input.close();
	output.close();

	return (0);
}
