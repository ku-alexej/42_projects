/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdTOPIC.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:11:17 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 17:21:45 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

// === in irssi documentation ===
// TOPIC [-delete]	[<channel>]		[:<topic>]								// syntax of irssi (all 3 elem -> set topic)
// TOPIC 			[#ch]													// show topic of #ch
// TOPIC 			[#ch] 			[:The] [robots] [are] [taking] [over!]	// set topic of #ch
// TOPIC [-delete]	[#ch]													// delete topic of #ch
// TOPIC 			[#shakespeare]	[:/bb|[^b]{2}/]							// set topic

void Server::cmdTopic(std::vector<std::string> tokens, int fd) {

	std::string	comment;
	Channel		*ch;
	Client		*c = getClientByFd(fd);

	if (c->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOTREGISTERED(c->getNickname()));
		return ;
	}

	if (tokens.size() < 2) {
		c->setReplyBuffer(ERR_NEEDMOREPARAMS(c->getNickname(), tokens[0]));
		return ;
	}

	ch = getChannel(tokens[1]);

	if (ch == NULL) {
		c->setReplyBuffer(ERR_NOSUCHCHANNEL(c->getNickname(), tokens[1]));
		return ;
	}

	if (ch->getClientByFd(fd) == NULL) {
		c->setReplyBuffer(ERR_NOTONCHANNEL(c->getNickname(), ch->getName()));
		return ;
	}

	// get topic
	if (tokens.size() == 2) {
		if (ch->getTopicText().empty() == true) {
			c->setReplyBuffer(RPL_NOTOPIC(c->getNickname(), ch->getName()));
		} else {
			c->setReplyBuffer(RPL_TOPIC(c->getNickname(), ch->getName(), ch->getTopicText()));
		}
		return ;
	}

	// if topic protected not operators will be stopped here
	if (ch->getT() == true && ch->getOperatorByFd(fd) == NULL ) {
		c->setReplyBuffer(ERR_CHANOPRIVSNEEDED(c->getNickname(), ch->getName()));
		return;
	}

	// delete topic
	if (tokens.size() == 3 && tokens[2] == ":") {
		ch->setTopicText("");
		ch->setReplyBufferForAllChannelClients(TOPIC(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), ""));
		return;
	}

	// set topic
	std::string	topic = "";
	if (tokens[2][0] == ':') {
		tokens[2].erase(tokens[2].begin());
		for (size_t i = 2; i < tokens.size(); i++) {
			topic += tokens[i];
				if (topic[topic.size() - 1] != ' ' && i < tokens.size() - 1 ) {
					topic += " ";
				}
		}
	} else {
		topic += tokens[2];
	}

	ch->setTopicText(topic);
	ch->setReplyBufferForAllChannelClients(TOPIC(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), topic));
}
