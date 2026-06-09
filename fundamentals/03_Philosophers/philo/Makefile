# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 15:00:02 by akurochk          #+#    #+#              #
#    Updated: 2024/04/02 16:06:56 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= main.c \
		arg_check.c \
		init_data.c \
		monitor.c \
		routine.c \
		threads.c \
		time.c \
		utils.c	

OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re