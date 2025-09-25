# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 16:48:14 by akurochk          #+#    #+#              #
#    Updated: 2023/12/19 13:14:35 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libgnl.a

CC		=	cc
INCLUDE	=	-I .
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

SRCS	=	get_next_line.c \
			get_next_line_utils.c

OBJS	=	$(SRCS:%.c=%.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
