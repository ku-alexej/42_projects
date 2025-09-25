# Born2beRoot – Intro to System Administration and Virtualization
Born2beRoot is a system administration project designed to teach virtualization, server setup, and Linux security. You will create your first virtual machine (VM) in VirtualBox or UTM and configure it according to strict rules.

# Key Objectives (Mandatory):
- Set up a VM using Debian (recommended) or Rocky Linux
- No graphical interface (X.org forbidden)
- Create at least 2 encrypted LVM partitions
- Run SSH on port 4242 with root login disabled
- Configure firewall (UFW for Debian, firewalld for Rocky)
- Implement a strong password policy (length, complexity, expiration, warnings)
- Configure sudo with logging, TTY enforcement, limited retries, and a custom error message
- Create a monitoring script (monitoring.sh) to display:
  - OS architecture & kernel
  - CPU info (physical and virtual)
  - RAM and disk usage with utilization percentages
  - CPU load
  - Last reboot time
  - LVM status
  - Active connections and logged-in users
  - Network info (IP & MAC)
  - Number of commands executed with sudo
- Script must run at startup and display info every 10 minutes

# Bonus Features:
- Advanced partitioning
- Set up a functional WordPress website with lighttpd, MariaDB, PHP
- Deploy an additional service of your choice (excluding Apache/Nginx)

# Learning Outcomes:
- Linux server setup
- Security hardening (password policy, sudo restrictions, firewall)
- Bash scripting for monitoring and automation
- Virtual machine management and best practices
