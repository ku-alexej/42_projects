# ft_irc – Internet Relay Chat Server

A custom IRC server built in C++98, following the official IRC protocol.
It allows multiple clients to connect via TCP/IP, authenticate, set nicknames, join channels, and exchange messages in real time.

# Features:

- Multi-client handling with non-blocking I/O and poll()
- User authentication (nickname & username)
- Private messaging and public channel communication
- Channel operators with commands: KICK, INVITE, TOPIC, MODE
- Basic channel modes: invite-only, topic restrictions, password, operators, user limits

Run:
`./ircserv <port> <password>`