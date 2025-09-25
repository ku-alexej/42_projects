/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdJOIN.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:11:06 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 17:36:49 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

std::vector<std::string>	split(const std::string str, char delimiter) {

	std::vector<std::string>	v;
	std::stringstream			ss(str);
	std::string					element;

	while (std::getline(ss, element, delimiter)) {
		v.push_back(element);
	}

	return (v);
}

std::vector<std::pair<std::string, std::string> >	getChannelsToJoin(std::vector<std::string> tokens) {

	std::vector<std::pair<std::string, std::string> >	channelsToJoin;
	std::vector<std::string>							channelsNames;
	std::vector<std::string>							channelsKeys;

	channelsNames = split(tokens[1], ',');
	if (tokens.size() > 2) {
		channelsKeys = split(tokens[2], ',');
	}

	for (size_t i = 0; i < channelsNames.size(); i++) {
		if (i < channelsKeys.size() && !channelsKeys[i].empty()) {
			channelsToJoin.push_back(std::make_pair(channelsNames[i], channelsKeys[i]));
		} else {
			channelsToJoin.push_back(std::make_pair(channelsNames[i], ""));
		}
	}

	return (channelsToJoin);
}

void	Server::welcomeChannelReply(Client *c, Channel *ch) {

	c->setReplyBuffer(JOIN_OK(c->getNickname(), c->getNickname(), c->getHostname(), ch->getName()));

	if (!ch->getTopicText().empty()) {
		c->setReplyBuffer(RPL_TOPIC(c->getNickname(), ch->getName(), ch->getTopicText()));
	}

	std::string clientsList;
	for (size_t i = 0; i < ch->getClients().size(); i++) {
		Client *toReply = (ch->getClients())[i];
		if (ch->getOperatorByFd(toReply->getFd()) != NULL) {
			clientsList += "@";
		}

		clientsList += toReply->getNickname();

		if (i < ch->getClients().size()) {
			clientsList += " ";
		}
	}

	c->setReplyBuffer(RPL_NAMREPLY(c->getNickname(), "=", ch->getName(), clientsList));
	c->setReplyBuffer(RPL_ENDOFNAMES(c->getNickname(), ch->getName()));
}

void	Server::clientJoinChannelReply(Client *c, Channel *ch) {

	std::vector<Client *>	listClients = ch->getClients();

	for (size_t i = 0; i < listClients.size(); i++) {
		Client *toClient = listClients[i];
		if (toClient->getFd() != c->getFd()) {
			toClient->setReplyBuffer(JOIN_OK(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName()));
		}
	}
}

void	Server::createChannel(Client *c, std::string channelName) {

	Channel	newChannel;

	newChannel.setName(channelName);
	newChannel.addClient(c);
	newChannel.addOperator(c);
	_channels.push_back(newChannel);
	c->addChannel(channelName);

	welcomeChannelReply(c, getChannel(channelName));
}

void	Server::joinChannel(Client *c, Channel *ch, std::string key) {

	//already on channel - ignore JOIN
	if (ch->getClientByFd(c->getFd()) != NULL) {
		return ;
	}

	//invite
	if (ch->getI() == true && c->isInvitedToChannel(ch->getName()) == false) {
		c->setReplyBuffer(ERR_INVITEONLYCHAN(c->getNickname(), ch->getName()));
		return ;
	}

	//pass
	if (ch->getK().empty() == false && (key.empty() == true || key != ch->getK())) {
		c->setReplyBuffer(ERR_BADCHANNELKEY(c->getNickname(), ch->getName()));
		return ;
	}

	//limit
	if (ch->getL() != 0 && (size_t)ch->getL() <= ch->getClients().size()) {
		c->setReplyBuffer(ERR_CHANNELISFULL(c->getNickname(), ch->getName()));
		return ;
	}

	ch->addClient(c);
	c->addChannel(ch->getName());
	c->deleteInvite(ch->getName());

	welcomeChannelReply(c, ch);
	clientJoinChannelReply(c, ch);
}

void	Server::cmdJoin(std::vector<std::string> tokens, int fd) {

	Client	*c = getClientByFd(fd);
	Channel	newChannel;

	if (c->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOTREGISTERED(c->getNickname()));
		return ;
	}

	// not enough params
	if (tokens.size() < 2) {
		c->setReplyBuffer(ERR_NEEDMOREPARAMS(c->getUsername(), tokens[0]));
		return ;
	}

	// too much params
	if (tokens.size() > 3) {
		c->setReplyBuffer(ERR_NEEDMOREPARAMS(c->getUsername(), tokens[0]));
		return ;
	}

	std::vector<std::pair<std::string, std::string> > channelsToJoin = getChannelsToJoin(tokens);

	for (size_t i = 0; i < channelsToJoin.size(); i++) {
		std::string channelName = channelsToJoin[i].first;
		Channel *ch = getChannel(channelName);

		if (isValidChannelName(channelName) != true) {
			c->setReplyBuffer(ERR_BADCHANMASK(channelName));
			continue;
		}

		if (ch == NULL) {
			createChannel(c, channelName);
		} else {
			joinChannel(c, ch, channelsToJoin[i].second);
		}
	}
}
