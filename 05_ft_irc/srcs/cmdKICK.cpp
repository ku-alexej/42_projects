/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdKICK.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:11:08 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 17:24:41 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::cmdKick(std::vector<std::string> tokens, int fd) {

	Client						*c = getClientByFd(fd);
	Channel						*ch;
	std::string					reason = "";
	std::string					defaultReason = "Very boring and speaks about frogs all the time.";
	std::vector<std::string>	listToKick;

	if (c->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOTREGISTERED(c->getNickname()));
		return ;
	}

	if (tokens.size() < 3) {
		c->setReplyBuffer(ERR_NEEDMOREPARAMS(c->getNickname(), tokens[0]));
		return;
	}

	//prepare reason
	if (tokens.size() > 3) {
		if (tokens[3][0] == ':') {
			tokens[3].erase(tokens[3].begin());
			for (size_t i = 3; i < tokens.size(); i++) {
				reason += tokens[i];
				if (reason[reason.size() - 1] != ' ' && i < tokens.size() - 1 ) {
					reason += " ";
				}
			}
		} else {
			reason += tokens[3];
		}
	}
	if (reason.empty() == true) {
		reason = defaultReason;
	}

	ch = getChannel(tokens[1]);
	if (ch == NULL) {
		c->setReplyBuffer(ERR_NOSUCHCHANNEL(c->getNickname(), tokens[1]));
		return;
	}

	if (ch->getClientByFd(c->getFd()) == NULL) {
		c->setReplyBuffer(ERR_NOTONCHANNEL(c->getNickname(), ch->getName()));
		return;
	}

	if (ch->getOperatorByFd(c->getFd()) == NULL) {
		c->setReplyBuffer(ERR_CHANOPRIVSNEEDED(c->getNickname(), ch->getName()));
		return;
	}

	listToKick = split(tokens[2], ',');

	for (size_t i = 0; i < listToKick.size(); i++) {

		Client	*t = getClientByNick(listToKick[i]);

		if (t == NULL) {
			c->setReplyBuffer(ERR_USERNOTINCHANNEL(c->getNickname(), "*", ch->getName()));
			continue;
		}

		if (t->getNickname() == "") {
			c->setReplyBuffer(ERR_USERNOTINCHANNEL(c->getNickname(), "*", ch->getName()));
			continue;
		}

		if (ch->getClientByFd(t->getFd()) == NULL) {
			c->setReplyBuffer(ERR_USERNOTINCHANNEL(c->getNickname(), t->getNickname(), ch->getName()));
			continue;
		}

		ch->deleteClient(t);
		ch->deleteOperator(t);
		t->deleteChannel(ch->getName());

		ch->setReplyBufferForAllChannelClients(KICK(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), t->getNickname(), reason));
		t->setReplyBuffer(KICK(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), t->getNickname(), reason));

		deleteEmptyChannel(ch);
	}
}
