/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:19:54 by akurochk          #+#    #+#             */
/*   Updated: 2024/11/18 15:20:01 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <cstdlib>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		bool	readDataBase(std::string dataBaseFile);
		bool	handleInput(std::string inputFile);

	private:
		std::map<std::string, float>	_dataBase;
		std::map<std::string, float>	_input;
		std::string						_startDate;
		
		void	printExchange(std::string date, std::string value);

};

#endif
