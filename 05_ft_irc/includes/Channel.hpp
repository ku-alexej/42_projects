/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:28:07 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 19:42:22 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>
# include <vector>
# include <sstream>
# include "Client.hpp"

class Channel {
	public:
		// --- constructors ---
		Channel();
		Channel(const Channel &src);
		Channel(std::string name, Client *client, bool firstConnection);

		// --- operators ---
		Channel &operator=(const Channel &src);

		// --- destructors ---
		~Channel();

		// --- getters ---
		int						getL();
		bool					getI();
		bool					getT();
		std::string				getK();
		std::string				getTopicText();
		std::vector<Client *>	getClients();
		std::vector<Client *>	getOperators();
		Client					*getClientByFd(int fd);
		Client					*getOperatorByFd(int fd);
		std::string 			getName();

		// --- setters ---
		void	setL(int newL);
		void	setI(bool isI);
		void	setT(bool isT);
		void	setK(std::string newK);
		void	setTopicText(std::string newTopicText);
		void	setName(std::string newName);

		// --- member functions ---
		void	addClient(Client *newClient);
		void	deleteClient(Client *toDelete);
		void	clearClients();
		void	addOperator(Client *newOperator);
		void	deleteOperator(Client *toDelete);
		void	clearOperators();
		void	setReplyBufferForAllChannelClients(std::string msg);
		void	setReplyBufferForAllChannelClientsExeptFd(std::string msg, int fd);
		std::string	getModes();
		std::string	getModesArgs(bool isOnChannel);

	private:
		int						_l;
		bool					_i;
		bool					_t;
		std::string				_k;
		std::string 			_name;
		std::string				_tText;
		std::vector<Client *>	_clients;
		std::vector<Client *>	_operators;
};

bool isValidChannelName(const std::string &channel);

#endif
