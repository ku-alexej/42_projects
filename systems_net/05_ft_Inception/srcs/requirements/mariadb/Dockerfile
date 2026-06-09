# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:01:57 by akurochk          #+#    #+#              #
#    Updated: 2025/05/30 17:22:09 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		debian:bullseye

# install mariadb
RUN			apt update && apt upgrade -y --no-install-recommends --no-install-suggests
RUN			apt install -y mariadb-server

# clear temp files
RUN			apt clean 
RUN			rm -rf /var/lib/apt/lists/*

# copy files
COPY		conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY		tools/*.sh /usr/local/bin/
RUN			chmod +x /usr/local/bin/*.sh

RUN         mkdir -p /var/lib/mysql /var/run/mysqld
RUN         chown -R mysql:mysql /var/lib/mysql /var/run/mysqld
RUN         chmod 750 /var/lib/mysql /var/run/mysqld

# init db
RUN         mariadb-install-db --user=mysql --datadir=/var/lib/mysql --basedir=/usr

# default run cmd
ENTRYPOINT  [ "/usr/local/bin/script.sh" ]
