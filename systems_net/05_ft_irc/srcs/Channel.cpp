/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:28:14 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 19:43:50 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

// --- constructors ---
Channel::Channel() {
	this->_l		= 0;		// 0		= unlimited number of clients
	this->_i		= false;	// false	= invite mot necessary
	this->_t		= false;	// false	= possible to change topic
	this->_k		= "";		// ""		= no password to join channel
	this->_tText	= "";
	this->_name		= "";
}

Channel::Channel(std::string name, Client *client, bool firstConnection) {

	this->_l		= 0;		// 0		= unlimited number of clients
	this->_i		= false;	// false	= invite mot necessary
	this->_t		= false;	// false	= possible to change topic
	this->_k		= "";		// ""		= no password to join channel
	this->_tText	= "";
	// this -> _password = "";
	this -> _name = name;
	if (firstConnection)
		this -> _operators.push_back(client);
	this -> _clients.push_back(client);
}

Channel::Channel(const Channel &src) {
	*this			= src;
}


// --- operators ---
Channel & Channel::operator=(const Channel &src) {
	if (this != &src) {
		this->_l			= src._l;
		this->_i			= src._i;
		this->_t			= src._t;
		this->_k			= src._k;
		this->_name			= src._name;
		this->_tText		= src._tText;
		this->_clients		= src._clients;
		this->_operators	= src._operators;
	}
	return (*this);
}

// --- destructors ---
Channel::~Channel() {}

// --- getters ---
int						Channel::getL()			{return (this->_l);}
bool					Channel::getI()			{return (this->_i);}
bool					Channel::getT()			{return (this->_t);}
std::string				Channel::getK()			{return (this->_k);}
std::string				Channel::getTopicText()	{return (this->_tText);}
std::vector<Client *>	Channel::getClients()	{return (this->_clients);}
std::vector<Client *>	Channel::getOperators()	{return (this->_operators);}
std::string 			Channel::getName() 		{return (this->_name);}


Client	*Channel::getClientByFd(int fd) {
	for (std::vector<Client *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++)
		if ((*it)->getFd() == fd) {
			return (*it);
		}
	return (NULL);
}

Client	*Channel::getOperatorByFd(int fd) {
	for (std::vector<Client *>::iterator it = this->_operators.begin(); it != this->_operators.end(); it++)
		if ((*it)->getFd() == fd) {
			return (*it);
		}
	return (NULL);
}

// --- setters ---
void	Channel::setL(int newL)							{this->_l		= newL;}
void	Channel::setI(bool isI)							{this->_i		= isI;}
void	Channel::setT(bool isT)							{this->_t		= isT;}
void	Channel::setK(std::string newK)					{this->_k		= newK;}
void	Channel::setTopicText(std::string newTopicText)	{this->_tText	= newTopicText;}
void	Channel::setName(std::string newName)			{this->_name	= newName;}

// --- member functions ---
void	Channel::addClient(Client *newClient) {
	for (std::vector<Client *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++)
		if ((*it)->getFd() == newClient->getFd())
			return ;
	this->_clients.push_back(newClient);
}

void	Channel::deleteClient(Client *toDelete) {
	for (std::vector<Client *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++)
		if ((*it)->getFd() == toDelete->getFd()) {
			this->_clients.erase(it);
			return ;
		}
}

void	Channel::clearClients() {
	this->_clients.clear();
}

void	Channel::addOperator(Client *newOperator) {
	for (std::vector<Client *>::iterator it = this->_operators.begin(); it != this->_operators.end(); it++)
		if ((*it)->getFd() == newOperator->getFd())
			return ;
	this->_operators.push_back(newOperator);
}

void	Channel::deleteOperator(Client *toDelete) {
	for (std::vector<Client *>::iterator it = this->_operators.begin(); it != this->_operators.end(); it++)
		if ((*it)->getFd() == toDelete->getFd()) {
			this->_operators.erase(it);
			return ;
		}
}

void	Channel::clearOperators() {
	this->_operators.clear();
}

std::string	Channel::getModes() {
	std::string modes = "+";
	modes += (_t == false ? "" : "t");
	modes += (_i == false ? "" : "i");
	modes += (_l == 0 ? "" : "l");
	modes += (_k.empty() ? "" : "k");
	return (modes);
}

std::string	Channel::getModesArgs(bool isOnChannel) {
	std::string args = "";

	std::stringstream buff;
	buff << _l;
	std::string lString = buff.str();

	if (isOnChannel) {
		args += (_l != 0 ? lString : "");
		args += (_l != 0 && !(_k.empty()) ? " " : "");
		args += (_k.empty() ? "" : _k);
	}
	return (args);
}

void	Channel::setReplyBufferForAllChannelClients(std::string msg) {
	for (std::vector<Client *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++) {
		(*it)->setReplyBuffer(msg);
	}
}

void	Channel::setReplyBufferForAllChannelClientsExeptFd(std::string msg, int fd) {
	for (std::vector<Client *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++) {
		if ((*it)->getFd() != fd) {
			(*it)->setReplyBuffer(msg);
		}
	}
}

bool isValidChannelName(const std::string &channel) {
	if (channel.empty())
		return false;

	char firstChar = channel[0];
	if (firstChar != '#')
		return false;

	for (std::size_t i = 0; i < channel.size(); ++i) {
		char c = channel[i];
		if (c == ' ' || c == '\a' || c == ',')
			return false;
	}

	return true;
}
