/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:28:15 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/11 20:10:06 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include "Replyes.hpp"

// --- constructors ---
Client::Client() {
	this->_fd			= -1;
	this->_capOn		= false;
	this->_online		= false;
	this->_operator		= false;
	this->_passOk		= false;
	this->_registred	= false;
	this->_replyBuffer	= "";
	this->_buffer		= "";
	this->_ip			= "";
	this->_username		= "";
	this->_hostname		= "";
	this->_realname		= "";
	this->_nickname		= "";
}

Client::Client(const Client &src) {
	*this				= src;
}

Client::Client(int fd, std::string username, std::string nickname) {
	this->_fd			= fd;
	this->_capOn		= false;
	this->_online		= false;
	this->_operator		= false;
	this->_passOk		= false;
	this->_registred	= false;
	this->_replyBuffer	= "";
	this->_buffer		= "";
	this->_ip			= "";
	this->_username		= username;
	this->_hostname		= "";
	this->_realname		= "";
	this->_nickname		= nickname;
}

// --- operators ---
Client	&Client::operator=(const Client &src) {
	if (this != &src) {
		this->_fd			= src._fd;
		this->_capOn		= src._capOn;
		this->_online		= src._online;
		this->_operator		= src._operator;
		this->_passOk		= src._passOk;
		this->_registred	= src._registred;
		this->_replyBuffer	= src._replyBuffer;
		this->_buffer		= src._buffer;
		this->_ip			= src._ip;
		this->_username		= src._username;
		this->_hostname		= src._hostname;
		this->_realname		= src._realname;
		this->_nickname		= src._nickname;
		this->_invites		= src._invites;
	}
	return (*this);
}

// --- destructors ---
Client::~Client() {}

// --- getters ---
int							Client::getFd()				{return (this->_fd);}
bool						Client::getCapOn()			{return (this->_capOn);}
bool						Client::getOnline()			{return (this->_online);}
bool						Client::getOperator()		{return (this->_operator);}
bool						Client::getPassOk()			{return (this->_passOk);}
bool						Client::getRegistred()		{return (this->_registred);}
std::string					Client::getReplyBuffer()	{return (this->_replyBuffer);}
std::string					Client::getBuffer()			{return (this->_buffer);}
std::string					Client::getIp()				{return (this->_ip);}
std::string					Client::getUsername()		{return (this->_username);}
std::string					Client::getHostname()		{return (this->_hostname);}
std::string					Client::getRealname()		{return (this->_realname);}
std::string					Client::getNickname()		{return (this->_nickname);}
std::vector<std::string>	Client::getInvites()		{return (this->_invites);}
std::vector<std::string>	Client::getChannelNames()	{return (this->_channelNames);}

std::string	Client::getUserID() {
	std::string userID = ":" + getNickname() + "!" + getUsername() + "@localhost";
	return (userID);
}

// --- setters ---
void	Client::setFd(int newFd)							{this->_fd			= newFd;}
void	Client::setCapOn(bool isCapOn)						{this->_capOn		= isCapOn;}
void	Client::setOnline(bool isOnline)					{this->_online		= isOnline;}
void	Client::setOperator(bool isOperator)				{this->_operator	= isOperator;}
void	Client::setPassOk(bool isPassOk)					{this->_passOk		= isPassOk;}
void	Client::setRegistred(bool isRegistred)				{this->_registred	= isRegistred;}
void	Client::setBuffer(std::string newBuffer)			{this->_buffer		+= newBuffer;}
void	Client::setIp(std::string newIp)					{this->_ip			= newIp;}
void	Client::setUsername(std::string newUsername)		{this->_username	= newUsername;}
void	Client::setHostname(std::string newHostname)		{this->_hostname	= newHostname;}
void	Client::setRealname(std::string newRealname)		{this->_realname	= newRealname;}
void	Client::setNickname(std::string newNickname)		{this->_nickname	= newNickname;}

void	Client::setReplyBuffer(std::string newReply) {
	if(newReply.size() > CMD_LEN - 2) {
		newReply.resize(CMD_LEN - 2);
	}
	this->_replyBuffer += (newReply + CRLF);
}

// --- member functions ---
void	Client::clearReplyBuffer() {
	this->_replyBuffer.clear();
}

void	Client::clearBuffer() {
	this->_buffer.clear();
}

void	Client::addInvite(std::string newInvite) {
	for (std::vector<std::string>::iterator it = this->_invites.begin(); it != this->_invites.end(); it++) {
		if (toLower(*it) == toLower(newInvite))
			return ;
	}
	this->_invites.push_back(newInvite);
}

void	Client::deleteInvite(std::string toDelete) {
	for (std::vector<std::string>::iterator it = this->_invites.begin(); it != this->_invites.end(); it++) {
		if (toLower(*it) == toLower(toDelete)) {
			this->_invites.erase(it);
			return ;
		}
	}
}

void	Client::deleteChannel(std::string toDelete) {
	for (std::vector<std::string>::iterator it = this->_channelNames.begin(); it != this->_channelNames.end(); it++) {
		if (toLower(*it) == toLower(toDelete)) {
			this->_channelNames.erase(it);
			return ;
		}
	}
}

void	Client::clearInvites() {
	this->_invites.clear();
}

void	Client::trimmReplyBuffer(size_t bytes) {
	this->_replyBuffer.erase(0, bytes);
}


void	Client::addChannel(std::string channelName) {

	for (std::vector<std::string>::iterator it = this->_channelNames.begin(); it != this->_channelNames.end(); it++) {
		if (toLower(*it) == toLower(channelName)) {
			return ;
		}
	}

	this->_channelNames.push_back(channelName);
}

bool	Client::isInvitedToChannel(std::string channelName) {

	for (std::vector<std::string>::iterator it = this->_invites.begin(); it != this->_invites.end(); it++) {
		if (toLower(*it) == toLower(channelName)) {
			return (true);
		}
	}

	return (false);
}

std::string	toLower(std::string str) {

	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = std::tolower(str[i]);
		}
	}

	return (str);
}
