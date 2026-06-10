# **42 Paris Projects**

Core curriculum and RNCP Level 7 projects completed at 42 Paris.  
This repository contains systems programming, networking, full-stack, and security projects developed during the program.

# **RNCP-7 projects**

### 🔐 Security & Cybersecurity
- **[arachnida](https://github.com/42-mates/arachnida)**  
Two CLI tools built around web scraping and file metadata inspection. **Spider** crawls a target URL and downloads all images it finds, with optional recursive crawling across same-domain links up to a configurable depth. **Scorpion** reads image files and displays their embedded metadata — filesystem info, image properties, and raw EXIF tags. Written in Python, the project covers HTTP request handling, HTML parsing and recursive web crawling strategies.
- **[override](https://github.com/42-mates/override)** *(teamwork with [@oprosvir](https://github.com/oprosvir))*  
This project is a part of the cybersecurity curriculum at 42 School. The goal is to dive deep into binary exploitation, reverse engineering, and system security by solving a series of increasingly difficult Capture The Flag (CTF) challenges. Each level introduces core security concepts and exploitation techniques, progressing from simple vulnerability identification to complex attack chains. The objective is to discover a vulnerability, exploit it to gain the privileges of the next user, and read the flag/password to proceed to the next level.
- **[rainfall](https://github.com/42-mates/rainfall)** *(teamwork with [@oprosvir](https://github.com/oprosvir))*  
A series of privilege escalation challenges. Each level provides a SUID binary owned by the next user — the goal is to exploit it and read the password from /home/user/<next_level>/.pass. All binaries are 32-bit ELF (x86, little-endian), compiled without modern protections (no stack canary, no NX, no PIE, no RELRO). Most exploits target the stack or heap.
- **[snow-crash](https://github.com/42-mates/snow-crash)** *(teamwork with [@oprosvir](https://github.com/oprosvir))*  
Snow Crash is a project focused on discovering various cyber security vulnerabilities. Each level presents a unique challenge requiring different exploitation techniques.
- **[darkly](https://github.com/42-mates/darkly)** *(teamwork with [@oprosvir](https://github.com/oprosvir))*  
This project is an introduction to cyber security in the field of the world wide web. It involves auditing a vulnerable website to find and exploit security breaches, understanding the risks, and learning how to fix them.

# **Core curriculum projects**

## 🌐 Full-Stack & Web
- **[ft_transcendence](https://github.com/kaierhyeh/ft_transcendence)** *(teamwork with [@s-t-e-v](https://github.com/s-t-e-v) [@ma-pierre](https://github.com/ma-pierre) [@kbaridon](https://github.com/kbaridon) [@kaierhyeh](https://github.com/kaierhyeh))*  
A fullstack team project: develop a web game Pong including the following features:
  - Basic user management systems for users to register, 2FA validate id, customize user settings.
  - Live chat with other users and play games remotely with Websocket.
  - Different game modes: PVE, local/remote PVP and tournament.
  - Single Page Application (SPA) for better UX.
  - Automated health test at launch time.

## 🧠 Systems & Networking
- **[ft_irc](https://github.com/ku-alexej/42_projects/tree/main/systems_net/05_ft_irc)** *(teamwork with [@vecherinca](https://github.com/vecherinca))*  
A custom IRC server built in C++98, following the official IRC protocol. It allows multiple clients to connect via TCP/IP, authenticate, set nicknames, join channels, and exchange messages in real time.
- **[Inception](https://github.com/ku-alexej/42_projects/tree/main/systems_net/05_ft_Inception)**  
A system administration project focused on containerization with Docker Compose. The goal is to build and configure a complete infrastructure inside a virtual machine by writing your own Dockerfiles.
- **[Born2beroot](https://github.com/ku-alexej/42_projects/tree/main/systems_net/01_Born2beroot)**  
Born2beRoot is a system administration project designed to teach virtualization, server setup, and Linux security. You will create your first virtual machine (VM) in VirtualBox or UTM and configure it according to strict rules.
- **[NetPractice](https://github.com/ku-alexej/42_projects/tree/main/systems_net/04_NetPractice)**  
An interactive project to learn and practice fundamental networking concepts through simulated exercises in a browser-based interface.

## 🎮 Graphics & Game Dev
- **[cub3d](https://github.com/42mates/cub3D)** *(teamwork with [@marinsucks](https://github.com/marinsucks))*  
"Cub3D" is a 3D game developed in C using the MiniLibX graphics library, which emulates 3D textures using the raycasting technique.
- **[FdF](https://github.com/ku-alexej/42_projects/tree/main/graphics/02_FdF)**  
A C project focused on rendering a wireframe model of a 3D landscape. Using the MiniLibX library, the program reads a .fdf file containing points in space and visualizes the corresponding 3D terrain in isometric projection.

## ⚙️ C Fundamentals
- **[minishell](https://github.com/42mates/minishell)** *(teamwork with [@marinsucks](https://github.com/marinsucks))*  
Minishell is a simplified version of a shell, implementing some of the basic functionalities of the Bash POSIX shell. It supports executing commands, handling environment variables, basic and managing processes.
- **[Philosophers](https://github.com/ku-alexej/42_projects/tree/main/fundamentals/03_Philosophers/philo)**  
A concurrency project that explores multithreading, synchronization, and resource sharing through the classic dining philosophers problem.
- **[minitalk](https://github.com/ku-alexej/42_projects/tree/main/fundamentals/02_minitalk)**  
A lightweight messaging program built in C, where a client and server communicate exclusively using UNIX signals (SIGUSR1 and SIGUSR2).
- **[push_swap](https://github.com/ku-alexej/42_projects/tree/main/fundamentals/02_push_swap)**  
A C program designed to sort integers using two stacks and a limited set of operations, aiming for the minimal number of instructions. This project emphasizes algorithmic thinking, optimization, and understanding the complexity of sorting.
- **[ft_printf](https://github.com/ku-alexej/42_projects/tree/main/fundamentals/01_ft_printf)**  
A C project that involves recreating the functionality of the standard printf() function. This project focuses on handling variadic functions, proper formatting, and argument parsing, providing a deeper understanding of C internals and formatted output.
- **[get_next_line](https://github.com/ku-alexej/42_projects/tree/main/fundamentals/01_get_next_line)**  
A C project focused on creating a function get_next_line() that reads a line from a file descriptor. This project teaches static variables, memory management, and efficient I/O handling.
- **[libft](https://github.com/ku-alexej/42_projects/tree/main/fundamentals/00_Libft)**  
Libft is a project where you reimplement standard C library functions and create your own general-purpose library. This foundational project helps you understand how common C functions work and prepares you for future assignments.

## 🧱 C++ Modules
- **[CPP modules](https://github.com/ku-alexej/42_projects/tree/main/CPP_modules)**  
A series of projects designed to progressively introduce and strengthen key C++ concepts. Each module focuses on a specific topic, combining theory with practical exercises to build a solid foundation in modern C++ programming.