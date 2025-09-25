/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:28:08 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:30 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
# include <vector>
# include <iostream>	
# include <algorithm> 
# include "Colors.hpp"

class Client {
	public:
		// --- constructors ---
		Client();
		Client(const Client &src);
		Client(int fd, std::string username, std::string nickname);

		// --- operators ---
		Client &operator=(const Client &src);

		// --- destructors ---
		~Client();

		// --- getters ---
		int							getFd();
		bool						getCapOn();
		bool						getOnline();
		bool						getOperator();
		bool						getPassOk();
		bool						getRegistred();
		std::string					getReplyBuffer();
		std::string					getBuffer();
		std::string					getIp();
		std::string					getUsername();
		std::string					getHostname();
		std::string					getRealname();
		std::string					getNickname();
		std::vector<std::string>	getInvites();
		std::vector<std::string>	getChannelNames();
		std::string 				getUserID();

		// --- setters ---
		void	setFd(int newFd);
		void	setCapOn(bool isCapOn);
		void	setOnline(bool isOnline);
		void	setOperator(bool isOperator);
		void	setPassOk(bool isPassOk);
		void	setRegistred(bool isRegistred);
		void	setReplyBuffer(std::string newReply);
		void	setBuffer(std::string newBuffer);
		void	setIp(std::string newIp);
		void	setUsername(std::string newUsername);
		void	setHostname(std::string newHostname);
		void	setRealname(std::string newRealname);
		void	setNickname(std::string newNickname);
		void    addChannel(std::string channel);
		// --- member functions ---
		void	clearReplyBuffer();
		void	clearBuffer();
		void	addInvite(std::string newInvite);
		void 	deleteChannel(std::string channelName);
		void	deleteInvite(std::string toDelete);
		void	clearInvites();
		void	trimmReplyBuffer(size_t bytes);
		bool	isInvitedToChannel(std::string channelName);

	private:
		int							_fd;
		bool						_capOn;
		bool						_online;
		bool						_operator;
		bool						_passOk;
		bool						_registred;
		std::string					_replyBuffer;
		std::string					_buffer;
		std::string					_ip;
		std::string					_username;
		std::string					_hostname;
		std::string					_realname;
		std::string					_nickname;
		std::vector<std::string>	_invites;
		std::vector<std::string> 	_channelNames;
};

std::string	toLower(std::string str);

#endif
