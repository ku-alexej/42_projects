/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdINVITE.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:11:03 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 17:36:40 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void  Server::cmdInvite(std::vector<std::string> tokens, int fd) {

  Client  *c = getClientByFd(fd);
  Client  *t;
  Channel *ch;

	if (c->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOTREGISTERED(c->getNickname()));
		return ;
	}

	// Here we MAY add this:
	//		Servers MAY allow the INVITE with no parameter, 
	//		and reply with a list of channels the sender is invited to 
	//		as RPL_INVITELIST (336) numerics, ending with a RPL_ENDOFINVITELIST (337) numeric.
	// 
	// irssi cant sent INVITE with no parameter =( 
	//
	// if (tokens.size() == 1) {
	// 	std::vector<std::string> list = c->getInvites();
	// 	for (size_t i = 0; i < list.size(); i++) {
	// 		c->setReplyBuffer(RPL_INVITELIST(c->getNickname(), list[i]));
	// 	}
	// 	c->setReplyBuffer(RPL_ENDOFINVITELIST(c->getNickname()));
	// 	return ;
	// }

	if (tokens.size() != 3) {
		c->setReplyBuffer(ERR_NEEDMOREPARAMS(c->getUsername(), tokens[0]));
		return ;
	}

	ch = getChannel(tokens[2]);

	if (ch == NULL) {
		c->setReplyBuffer(ERR_NOSUCHCHANNEL(c->getNickname(), tokens[2]));
		return ;
	}

	if (ch->getClientByFd(c->getFd()) == NULL) {
		c->setReplyBuffer(ERR_NOTONCHANNEL(c->getNickname(), ch->getName()));
  		return ;
	}

	if (ch->getI() == true && ch->getOperatorByFd(c->getFd()) == NULL) {
		c->setReplyBuffer(ERR_CHANOPRIVSNEEDED(c->getNickname(), ch->getName()));
		return ;
	}

	t = getClientByNick(tokens[1]);
	if (t == NULL) {
		c->setReplyBuffer(ERR_NOSUCHNICK(c->getNickname(), tokens[1]));
		return ;
	}

	if (t->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOTREGISTERED(t->getNickname()));
		return ;
	}

	if (ch->getClientByFd(t->getFd())) {
		c->setReplyBuffer(ERR_USERONCHANNEL(c->getNickname(), t->getNickname(), ch->getName()));
		return ;
	}

	if (t->isInvitedToChannel(ch->getName()) == false) {
		t->addInvite(ch->getName());
	}

	c->setReplyBuffer(RPL_INVITING(c->getNickname(), t->getNickname(), ch->getName()));
	t->setReplyBuffer(INVITE(c->getNickname(), c->getUsername(), c->getHostname(), t->getNickname(), ch->getName()));
}
