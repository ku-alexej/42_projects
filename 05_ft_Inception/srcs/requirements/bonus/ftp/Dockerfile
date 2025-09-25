# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:01:57 by akurochk          #+#    #+#              #
#    Updated: 2025/06/27 15:10:03 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		debian:bullseye

# install vsftpd
RUN			apt update && apt upgrade -y --no-install-recommends --no-install-suggests
RUN			apt install -y vsftpd

# clear temp files
RUN			apt clean 
RUN			rm -rf /var/lib/apt/lists/*

# copy files
COPY		conf/ftp.conf /etc/ftp.conf
COPY        tools/*.sh /usr/local/bin/
RUN			chmod +x /usr/local/bin/*.sh

# default run cmd
ENTRYPOINT  [ "/usr/local/bin/script.sh" ]
