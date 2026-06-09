# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 17:45:37 by akurochk          #+#    #+#              #
#    Updated: 2025/05/30 17:22:33 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		debian:bullseye

# install nginx + openssl
RUN			apt update && apt upgrade -y --no-install-recommends --no-install-suggests
RUN			apt install -y \
				nginx \
				openssl
				
# clear temp files
RUN			apt clean
RUN			rm -rf /var/lib/apt/lists/*

# make dirs and set rights			
RUN			mkdir -p /etc/nginx/ssl
RUN			mkdir -p /var/run/nginx
RUN			mkdir -p /var/www/html
RUN			chmod -R 755 /var/www/html
RUN			chown -R www-data:www-data /var/www/html

# create certificates
RUN			openssl req \
				-x509 \
				-nodes \
				-out /etc/nginx/ssl/inception.crt \
				-keyout /etc/nginx/ssl/inception.key \
				-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=akurochk.42.fr/UID=akurochk"

# copy files
COPY		conf/nginx.conf /etc/nginx/conf.d/

CMD			[ "nginx", "-g", "daemon off;" ]
