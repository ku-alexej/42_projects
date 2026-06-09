/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdPASS.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:57:28 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 18:07:33 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::cmdPass(std::vector<std::string> tokens, int fd) {
	Client *c = getClientByFd(fd);

	if(c->getPassOk()) {
		c->setReplyBuffer(ERR_ALREADYREGISTERED(c->getNickname()));
		return ;
	}

	// protocol: last parameter is used as a password
	size_t i = tokens.size() - 1;

	if(tokens.size() < 2 || tokens[i] == "") {
		c->setReplyBuffer(ERR_NEEDMOREPARAMS(c->getNickname(), tokens[0]));
		return ;
	}

	if(tokens[i] != _password) {
		c->setReplyBuffer(ERR_PASSWDMISMATCH(c->getNickname()));
		disconnectClient(fd, "Wrong password");
		return ;
	}

	c->setPassOk(true);

	if(c->getPassOk() && c->getNickname() != "" && c->getUsername() != "" && !c->getCapOn()) {
		c->setRegistred(true);
		c->setReplyBuffer(RPL_ISSUPPORT(c->getNickname()));
		c->setReplyBuffer(RPL_WELCOME(c->getNickname(), c->getNickname(), c->getUsername(), c->getHostname()));
	}
}
