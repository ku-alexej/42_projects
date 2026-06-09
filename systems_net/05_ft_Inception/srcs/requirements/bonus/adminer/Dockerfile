# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:01:57 by akurochk          #+#    #+#              #
#    Updated: 2025/06/27 15:09:27 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		debian:bullseye

# install php-mysql + php + wget
RUN			apt update && apt upgrade -y --no-install-recommends --no-install-suggests
RUN			apt install -y \
                php-mysql \
                php \
                wget

# clear temp files
RUN			apt clean 
RUN			rm -rf /var/lib/apt/lists/*

# copy files
COPY		tools/*.sh /usr/local/bin/
RUN			chmod +x /usr/local/bin/*.sh

# default run cmd
ENTRYPOINT  [ "/usr/local/bin/script.sh" ]
