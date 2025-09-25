# Minitalk – Client/Server Communication with Signals
A lightweight messaging program built in C, where a client and server communicate exclusively using UNIX signals (SIGUSR1 and SIGUSR2).

# Features (Mandatory):
- Server prints its PID on startup
- Client sends a string to the server using only signals
- Server prints received messages instantly (no noticeable delay)
- Server can handle multiple clients without restarting
- No external communication methods (only signals allowed)

# Bonus Features:
- Server acknowledges each received message with a signal back to the client
- Support for Unicode characters

Run (example):
`./server`
`./client <server_pid> "Hello, world!"`
