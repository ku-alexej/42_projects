# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:01:57 by akurochk          #+#    #+#              #
#    Updated: 2025/06/27 15:10:22 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:bullseye

# install redis
RUN		apt update && apt upgrade -y --no-install-recommends --no-install-suggests
RUN		apt install -y redis-server

# clear temp files
RUN		apt clean
RUN		rm -rf /var/lib/apt/lists/*

# set config
RUN		echo "maxmemory 256mb" >> /etc/redis/redis.conf
RUN		echo "maxmemory-policy allkeys-lru" >> /etc/redis/redis.conf

# default run cmd
CMD		["redis-server",  "--protected-mode", "no"]
