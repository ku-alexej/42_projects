/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdMODE.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:11:10 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 18:08:55 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::cmdUserMode(std::vector<std::string> tokens, int fd) {

	Client *c = getClientByFd(fd);
	Client *t = getClientByNick(tokens[1]);

	if (t == NULL || t->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOSUCHNICK(c->getNickname(), tokens[1]));
		return ;
	}

	if (toLower(c->getNickname()) != toLower(tokens[1])) {
		c->setReplyBuffer(ERR_USERSDONTMATCH(c->getNickname()));
		return ;
	}

	if (tokens.size() == 2) {
		c->setReplyBuffer(RPL_UMODEIS(c->getNickname(), ""));
		return ;
	}

	c->setReplyBuffer(ERR_UMODEUNKNOWNFLAG(c->getNickname(), tokens[2]));
}

static bool	isUsableMode(std::string mode) {

	if (mode[1] == 't' || mode[1] == 'i' || mode[1] == 'l' || mode[1] == 'k' || mode[1] == 'o') {
		return (true);
	}

	return (false);
}

// according the Protocol [+behklovIO] [-behkovIO] use variables =(
// so we have to collect variables but then can use only commands from subject: [+tilk] [-tilk]
static bool	isVariableNeeded(char c, char sign) {

	std::string mode;
	mode += c;

	if (sign == '+') {
		if (mode.find_first_not_of("behklovIO") == std::string::npos) {
			return (true);
		}
	}

	if (sign == '-') {
		if (mode.find_first_not_of("behkovIO") == std::string::npos) {
			return (true);
		}
	}

	return (false);
}

void	Server::setModeT(std::vector<std::string> tokens, int fd, std::string mode, std::string variable) {

	(void) variable;

	Channel	*ch = getChannel(tokens[1]);
	Client	*c = getClientByFd(fd);

	switch (mode[0]) {
		case '+':
			if (ch->getT() == true) {
				return ;
			}
			ch->setT(true);
			ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, ""));
			break;
		case '-':
			if (ch->getI() == false) {
				return ;
			}
			ch->setI(false);
			ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, ""));
			break;
	}
}

void	Server::setModeI(std::vector<std::string> tokens, int fd, std::string mode, std::string variable) {

	(void) variable;

	Channel	*ch = getChannel(tokens[1]);
	Client	*c = getClientByFd(fd);

	switch (mode[0]) {
		case '+':
			if (ch->getI() == true) {
				return ;
			}
			ch->setI(true);
			ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, ""));
			break;
		case '-':
			if (ch->getI() == false) {
				return ;
			}
			ch->setI(false);
			ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, ""));
			break;
	}
}

static int	getNewLimitForChannel(std::string variable) {

	if (variable.find_first_not_of("+0123456789") != std::string::npos) {
		throw (std::invalid_argument("Invalid argument: /mode #channel +l argument"));
	}

	return (atoi(variable.c_str()));
}

void	Server::setModeL(std::vector<std::string> tokens, int fd, std::string mode, std::string variable) {

	Channel	*ch = getChannel(tokens[1]);
	Client	*c = getClientByFd(fd);

	switch (mode[0]) {
		case '+':
			try {
				int l = getNewLimitForChannel(variable);
				if (ch->getL() == l) {
					return ;
				}
				ch->setL(l);
				ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, variable));
			} catch (const std::exception &e) {
				c->setReplyBuffer(ERR_INVALIDMODEPARAM(c->getNickname(), ch->getName(), mode, variable, "use integer value"));
				return ;
			}
			break;
		case '-':
			if (ch->getL() != 0) {
				ch->setL(0);
				ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, ""));
			}
			break;
	}
}

void	Server::setModeK(std::vector<std::string> tokens, int fd, std::string mode, std::string variable) {

	Channel	*ch = getChannel(tokens[1]);
	Client	*c = getClientByFd(fd);

	switch (mode[0]) {
		case '+':
			if (variable.empty() == true) {
				return ;
			}
			ch->setK(variable);
			ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, variable));
			break;
		case '-':
			if (ch->getK().empty() == true || variable.empty() == true)	{	// if nothing to change
				return ;
			}
			if (ch->getK() != variable) {
				c->setReplyBuffer(ERR_INVALIDMODEPARAM(c->getNickname(), ch->getName(), mode, variable, "use -k <current key> to remove key mode"));
				return ;
			}

			ch->setK("");
			ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, ""));
			break;
	}
}

void	Server::setModeO(std::vector<std::string> tokens, int fd, std::string mode, std::string variable) {

	Channel	*ch = getChannel(tokens[1]);
	Client	*c = getClientByFd(fd);
	Client	*t;

	if (variable.empty() == true) {
		return ;
	}

	t = getClientByNick(variable);
	if (t == NULL || t->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOSUCHNICK(c->getNickname(), variable));
		return ;
	}

	if (ch->getClientByFd(t->getFd()) == NULL) {
		c->setReplyBuffer(ERR_USERNOTINCHANNEL(c->getNickname(), t->getNickname(), ch->getName()));
		return ;
	}

	switch (mode[0]) {
		case '+':
			if (ch->getOperatorByFd(t->getFd()) == NULL) {
				ch->addOperator(t);
				ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, variable));
			}
			break;
		case '-':
			if (ch->getOperatorByFd(t->getFd()) != NULL) {
				ch->deleteOperator(t);
				ch->setReplyBufferForAllChannelClients(MODE_SET(c->getNickname(), c->getUsername(), c->getHostname(), ch->getName(), mode, variable));
			}
			break;
	}
}

