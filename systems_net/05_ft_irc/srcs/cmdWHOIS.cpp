/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdWHOIS.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:57:16 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/10 14:26:23 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::cmdWhois(std::vector<std::string> tokens, int fd) {
	Client *c = getClientByFd(fd);
	Client *t;

	if (c->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOTREGISTERED(c->getNickname()));
		return ;
	}

	if (tokens.size() < 2 || tokens[1].empty()) {
		c->setReplyBuffer(ERR_NONICKNAMEGIVEN(c->getNickname()));
		return ;
	}

	if (tokens.size() >= 3  && tokens[1] != _serverName && tokens[1] != tokens[1]) {
		c->setReplyBuffer(ERR_NOSUCHSERVER(c->getNickname(), tokens[1]));
		return ;
	}

	(tokens.size() >= 3) ? t = getClientByNick(tokens[2]) : t = getClientByNick(tokens[1]);

	if (t == NULL || t->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOSUCHNICK(c->getNickname(), ((tokens.size() >= 3) ? tokens[2] : tokens[1])));
		return ;
	}

	c->setReplyBuffer(RPL_WHOISUSER(c->getNickname(), t->getNickname(), t->getUsername(), t->getHostname(), t->getRealname()));
	c->setReplyBuffer(RPL_ENDOFWHOIS(c->getNickname(), c->getNickname()));
}
