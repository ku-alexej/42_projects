# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 15:57:09 by akurochk          #+#    #+#              #
#    Updated: 2023/05/16 13:52:10 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c ft_memchr.c  ft_memset.c ft_strlen.c ft_tolower.c ft_strrchr.c \
			ft_atoi.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strncmp.c ft_toupper.c  \
			ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strlcat.c ft_strnstr.c ft_isalnum.c \
			ft_isprint.c ft_memmove.c ft_strlcpy.c ft_calloc.c ft_strdup.c ft_itoa.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c

BONUS		= ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c \
			ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c

NAME		= libft.a

OBJS		= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUS:.c=.o}

FLAG		= -Wall -Wextra -Werror

.c.o:
		gcc ${FLAG} -g -I . -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

all: ${NAME}

clean:
		rm -f ${OBJS} ${BONUSOBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

bonus: ${OBJS} ${BONUSOBJS}
		ar rc ${NAME} ${OBJS} ${BONUSOBJS}
		ranlib ${NAME}

so:
		gcc -nostartfiles -fPIC ${FLAG} ${SRCS} ${BONUS}
		gcc -nostartfiles -shared -o libft.so ${OBJS} ${BONUSOBJS}

.PHONY: all clear fclear re bonus
