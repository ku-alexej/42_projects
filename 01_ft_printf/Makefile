# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 14:42:29 by akurochk          #+#    #+#              #
#    Updated: 2023/06/13 10:44:50 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
	ft_parse_format.c \
	ft_print_c.c \
	ft_print_s.c \
	ft_print_p.c \
	ft_print_d.c \
	ft_print_u.c \
	ft_print_x_lower.c \
	ft_print_x_upper.c \
	ft_print_percent.c \
	ft_utils_put.c \
	ft_utils_count.c
	
NAME	= libftprintf.a

OBJS	= ${SRCS:.c=.o}

FLAG	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a

.c.o:
	gcc ${FLAG} -g -I . -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBFT}
	cp libft/libft.a ${NAME}
	ar -rcs ${NAME} ${OBJS}

$(LIBFT):
	make -C ./libft

	
all: ${NAME}

clean:
	rm -f ${OBJS}
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f ${NAME}

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
