/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdPART.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:11:12 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 17:24:05 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::deleteEmptyChannel(Channel *channel) {

	if (channel->getClients().size() == 0) {
		std::vector<Client *> clients = channel->getClients();
		for (std::vector<Client *>::iterator it = clients.begin(); it != clients.end(); ++it) {
			(*it)->deleteInvite(channel->getName());
		}
		deleteChannel(channel->getName());
	}
}

void	Server::cmdPart(std::vector<std::string> tokens, int fd) {

	Client						*c = getClientByFd(fd);
	Channel						*channel;
	std::string					reason = "";
	std::vector<std::string>	channelsNames;

	if (c->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOTREGISTERED(c->getNickname()));
		return ;
	}

	if (tokens.size() < 2) {
		c->setReplyBuffer(ERR_NEEDMOREPARAMS(c->getUsername(), tokens[0]));
		return;
	}

	if (tokens.size() > 2) {
		if (tokens[2][0] == ':') {
			tokens[2].erase(tokens[2].begin());
			for (size_t i = 2; i < tokens.size(); i++) {
				reason += tokens[i];
				if (reason[reason.size() - 1] != ' ' && i < tokens.size() - 1 ) {
					reason += " ";
				}
			}
		} else {
			reason += tokens[2];
		}
	}

	channelsNames = split(tokens[1], ',');
	for (size_t i = 0; i < channelsNames.size(); i++) {
		channel = getChannel(channelsNames[i]);

		if (channel == NULL) {
			c->setReplyBuffer(ERR_NOSUCHCHANNEL(c->getNickname(), channelsNames[i]));
			return;
		}

		if (channel->getClientByFd(c->getFd()) == NULL) {
			c->setReplyBuffer(ERR_NOTONCHANNEL(c->getNickname(), channelsNames[i]));
			return;
		}

		std::stringstream msg;
		msg << c->getUserID() << " PART " << channel->getName() << " :" << reason;

		c->deleteChannel(channelsNames[i]);
		channel->deleteOperator(c);
		channel->deleteClient(c);

		c->setReplyBuffer(msg.str());
		channel->setReplyBufferForAllChannelClients(msg.str());

		deleteEmptyChannel(channel);
	}
}
