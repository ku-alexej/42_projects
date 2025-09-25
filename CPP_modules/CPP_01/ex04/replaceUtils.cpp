/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:29 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/10 17:09:26 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceUtils.hpp"

void	argvChecker(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		std::cout << "Usage: ./replace <filename> <string_to_find> <string_to_replace>" << std::endl;
		exit(1);
	}
	if (std::string(argv[2]).empty() || std::string(argv[3]).empty()) {
		std::cout << "Error: empty string" << std::endl;
		exit(1);
	}
}

void	fileCheckerIn(std::ifstream &file, std::string filename) {
	if (file.fail()) {
		std::cerr << "Error: couldn't open or create \"" << filename << "\"" << std::endl;
		exit(1);
	}
}

void	fileCheckerOut(std::ofstream &file, std::string filename) {
	if (file.fail()) {
		std::cerr << "Error: couldn't open or create \"" << filename << "\"" << std::endl;
		exit(1);
	}
}

std::string	replaceLoop(std::string &buffer, std::string &s1, std::string &s2) {
	size_t	curr = 0;

	while ((curr = buffer.find(s1, curr)) != std::string::npos) {
		buffer = buffer.substr(0, curr) + s2 + buffer.substr(curr + s1.length());
		curr += s2.length();
	}
	return (buffer);
}