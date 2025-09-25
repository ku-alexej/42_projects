#!/bin/bash

echo "[1/2] DB script"

if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then 
    echo "      Init db..."

    echo "      Create init query..."
    cat << EOF > /tmp/init.sql
USE mysql;
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\` CHARACTER SET utf8 COLLATE utf8_general_ci;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_USER_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

    echo "      Run MariaDB in bootstrap mode to execute init..."
    mysqld --user=mysql --bootstrap < /tmp/init.sql
    rm -f /tmp/init.sql
fi
echo "      MariaDB initialized"

echo "[2/2] DB script"
echo "      Running mysqld..."
exec mysqld --user=mysql