void	Server::setMode(std::vector<std::string> tokens, int fd, std::string mode, std::string variable) {

	// ignore mode
	if (isVariableNeeded(mode[1], mode[0]) && variable.empty()) {
		return ;
	}

	// set mode
	switch (mode[1]) {
		case 't':
			setModeT(tokens, fd, mode, variable);
			break;
		case 'i':
			setModeI(tokens, fd, mode, variable);
			break;
		case 'l':
			setModeL(tokens, fd, mode, variable);
			break;
		case 'k':
			setModeK(tokens, fd, mode, variable);
			break;
		case 'o':
			setModeO(tokens, fd, mode, variable);
			break;
	}
}

static void	setIndexes(std::string &modestring, std::vector<std::string> tokens, size_t &i, size_t &variableIndex) {

	if (i + 1 >= modestring.size() && variableIndex < tokens.size()) {
		modestring = tokens[variableIndex];
		i = 0;
		variableIndex++;
	}
}

void	Server::runModes(std::vector<std::string> tokens, int fd) {

	std::vector<std::pair<std::string, std::string> > modesToUse;
	std::string sign = "+";
	Client *c = getClientByFd(fd);

	// here we parse modes and theit variables
	std::string modestring = tokens[2];
	size_t variableIndex = 3;
	for (size_t i = 0; i < modestring.size(); i++) {
		if (modestring[i] == '+') {
			sign = "+";
			setIndexes(modestring, tokens, i, variableIndex);
			continue;
		} else if (modestring[i] == '-') {
			sign = "-";
			setIndexes(modestring, tokens, i, variableIndex);
			continue;
		}
		if (isVariableNeeded(modestring[i], sign[0])) {
			std::string mode = sign + modestring[i];
			std::string variable = (variableIndex < tokens.size()) ? tokens[variableIndex] : "";
			modesToUse.push_back(std::make_pair(mode, variable));
			variableIndex++;
			setIndexes(modestring, tokens, i, variableIndex);
		} else {
			std::string mode = sign + modestring[i];
			modesToUse.push_back(std::make_pair(mode, ""));
			setIndexes(modestring, tokens, i, variableIndex);
		}
	}

	// std::cout << "[MODE]=[variable]" << std::endl;
	// for (std::vector<std::pair<std::string, std::string> >::iterator it = modesToUse.begin(); it != modesToUse.end(); it++) {
	// 	std::cout << "[" + it->first + "]=[" + it->second + "]" << std::endl;
	// }

	//here we try to set each mode
	for (std::vector<std::pair<std::string, std::string> >::iterator it = modesToUse.begin(); it != modesToUse.end(); it++) {
		if (isUsableMode(it->first)) {
			setMode(tokens, fd, it->first, it->second);
		} else {
			c->setReplyBuffer(ERR_UNKNOWNMODE(c->getNickname(), it->first));
		}
	}
}


void	Server::cmdChannelMode(std::vector<std::string> tokens, int fd) {

	Client	*c = getClientByFd(fd);
	Channel	*ch = getChannel(tokens[1]);

	if (ch == NULL) {
		c->setReplyBuffer(ERR_NOSUCHCHANNEL(c->getNickname(), tokens[1]));
		return ;
	}

	if (tokens.size() == 2) {
		c->setReplyBuffer(RPL_CHANNELMODEIS(c->getNickname(), ch->getName(), ch->getModes(), ch->getModesArgs(ch->getClientByFd(fd) != NULL)));
		return ;
	}

	if (tokens.size() == 3 && tokens[2] == "b") {
		c->setReplyBuffer(RPL_ENDOFBANLIST(c->getNickname(), ch->getName()));
		return ;
	}

	if (ch->getClientByFd(fd) == NULL) {
		c->setReplyBuffer(ERR_NOTONCHANNEL(c->getNickname(), tokens[1]));
		return ;
	}

	if (ch->getOperatorByFd(fd) == NULL) {
		c->setReplyBuffer(ERR_CHANOPRIVSNEEDED(c->getNickname(), tokens[1]));
		return ;
	}

	runModes(tokens, fd);
}

void	Server::cmdMode(std::vector<std::string> tokens, int fd) {

	Client *c = getClientByFd(fd);

	if (c->getRegistred() == false) {
		c->setReplyBuffer(ERR_NOTREGISTERED(c->getNickname()));
		return ;
	}

	if (tokens.size() < 2 || tokens[1].empty()) {
		c->setReplyBuffer(ERR_NEEDMOREPARAMS(c->getUsername(), tokens[0]));
		return ;
	}

	// MODE for client: we have +i in irssi afer registration
	if (tokens[1][0] != '#') {
		cmdUserMode(tokens, fd);
		return ;
	}

	// MODE for channel: as in subject
	if (tokens[1][0] == '#') {
		cmdChannelMode(tokens, fd);
		return ;
	}
}
