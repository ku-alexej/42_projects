# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 16:43:52 by akurochk          #+#    #+#              #
#    Updated: 2025/07/01 11:15:49 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOCKER_COMPOSE =	docker compose -f srcs/docker-compose.yml

all:	up

up:
		@echo "Building and starting containers..."
		mkdir /home/akurochk/data/mariadb -p
		mkdir /home/akurochk/data/wordpress -p
		$(DOCKER_COMPOSE) up -d --build

down:
		@echo "Stopping containers..."
		$(DOCKER_COMPOSE) down

re:		fclean up

clean:	down
		@echo "Cleaning..."
		docker volume prune -f
		docker image prune -f

fclean: down
		@echo "Full cleaning... "
		docker system prune -a --force --volumes
		sudo chmod 777 /home/akurochk/data/wordpress
		sudo chmod 777 /home/akurochk/data/mariadb
		sudo rm -rf /home/akurochk/data/wordpress/*
		sudo rm -rf /home/akurochk/data/mariadb/*

.PHONY:	all up down re clean fclean
