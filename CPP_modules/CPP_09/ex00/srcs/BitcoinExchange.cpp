/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:19:57 by akurochk          #+#    #+#             */
/*   Updated: 2024/11/14 17:14:19 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Canonical form

BitcoinExchange::BitcoinExchange() {
	this->_startDate = "9999-12-31";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	this->_dataBase = other._dataBase;
	this->_input = other._input;
	this->_startDate = other._startDate;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_dataBase = other._dataBase;
		this->_input = other._input;
		this->_startDate = other._startDate;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// Common

static bool	dayIsValid(std::string date) {
	int day = std::atoi(date.substr(8, 2).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int year = std::atoi(date.substr(0, 4).c_str());
	int daysLeapYear[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int daysCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12)
		return (false);
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		return ((day < 1 || day > daysLeapYear[month - 1]) ? false : true);
	} else {
		return ((day < 1 || day > daysCommonYear[month - 1]) ? false : true);
	}
}

static bool	dateIsValid(std::string date) {
	if (date.length() != 10 || date.find_first_not_of("0123456789-") != std::string::npos
		|| date[4] != '-' || date[7] != '-'	|| !dayIsValid(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return (false);
	}
	return (true);
}

// Read base

static bool	isDataLineValid(std::string line) {
	if (line.find_first_not_of("0123456789-+.,") != std::string::npos)
		return (false);
	if (line.length() < 12)
		return (false);
	if (line[10] != ',')
		return (false);
	return (true);
}

static bool	exchangeRateIsValid(std::string r) {
	char *endPtr;
	
	if (r.empty()) {
		std::cerr << "Error: exchange rate is empty" << std::endl;
		return (false);
	} 

	if (r.find_first_not_of("0123456789-+.") != std::string::npos) {
		std::cerr << "Error: invalid exchange rate format: " << r << std::endl;
		return (false);
	}
	
	try {
		double val = strtod(r.c_str(), &endPtr);
		if (*endPtr != '\0') {
			std::cerr << "Error: invalid exchange rate format: " << r << std::endl;
			return (false);
		}
		if (val < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			return (false);
		}
	} catch (std::exception &e) {
		std::cerr << "Error: invalid exchange rate format: " << r << std::endl;
		return (false);
	}
	
	return (true);
}

bool	BitcoinExchange::readDataBase(std::string dataBaseFile) {
	std::ifstream file;
	std::string line;

	file.open(dataBaseFile.c_str());
	if (!file.is_open() || !file.good()) {
		std::cerr << "Error: could not open data file" << std::endl;	
		return (false);
	}

	std::getline(file, line);
	if (line != "date,exchange_rate") {
		std::cerr << "Error: bad data header => " << std::endl;
		return (false);
	}

	while (std::getline(file, line)) {
		std::string date;
		std::string exchange_rate;
		
		if (!isDataLineValid(line)) {
			std::cerr << "Error: bad data => " << std::endl;
			return (false);
		}
	
		date = line.substr(0, 10);
		exchange_rate = line.substr(11, line.length());
		if (!dateIsValid(date) || !exchangeRateIsValid(exchange_rate))
			return (false);	
		_dataBase.insert(std::pair<std::string, float>(date, std::atof(exchange_rate.c_str())));
		if (_startDate > date)
			_startDate = date;
	}
	
	if (_dataBase.size() < 1) {
		std::cerr << "Error: data file is empty" << std::endl;
		return (false);
	}

	return (true);
}

// Handle input

static bool	isInputLineValid(std::string line) {
	if (line.find_first_not_of("0123456789-+.| ") != std::string::npos)
		return (false);
	if (line.length() < 14)
		return (false);
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return (false);
	return (true);
}

static bool	valueIsValid(std::string v) {
	char *endPtr;
	
	if (v.empty()) {
		std::cerr << "Error: value is empty" << std::endl;
		return (false);
	} 

	if (v.find_first_not_of("0123456789-+.") != std::string::npos) {
		std::cerr << "Error: bad input => " << v << std::endl;
		return (false);
	}
	
	try {
		double val = strtod(v.c_str(), &endPtr);
		if (*endPtr != '\0') {
			std::cerr << "Error: bad input => " << v << std::endl;
			return (false);
		}
		if (val < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			return (false);
		}
		if (val > 1000) {
			std::cerr << "Error: too large number." << std::endl;
			return (false);
		}
	} catch (std::exception &e) {
		std::cerr << "Error: bad input => " << v << std::endl;
		return (false);
	}
	
	return (true);
}

void	BitcoinExchange::printExchange(std::string date, std::string value) {
	if (date < _dataBase.begin()->first) {
		std::cerr << "Error: bad input, date is out of data range => " << date << std::endl;
		return ;
	}
	std::map<std::string, float>::iterator it = _dataBase.lower_bound(date);
	if (it == _dataBase.end() || it->first != date)
		--it;
	std::cout << date << " => " << value << " = " << it->second * static_cast <float> (strtod(value.c_str(), NULL)) << std::endl;
}

bool	BitcoinExchange::handleInput(std::string inputFile) {
	std::ifstream file;
	std::string line;

	file.open(inputFile.c_str());
	if (!file.is_open() || !file.good()) {
		std::cerr << "Error: could not open file" << std::endl;
		return (false);
	}

	std::getline(file, line);
	if (line != "date | value") {
		std::cerr << "Error: bad input header => " << line << std::endl;
		return (false);
	}

	while (std::getline(file, line)) {
		std::string date;
		std::string value;
		
		if (line.length() == 0) {
			std::cerr << "Error: bad input => empty line" << line << std::endl;
			continue;
		}
		
		if (!isInputLineValid(line)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	
		date = line.substr(0, 10);
		value = line.substr(13, line.length());
		if (!dateIsValid(date) || !valueIsValid(value))
			continue;
		if (date < _startDate) {
			std::cerr << "Error: bad input, date is out of data range => " << date << std::endl;
			continue;
		}

		printExchange(date, value);
	}
	
	return (true);
}

