/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replyes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:28:11 by akurochk          #+#    #+#             */
/*   Updated: 2025/02/12 19:33:30 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLYES_HPP
# define REPLYES_HPP

# define CRLF			"\r\n"
# define CMD_LEN		512
# define SERVER_NAME	"ft_irc"

// client = nickname of user

# define MODE_SET(client, userName, hostName, channelName, mode, variable)	std::string(":") + (client.empty() ? "*" : client) + "!" + userName + "@" + hostName + " MODE " + channelName + " " + mode + " " + variable + ""
# define JOIN_OK(client, userName, hostName, channelName)					std::string(":") + (client.empty() ? "*" : client) + "!" + userName + "@" + hostName + " JOIN " + channelName + ""
# define QUIT_CHANNEL(client, userName, hostName, channelName, msg)			std::string(":") + (client.empty() ? "*" : client) + "!" + userName + "@" + hostName + " QUIT " + channelName + " :" + msg + ""
# define QUIT_SERVER(msg)													std::string(":") + SERVER_NAME + " ERROR :" + msg + ""
# define TOPIC(client, userName, hostName, channelName, topic)				std::string(":") + (client.empty() ? "*" : client) + "!" + userName + "@" + hostName + " TOPIC " + channelName + " :" + topic + ""
# define INVITE(client, userName, hostName, targetName, channelName)		std::string(":") + (client.empty() ? "*" : client) + "!" + userName + "@" + hostName + " INVITE " + targetName + " " + channelName + ""
# define KICK(client, userName, hostName, channelName,targetName, msg)		std::string(":") + (client.empty() ? "*" : client) + "!" + userName + "@" + hostName + " KICK " + channelName + " " + targetName + " :" + msg + ""
# define PRIVMSG(client, userName, hostName, nickOrChannel, msg)			std::string(":") + (client.empty() ? "*" : client) + "!" + userName + "@" + hostName + " PRIVMSG " + nickOrChannel + " :" + msg + ""

// --- errors ---
# define ERR_NOSUCHNICK(client, nickOrChannel)							std::string(":") + SERVER_NAME + " 401 " + (client.empty() ? "*" : client) + " " + nickOrChannel + " :No such nick/channel"
# define ERR_NOSUCHSERVER(client, serverName)							std::string(":") + SERVER_NAME + " 402 " + (client.empty() ? "*" : client) + " " + serverName + " :No such server"
# define ERR_NOSUCHCHANNEL(client, channelName)							std::string(":") + SERVER_NAME + " 403 " + (client.empty() ? "*" : client) + " " + channelName + " :No such channel"
# define ERR_NORECIPIENT(client, command)								std::string(":") + SERVER_NAME + " 411 " + (client.empty() ? "*" : client) + " :No recipient given (" + command + ")"
# define ERR_NOTEXTTOSEND(client)										std::string(":") + SERVER_NAME + " 412 " + (client.empty() ? "*" : client) + " :No text to send"
# define ERR_UNKNOWNCOMMAND(client, command)							std::string(":") + SERVER_NAME + " 421 " + (client.empty() ? "*" : client) + " " + command + " :Unknown command"
# define ERR_NONICKNAMEGIVEN(client)									std::string(":") + SERVER_NAME + " 431 " + (client.empty() ? "*" : client) + " :No nickname given"
# define ERR_ERRONEUSNICKNAME(client, nickName)							std::string(":") + SERVER_NAME + " 432 " + (client.empty() ? "*" : client) + " " + nickName + " :Erroneus nickname"
# define ERR_NICKNAMEINUSE(client, nickName)							std::string(":") + SERVER_NAME + " 433 " + (client.empty() ? "*" : client) + " " + nickName + " :Nickname is already in use"
# define ERR_USERNOTINCHANNEL(client, nickName, channelName)			std::string(":") + SERVER_NAME + " 441 " + (client.empty() ? "*" : client) + " " + nickName + " " + channelName + " :They aren't on that channel"
# define ERR_NOTONCHANNEL(client, channelName)							std::string(":") + SERVER_NAME + " 442 " + (client.empty() ? "*" : client) + " " + channelName + " :You're not on that channel"
# define ERR_USERONCHANNEL(client, nickName, channelName)				std::string(":") + SERVER_NAME + " 443 " + (client.empty() ? "*" : client) + " " + nickName + " " + channelName + " :is already on channel"
# define ERR_NOTREGISTERED(client)										std::string(":") + SERVER_NAME + " 451 " + (client.empty() ? "*" : client) + ":You have not registered"
# define ERR_NEEDMOREPARAMS(client, command)							std::string(":") + SERVER_NAME + " 461 " + (client.empty() ? "*" : client) + " " + command + " :Not enough parameters"
# define ERR_ALREADYREGISTERED(client)									std::string(":") + SERVER_NAME + " 462 " + (client.empty() ? "*" : client) + " :You may not reregister"
# define ERR_PASSWDMISMATCH(client)										std::string(":") + SERVER_NAME + " 464 " + (client.empty() ? "*" : client) + " :Password incorrect"
# define ERR_CHANNELISFULL(client, channelName)							std::string(":") + SERVER_NAME + " 471 " + (client.empty() ? "*" : client) + " " + channelName + " :Cannot join channel (+l)"
# define ERR_UNKNOWNMODE(client, modechar)								std::string(":") + SERVER_NAME + " 472 " + (client.empty() ? "*" : client) + " " + modechar + " :is unknown mode char to me"
# define ERR_INVITEONLYCHAN(client, channelName)						std::string(":") + SERVER_NAME + " 473 " + (client.empty() ? "*" : client) + " " + channelName + " :Cannot join channel (+i)"
# define ERR_BADCHANNELKEY(client, channelName)							std::string(":") + SERVER_NAME + " 475 " + (client.empty() ? "*" : client) + " " + channelName + " :Cannot join channel (+k)"
# define ERR_BADCHANMASK(channelName)									std::string(":") + SERVER_NAME + " 476 " + channelName + " :Bad Channel Mask"
# define ERR_CHANOPRIVSNEEDED(client, channelName)						std::string(":") + SERVER_NAME + " 482 " + (client.empty() ? "*" : client) + " " + channelName + " :You're not channel operator"
# define ERR_USERSDONTMATCH(client)										std::string(":") + SERVER_NAME + " 502 " + (client.empty() ? "*" : client) + " :Cant change mode for other users"
# define ERR_UMODEUNKNOWNFLAG(client, flag)								std::string(":") + SERVER_NAME + " 501 " + (client.empty() ? "*" : client) + " :Unknown user MODE flag " + flag + ""
# define ERR_INVALIDMODEPARAM(client, target, mode, param, msg)			std::string(":") + SERVER_NAME + " 696 " + (client.empty() ? "*" : client) + " " + target + " " + mode + " " + param + " :" + msg + ""

// --- replyes ---
# define RPL_WELCOME(client, nickName, userName, hostName)				std::string(":") + SERVER_NAME + " 001 " + (client.empty() ? "*" : client) + " :Welcome to the IRC Network, " + nickName + "!~" + userName + "@" + hostName
# define RPL_ISSUPPORT(client)											std::string(":") + SERVER_NAME + " 005 " + (client.empty() ? "*" : client) + \
																						" CHANMODES=,o,lk,ti" + \
																						" CASEMAPPING=ascii" + \
																						" CHANTYPES=#" + \
																						" PREFIX=(o)@" + \
																						" :are supported by this server"
# define RPL_UMODEIS(client, userModes)									std::string(":") + SERVER_NAME + " 221 " + (client.empty() ? "*" : client) + " " + userModes + ""
# define RPL_WHOISUSER(client, nickName, userName, hostname, realName)	std::string(":") + SERVER_NAME + " 311 " + (client.empty() ? "*" : client) + " " + nickName + " ~" + userName + " " + hostname + " * :" + realName + ""
# define RPL_ENDOFWHO(client, mask)										std::string(":") + SERVER_NAME + " 315 " + (client.empty() ? "*" : client) + " " + mask + " :End of WHO list"
# define RPL_ENDOFWHOIS(client, nickName)								std::string(":") + SERVER_NAME + " 318 " + (client.empty() ? "*" : client) + " " + nickName + " :End of /WHOIS list"
# define RPL_CHANNELMODEIS(client, channelName, modeString, modeArgs)	std::string(":") + SERVER_NAME + " 324 " + (client.empty() ? "*" : client) + " " + channelName + " " + modeString + " " + modeArgs + ""
# define RPL_NOTOPIC(client, channelName)								std::string(":") + SERVER_NAME + " 331 " + (client.empty() ? "*" : client) + " " + channelName + " :No topic is set"
# define RPL_TOPIC(client, channelName, topic)							std::string(":") + SERVER_NAME + " 332 " + (client.empty() ? "*" : client) + " " + channelName + " :" + topic + ""
# define RPL_INVITING(client, nickName, channelName)					std::string(":") + SERVER_NAME + " 341 " + (client.empty() ? "*" : client) + " " + nickName + " " + channelName + ""
# define RPL_NAMREPLY(client, symbol, channelName, nickList)			std::string(":") + SERVER_NAME + " 353 " + (client.empty() ? "*" : client) + " " + symbol + " " + channelName + " :" + nickList + ""
# define RPL_ENDOFNAMES(client, channelName)							std::string(":") + SERVER_NAME + " 366 " + (client.empty() ? "*" : client) + " " + channelName + " :End of /NAMES list"
# define RPL_ENDOFBANLIST(client, channelName)							std::string(":") + SERVER_NAME + " 368 " + (client.empty() ? "*" : client) + " " + channelName + " :End of channel ban list"

#endif