/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerCommands.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:52:12 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 19:18:23 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::exec(std::string cmd, int fd) {
	
	std::vector<std::string> tokens = splitIrssiCommandinToken(cmd);

	if (tokens.size() < 1) {
		return ;
	}

	bool	isRegistred = getClientByFd(fd)->getRegistred(); 
	bool	isBasicCmd = (tokens[0] == "PASS" || tokens[0] == "CAP" || tokens[0] == "NICK" || tokens[0] == "USER" || tokens[0] == "QUIT");
	
	std::cout << "[INFO]: " << YEL << "fd=" << RES << fd << GRN << " token=" << RES;
	printStringVector(tokens);
	if (isBasicCmd == false) {
		if (isRegistred == false) {
			return ;
		}
	}
	std::cout << "[INFO]: try to handle \'" << YEL << tokens[0] << RES << "\'" << std::endl;

	std::map<std::string, void (Server::*)(std::vector<std::string>, int)>::iterator it;
	for (it = _cmdMap.begin(); it != _cmdMap.end(); it++) {
		if (it->first == tokens[0]) {
			(this->*(it->second))(tokens, fd);
			return ;
		}
	}

	Client *c = getClientByFd(fd);
	c->setReplyBuffer(ERR_UNKNOWNCOMMAND(c->getUsername(), tokens[0]));
}
