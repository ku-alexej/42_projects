# ft_irc

ft_irc is a custom IRC server written in C++98 for the 42 curriculum.
It implements a multi-client TCP server with non-blocking I/O and `poll()`,
supports IRC registration, channels, private messages, and a basic operator
toolset.

## Features

- Multiple clients handled in a single process with `poll()`
- IRC registration with `PASS`, `NICK`, and `USER`
- Channel management with `JOIN`, `PART`, `WHO`, and `WHOIS`
- Messaging with `PRIVMSG`
- Operator commands: `KICK`, `INVITE`, `TOPIC`, and `MODE`
- Basic channel modes: invite-only, topic lock, password, operators, and user limits
- Compatible with the `irssi` client

## Requirements

- C++98 compiler
- `make`
- A valid port in the range `1024` to `65535`
- A non-empty server password

## Build

From the project directory:

```bash
make
```

Useful targets:

```bash
make clean
make fclean
make re
```

## Run

```bash
./ircserv <port> <password>
```

Example:

```bash
./ircserv 6667 mypassword
```

## Connect with irssi

Start `irssi`, then connect with the same password used to launch the server:

```text
/connect 127.0.0.1 6667 mypassword
```

If you want to register manually, the usual order is:

```text
/quote PASS mypassword
/nick your_nick
/user your_user 0 * :Your Name
```

After registration, you can join channels and chat normally:

```text
/join #42
/msg someuser hello
/topic #42 new topic
```

## Supported Commands

The server handles the following IRC commands:

- `CAP`
- `PASS`
- `NICK`
- `USER`
- `PING`
- `WHOIS`
- `JOIN`
- `PART`
- `TOPIC`
- `INVITE`
- `KICK`
- `MODE`
- `QUIT`
- `WHO`
- `PRIVMSG`

## Notes

- The server only starts when the port and password arguments are valid.
- A client is fully registered only after the required authentication fields are provided.
- Channel operator permissions are enforced for the commands that modify a channel.