# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 18:01:47 by akurochk          #+#    #+#              #
#    Updated: 2025/06/27 16:10:21 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:bullseye

# install curl (for link)
RUN		apt update && apt upgrade -y --no-install-recommends --no-install-suggests
RUN		apt install -y \
            curl

# clear temp files
RUN		apt clean
RUN		rm -rf /var/lib/apt/lists/*

# get official script
RUN		curl -L https://my-netdata.io/kickstart-static64.sh -o /usr/local/bin/kickstart.sh

# run to only for installation of
RUN		bash /usr/local/bin/kickstart.sh --dont-wait --dont-start-it

# default run cmd
CMD ["/usr/sbin/netdata", "-D"]
