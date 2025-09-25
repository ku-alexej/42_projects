# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:53:35 by akurochk          #+#    #+#              #
#    Updated: 2023/12/19 16:53:02 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

LIBFT		=	libft/
GNL			=	get_next_line/
MLX			=	libmlx/

LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
GNL_A		=	$(addprefix $(GNL), libgnl.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

LIBFT_FLAGS	=	-L$(LIBFT) -lft
GNL_FLAGS	=	-L$(GNL) -lgnl
MLX_FLAGS	=	-L$(MLX) -lmlx -lX11 -lXext -lm -lz

CC			=	cc
INCLUDE 	=	-I inc -I $(LIBFT) -I $(GNL) -I $(MLX)
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCS		=	srcs/draw.c \
				srcs/draw_line.c \
				srcs/fdf.c \
				srcs/ft_atoi_hex.c \
				srcs/hook_close.c \
				srcs/instructions.c \
				srcs/key.c \
				srcs/map_utils.c \
				srcs/math_utils.c \
				srcs/parse_map.c \
				srcs/projection.c \
				srcs/rotation.c \
				srcs/utils.c

OBJS		=	$(SRCS:%.c=%.o)

$(NAME):		$(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
				$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT_FLAGS) $(GNL_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_A):
				make -s -C $(LIBFT)

$(GNL_A):
				make -s -C $(GNL)

$(MLX_A):
				make -s -C $(MLX)

.c.o:
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all:			$(NAME)

clean:			
				$(RM) $(OBJS)
				make clean -s -C $(LIBFT)
				make clean -s -C $(GNL)
				make clean -s -C $(MLX)

fclean:			
				$(RM) $(OBJS)
				make fclean -s -C $(LIBFT)
				make fclean -s -C $(GNL)
				make clean -s -C $(MLX)
				$(RM) $(NAME)

re:				fclean all

bonus:			all

.PHONY:			all clean fclean re bonus
