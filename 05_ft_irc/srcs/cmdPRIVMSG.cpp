/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdPRIVMSG.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:05:31 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 19:53:15 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::sendPrivateMsgToChannel(std::string channelName, std::string message, int fd) {
	Client	*c = getClientByFd(fd);
	Channel	*ch = getChannel(channelName);

	if (ch == NULL) {
		c->setReplyBuffer(ERR_NOSUCHCHANNEL(c->getNickname(), channelName));
		return ;
	}

	ch->setReplyBufferForAllChannelClientsExeptFd(PRIVMSG(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), message), fd);
}

void	Server::sendPrivateMsgToClient(std::string nickName, std::string message, int fd) {
	Client	*c = getClientByFd(fd);
	Client	*t = getClientByNick(nickName);

	if (t == NULL) {
		c->setReplyBuffer(ERR_NOSUCHNICK(c->getNickname(), nickName));
		return ;
	}

	if (t->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOSUCHNICK(c->getNickname(), nickName));
		return ;
	}

	t->setReplyBuffer(PRIVMSG(c->getNickname(), c->getUsername(), c->getHostname(), t->getNickname(), message));
}

// server doesn't use STATUSMSG=@
// so we no need to manage "sent to operators of channel" @#channel

// server doesn't use channe mode "+n"
// so clients can sent messages to channels even if they are not in this channels
void	Server::cmdPrivmsg(std::vector<std::string> tokens, int fd)
{
	Client      *c = getClientByFd(fd);
	std::string message = "";

	if (tokens.size() < 2) {
		c->setReplyBuffer(ERR_NORECIPIENT(c->getNickname(), tokens[0]));
		return ;
	}

	if (tokens[1][0] == ':') {
		c->setReplyBuffer(ERR_NORECIPIENT(c->getNickname(), tokens[0]));
		return ;
	}

	if (tokens.size() < 3) {
		c->setReplyBuffer(ERR_NOTEXTTOSEND(c->getNickname()));
		return ;
	}

	// prepare msg
	if (tokens.size() > 2) {
		if (tokens[2][0] == ':') {
			tokens[2].erase(tokens[2].begin());
			for (size_t i = 2; i < tokens.size(); i++) {
				message += tokens[i];
				if (message[message.size() - 1] != ' ' && i < tokens.size() - 1 ) {
					message += " ";
				}
			}
		} else {
			message += tokens[2];
		}
	}

	if (message.size() == 0) {
		c->setReplyBuffer(ERR_NOTEXTTOSEND(c->getNickname()));
		return ;
	}

	std::vector<std::string> targets = split(tokens[1], ',');

	for (size_t i = 0; i < targets.size(); i++) {
		std::string target = targets[i];

		if (target[0] == '#') {
			sendPrivateMsgToChannel(target, message, fd);
		} else {
			sendPrivateMsgToClient(target, message, fd);
		}
	}
}
