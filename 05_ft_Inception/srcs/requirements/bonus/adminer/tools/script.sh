#!/bin/bash

echo "[1/2] adminer script"
cd
mkdir -p /var/www/html
echo "      Installing adminer..."
wget "http://www.adminer.org/latest.php" -O /var/www/html/index.php
echo "      Adminer was installed..."
cd /var/www/html

echo "[2/2] adminer script"
echo "      Running adminer..."
php -S 0.0.0.0:80
