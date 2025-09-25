# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:01:47 by akurochk          #+#    #+#              #
#    Updated: 2025/05/30 17:23:09 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:bullseye

# install wget (downloading), php-fpm (php beckend), php-mysql (db connection)
RUN			apt update && apt upgrade -y --no-install-recommends --no-install-suggests
RUN			apt install -y \
				wget \
				php7.4-fpm \
				php7.4-mysql
				
# clear temp files
RUN			apt clean
RUN			rm -rf /var/lib/apt/lists/*

# make dirs
RUN			mkdir -p /var/www/html
RUN			mkdir -p /run/php/

# set rights
RUN			chown -R www-data:www-data /var/www/html

# copy files
COPY		./tools/*.sh /usr/local/bin/
RUN			chmod +x /usr/local/bin/*.sh

# default run cmd
ENTRYPOINT	[ "/usr/local/bin/script.sh" ]
