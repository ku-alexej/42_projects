# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 12:49:31 by akurochk          #+#    #+#              #
#    Updated: 2023/11/30 13:25:08 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= push_swap_do_op.c \
			push_swap_libft.c \
			push_swap_main.c \
			push_swap_parse_utils.c \
			push_swap_parse.c \
			push_swap_split.c \
			push_swap_stack.c \
			push_swap_third_sort.c \
			push_swap_utils.c

SRCS_B		= checker_do_op_bonus.c \
			checker_libft_bonus.c \
			checker_main_bonus.c \
			checker_parse_bonus.c \
			checker_parse_utils_bonus.c \
			checker_split_bonus.c \
			checker_stack_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c
		
OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

NAME		= push_swap
NAME_B		= checker

CC 			= gcc
FLAGS		= -Wall -Wextra -Werror -I.

all: $(NAME)

%.o:%.c
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

bonus: $(OBJS_B)
		$(CC) $(FLAGS) -o $(NAME_B) $(OBJS_B)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

clean_b:
		rm -f $(OBJS_B)

fclean_b: clean_b
		rm -f $(NAME_B)

re: fclean all

re_b: fclean_b bonus

.PHONY: all bonus clean fclean clean_b fclean_b re re_b
