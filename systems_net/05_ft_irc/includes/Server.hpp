/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:28:12 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 18:41:51 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <csignal>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <map>
# include <list>
# include <netinet/in.h>
# include <poll.h>
# include <fcntl.h>
# include <arpa/inet.h>
# include <sstream>
# include <algorithm>
# include <unistd.h>
# include <cctype>

# include "Client.hpp"
# include "Channel.hpp"
# include "Colors.hpp"
# include "Replyes.hpp"

class Server {
	public:
		Server();
		Server(const Server &src);
		Server(int port, std::string password, std::string serverName);
		Server &operator=(const Server &src);
		~Server();

		void	connectNewClient();
		void	disconnectClient(int fd, std::string reason);
		void	handleNewInput(int fd);
		void	sentReply(int fd);

		std::vector<std::string>	parsCommands(Client *c);
		std::vector<std::string>	splitIrssiCommandinToken(std::string cmd);

		void	initCmdMap();
		void	exec(std::string cmd, int fd);
		void	cmdCap(std::vector<std::string> tokens, int fd);
		void	cmdPass(std::vector<std::string> tokens, int fd);
		void	cmdNick(std::vector<std::string> tokens, int fd);
		void	cmdUser(std::vector<std::string> tokens, int fd);
		void	cmdPing(std::vector<std::string> tokens, int fd);
		void	cmdWhois(std::vector<std::string> tokens, int fd);

		//		functions JOIN
		void	cmdJoin(std::vector<std::string> tokens, int fd);
		void		createChannel(Client *c, std::string channelName);
		void		joinChannel(Client *c, Channel *ch, std::string key);
		void		welcomeChannelReply(Client *c, Channel *ch);
		void		clientJoinChannelReply(Client *c, Channel *ch);

		void	cmdPart(std::vector<std::string> tokens, int fd);
		void	cmdTopic(std::vector<std::string> tokens, int fd);
		void	cmdInvite(std::vector<std::string> tokens, int fd);
		void	cmdKick(std::vector<std::string> tokens, int fd);

		//		functions PRIVMSG
		void 	cmdPrivmsg(std::vector<std::string> tokens, int fd);
		void		sendPrivateMsgToChannel(std::string channelName, std::string message, int fd);
		void		sendPrivateMsgToClient(std::string nickName, std::string message, int fd);
		
		//		functions MODE
		void	cmdMode(std::vector<std::string> tokens, int fd);
		void		cmdUserMode(std::vector<std::string> tokens, int fd);
		void		cmdChannelMode(std::vector<std::string> tokens, int fd);
		void		runModes(std::vector<std::string> tokens, int fd);
		void		setMode(std::vector<std::string> tokens, int fd, std::string mode, std::string variable);
		void		setModeT(std::vector<std::string> tokens, int fd, std::string mode, std::string variable);
		void		setModeI(std::vector<std::string> tokens, int fd, std::string mode, std::string variable);
		void		setModeL(std::vector<std::string> tokens, int fd, std::string mode, std::string variable);
		void		setModeK(std::vector<std::string> tokens, int fd, std::string mode, std::string variable);
		void		setModeO(std::vector<std::string> tokens, int fd, std::string mode, std::string variable);
		
		void	cmdQuit(std::vector<std::string> tokens, int fd);
		void	cmdWho(std::vector<std::string> tokens, int fd);

		Channel* 	getChannel(std::string chanName);
		void		addChannel(Channel *newChannel, std::string name);
		Client		*getClientByFd(int fd);
		Client		*getClientByNick(std::string nick);
		void		deleteChannel(std::string toDelete);
		void		deleteEmptyChannel(Channel *ch);
		void		deleteClient(Client toDelete);
		void		deleteFromFds(int fdsIndex);
		void		startListening();
		void		turnOn();
		void		turnOff();
		static void	signalHandler(int signum);

		//		functions for debug
		void	printStringVector(std::vector<std::string> v);
		void	printBuffer(std::string str);
		void	printClientBuffer(Client client);
		void	printServer();

	private:
		int							_fd;
		int							_port;
		static bool					_stayTurnedOn;
		std::string					_password;
		std::string					_serverName;
		struct sockaddr_in			_serverAddress;
		struct pollfd				_clientIn;
		std::list<Client>			_clients;
		std::list<Channel>			_channels;
		std::vector<struct pollfd>	_fds;
		std::map<std::string, void (Server::*)(std::vector<std::string>, int)> _cmdMap;
};

std::vector<std::string>	split(const std::string str, char delimiter);

#endif
