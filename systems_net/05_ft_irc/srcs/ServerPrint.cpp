/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerPrint.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:53:20 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 18:03:43 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::printStringVector(std::vector<std::string> v) {
	if(v.size() == 0) {
		return ;
	}
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << "[" << v[i] << "]";
		if (i + 1 < v.size())
			std::cout << GRN << "->" << RES;
	}
	std::cout << std::endl;
}

void	Server::printBuffer(std::string str) {
	std::cout << CYN << "[INFO]: buffer=[";
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n')
			std::cout << "\\n";
		else if (str[i] == '\r')
			std::cout << "\\r";
		else
			std::cout << str[i];
	}
	std::cout << "]" << RES << std::endl;
}

void	Server::printClientBuffer(Client client) {
	std::string str = client.getBuffer();

	std::cout << YEL << "[INFO]: client fd=" << client.getFd() << " buffer=[";
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n')
			std::cout << "\\n";
		else if (str[i] == '\r')
			std::cout << "\\r";
		else
			std::cout << str[i];
	}
	std::cout << "]" << RES << std::endl;
}

void	Server::printServer() {
		std::cout << std::endl << "SERVER INFO" << std::endl;

		// std::cout << "           _fd=[" << _fd << "]" << std::endl;
		// std::cout << "         _port=[" << _port << "]" << std::endl;
		// std::cout << " _stayTurnedOn=[" << _stayTurnedOn << "]" << std::endl;
		// std::cout << "     _password=[" << _password << "]" << std::endl;
		// std::cout << "   _serverName=[" << _serverName << "]" << std::endl;

		// // struct sockaddr_in			_serverAddress;
		// std::cout << "_serverAddress=[" << &_serverAddress << "]" << std::endl;

		// // struct pollfd				_clientIn;
		// std::cout << "     _clientIn=[" << &_clientIn << "]" << std::endl;

		// std::list<Client>			_clients;
		std::cout << "      _clients=[" << &_clients << "]" << std::endl;
		std::cout << "                size  ->[" << _clients.size() << "]" << std::endl;
		for (std::list<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
			std::cout << "                client->[" << &(*it)
					<< "] fd=[" << it->getFd()
					<< "]" << std::endl;
		}

		// std::list<Channel*>		_channels;
		std::cout << "     _channels=[" << &_channels << "]" << std::endl;
		std::cout << "                size   ->[" << _channels.size() << "]" << std::endl;
		for (std::list<Channel>::iterator it = _channels.begin(); it != _channels.end(); it++) {
			std::cout << "                channel->[" << &(*it)
					<< "] name=[" << it->getName()
					<< "] Op=[" << it->getOperators().size()
					<< "] Cl=[" << it->getClients().size()
					<< "]" << std::endl;
		}

		// // std::vector<struct pollfd>	_fds;
		// std::cout << "          _fds=[" << &_fds << "]" << std::endl;

		std::cout << std::endl;
}
