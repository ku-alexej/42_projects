/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:24:57 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/14 16:58:31 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other)
		;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static int isNanOrInf(double value, const std::string &input) {
	if (input != "nan" && input != "+inf" && input != "-inf"
		&& input != "nanf" && input != "+inff" && input != "-inff") {
		return (0);
	}
	if (std::isnan(value)) {
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		std::cout << "float:  nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (1);
	} else if (std::isinf(value)) {
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		if (value > 0) {
			std::cout << "float:  +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		} else {
			std::cout << "float:  -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		return (1);
	}
	return (0);
}

static int isNumber(double value, char *s) {
	if ((s[0] == '\0' || (s[0] == 'f' && s[1] == '\0')) && !std::isinf(value)) {
		std::cout << "char:   ";
		if ((value >= 32 && value <= 126))
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		else if (value >= 0 && value <= 31)
			std::cout << "Non printable" << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "int:    ";
		if ((value <= std::numeric_limits<int>::max() && value >= std::numeric_limits<int>::min()))
			std::cout << static_cast<int>(value) << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "float:  ";
		if ((value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
			&& (value < -std::numeric_limits<float>::max() || value > -std::numeric_limits<float>::min()) && value != 0)
			std::cout << "impossible" << std::endl;
		else if (value - static_cast<int>(value) == 0)
			std::cout << static_cast<float>(value) << ".0f" << std::endl;
		else
			std::cout << static_cast<float>(value) << "f" << std::endl;

		std::cout << "double: ";
		if ((value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min())
			&& (value < -std::numeric_limits<double>::max() || value > -std::numeric_limits<double>::min()) && value != 0)
			std::cout << "impossible" << std::endl;
		else if (value - static_cast<int>(value) == 0)
			std::cout << value << ".0" << std::endl;
		else
			std::cout << value << std::endl;
		return (1);
	}
	return (0);
}

static int isChar(const std::string &input) {
	if (input.length() == 1 && isprint(input[0])){
		std::cout << "char:   " << "'" << input[0] << "'" << std::endl;
		std::cout << "int:    " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float:  " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double> (input[0]) << ".0" <<std::endl;
		return (1);
	}
	return (0);
}

void ScalarConverter::convert(const std::string &input) {
	char	*s = NULL;
	double	value = strtod(input.c_str(), &s);
	
	if (isNanOrInf(value, input))
		return ;
	if (isNumber(value, s))
		return ;
	if (isChar(input))
		return ;

	std::cout <<"char:   impossible"<< std::endl;
	std::cout <<"int:    impossible"<< std::endl;
	std::cout <<"float:  impossible"<< std::endl;
	std::cout <<"double: impossible"<< std::endl;
}
