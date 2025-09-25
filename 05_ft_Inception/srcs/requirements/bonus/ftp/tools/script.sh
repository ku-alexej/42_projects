#!/bin/bash

echo "[1/3] FTP script"
echo "      Create user..."
useradd -m -s /bin/bash "$FTP_USER"
echo "$FTP_USER:$FTP_PASSWORD" | chpasswd
echo "      User created"

echo "[2/3] FTP script"
echo "      Create directories..."
mkdir -p /ftp/wordpress
mkdir -p /var/run/vsftpd/empty
chown $FTP_USER_NAME:$FTP_USER_NAME /ftp/wordpress
chmod 777 /ftp/wordpress
chmod 755 /var/run/vsftpd/empty
echo "      Directories created"

echo "[3/3] FTP script"
echo "      Running ftp..."
exec vsftpd /etc/ftp.conf
